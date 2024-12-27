import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped, Pose, Twist
from std_msgs.msg import String
from guiding_services.srv import SetGoalPose  # 서비스 메시지 임포트
from action_msgs.srv import CancelGoal
import json
import time


class NavigateToPoseClient(Node):
    def __init__(self):
        super().__init__('navigate_to_pose_client')
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

        self.last_goal_pose = None  # 마지막으로 전송한 목표 인덱스 저장
        self.current_goal_active = False  # 현재 목표가 활성화 상태인지 확인

        # /control_command 구독
        self.subscriber = self.create_subscription(
            String,
            '/control_command',
            self.control_command_callback,
            10
        )

        # cmd_vel publisher 생성
        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.msg = Twist()
        self.msg.linear.x = 0.0  # x 방향 속도 설정
        self.msg.linear.y = 0.0       # y 방향은 0
        self.msg.linear.z = 0.0       # z 방향은 0
        self.msg.angular.x = 0.0      # 회전 x축
        self.msg.angular.y = 0.0      # 회전 y축
        self.msg.angular.z = 0.0      # 회전 z축

        # 서비스 서버 생성
        self.srv = self.create_service(SetGoalPose, 'set_goal_pose', self.handle_set_goal_pose)

        self.get_logger().info('NavigateToPoseClient initialized with service /set_goal_pose')

    def send_goal(self, goal_pose):
        while not self._action_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().error('Action server not available!')

        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = self._get_goal_pose(goal_pose)

        self.last_goal_pose = Pose()
        self.last_goal_pose = goal_pose
        self.current_goal_active = True  # 현재 목표 활성화
        self.get_logger().info(f"Sending goal #{goal_pose} to NavigateToPose action server.")
        self._action_client.send_goal_async(goal_msg).add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('Goal rejected!')
            return

        self.get_logger().info('Goal accepted!')
        goal_handle.get_result_async().add_done_callback(self.result_callback)

    def result_callback(self, future):
        result = future.result().result
        self.current_goal_active = False  # 목표 완료
        if result:
            self.get_logger().info('Goal succeeded!')
            # self.msg.angular.z = 0.5
            # for i in range(11):
            #     self.cmd_vel_publisher.publish(self.msg)
            #     time.sleep(0.8)
        else:
            self.get_logger().error('Goal failed!')

    def _get_goal_pose(self, goal_pose):
        pose = PoseStamped()
        pose.header.frame_id = 'map'
        pose.header.stamp = self.get_clock().now().to_msg()

        pose.pose = goal_pose
        return pose

    def control_command_callback(self, msg):
        command = msg.data.lower()
        if command == 'resume':
            if self.last_goal_pose is None:
                self.get_logger().error("No previous goal to resume.")
            else:
                self.get_logger().info(f"Resuming goal #{self.last_goal_pose}")
                self.send_goal(self.last_goal_pose)
        elif command == 'pause':
            if self.current_goal_active:
                self.get_logger().info("Received 'pause' command, canceling current goal...")
                self.cancel_goal()
            else:
                self.get_logger().warn("No active goal to pause. Sending cancel request to clear any lingering goals.")
                self.cancel_goal()
        else:
            self.get_logger().warn(f"Unknown command received: {command}")

    def cancel_goal(self):
        cancel_goal_service = '/navigate_to_pose/_action/cancel_goal'
        client = self.create_client(CancelGoal, cancel_goal_service)

        if not client.wait_for_service(timeout_sec=5.0):
            self.get_logger().error("CancelGoal service not available.")
            return

        request = CancelGoal.Request()
        request.goal_info.goal_id.uuid = [0] * 16  # 모든 목표를 취소

        self.get_logger().info("Sending cancel request for all active goals...")
        future = client.call_async(request)
        future.add_done_callback(self.cancel_response_callback)

    def cancel_response_callback(self, future):
        try:
            response = future.result()
            self.current_goal_active = False  # 목표 취소 상태 반영
            if response.return_code == CancelGoal.Response.ERROR_NONE:
                self.get_logger().info("Successfully canceled active goals.")
                if self.last_goal_pose is not None:
                    self.get_logger().info(f"Keeping last_goal_pose={self.last_goal_pose} for potential resume.")
            else:
                self.get_logger().error(f"Failed to cancel goals, return code: {response.return_code}")
        except Exception as e:
            self.get_logger().error(f"Error processing cancel response: {e}")

    def handle_set_goal_pose(self, request, response):
        self.get_logger().info(f"Received request : {request}")
        goal_pose = request.goal_pose
        self.send_goal(goal_pose)
        response.success = True
        response.message = f"Goal #{request.goal_pose} sent successfully."
        return response


def main(args=None):
    rclpy.init(args=args)
    node = NavigateToPoseClient()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Keyboard interrupt, shutting down...")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
