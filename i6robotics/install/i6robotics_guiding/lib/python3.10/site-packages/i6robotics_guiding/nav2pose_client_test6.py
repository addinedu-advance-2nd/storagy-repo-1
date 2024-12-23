import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import String
from action_msgs.srv import CancelGoal
import json
import threading


class NavigateToPoseClient(Node):
    def __init__(self):
        super().__init__('navigate_to_pose_client')
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')

        # 기본 `goal_poses`를 JSON 문자열로 선언
        default_goal_poses = json.dumps([
            {'x': -0.169, 'y': 0.25, 'z': 0.0, 'qw': 1.0},
            {'x': -0.16, 'y': -1.12, 'z': 0.0, 'qw': 1.0},
            {'x': 2.24, 'y': -3.23, 'z': 0.0, 'qw': 1.0},
            {'x': 2.01, 'y': -2.23, 'z': 0.0, 'qw': 1.0},
            {'x': 2.95, 'y': -0.61, 'z': 0.0, 'qw': 1.0},
        ])
        self.declare_parameter('goal_poses', default_goal_poses)

        # 매개변수 변경 콜백 설정
        self.add_on_set_parameters_callback(self.on_set_parameters)

        # 현재 goal_poses 값을 파싱
        self.goal_poses = json.loads(self.get_parameter('goal_poses').value)

        self.last_goal_index = None  # 마지막으로 전송한 목표 인덱스 저장
        self.current_goal_active = False  # 현재 목표가 활성화 상태인지 확인

        # /control_command 구독
        self.subscriber = self.create_subscription(
            String,
            '/control_command',
            self.control_command_callback,
            10
        )

        # 사용자 입력 스레드 실행
        self.input_thread = threading.Thread(target=self.handle_user_input, daemon=True)
        self.input_thread.start()

        self.get_logger().info('NavigateToPoseClient initialized')

    def on_set_parameters(self, params):
        for param in params:
            if param.name == 'goal_poses' and param.type_ == rclpy.parameter.Parameter.Type.STRING:
                try:
                    # JSON 문자열을 파싱하여 goal_poses 업데이트
                    self.goal_poses = json.loads(param.value)
                    self.get_logger().info(f"Updated goal_poses: {self.goal_poses}")
                except json.JSONDecodeError:
                    self.get_logger().error("Invalid JSON format for goal_poses")
                    return rclpy.parameter.SetParametersResult(successful=False)
        return rclpy.parameter.SetParametersResult(successful=True)

    def send_goal(self, index):
        if not self._action_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().error('Action server not available!')
            return

        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = self._get_goal_pose(index)

        self.last_goal_index = index  # 마지막 목표 인덱스 저장
        self.current_goal_active = True  # 현재 목표 활성화
        self.get_logger().info(f"Sending goal #{index} to NavigateToPose action server.")
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
        else:
            self.get_logger().error('Goal failed!')

        self.get_logger().info("Waiting for the next input...")
        threading.Thread(target=self.handle_user_input, daemon=True).start()

    def _get_goal_pose(self, index):
        pose = PoseStamped()
        pose.header.frame_id = 'map'
        pose.header.stamp = self.get_clock().now().to_msg()

        goal = self.goal_poses[index - 1]
        pose.pose.position.x = goal['x']
        pose.pose.position.y = goal['y']
        pose.pose.position.z = goal['z']
        pose.pose.orientation.w = goal['qw']

        return pose

    def control_command_callback(self, msg):
        command = msg.data.lower()
        if command == 'resume':
            if self.last_goal_index is None:
                self.get_logger().error("No previous goal to resume.")
                self.get_logger().info("Waiting for the next input...")
                threading.Thread(target=self.handle_user_input, daemon=True).start()
            else:
                self.get_logger().info(f"Resuming goal #{self.last_goal_index}")
                self.send_goal(self.last_goal_index)
        elif command == 'pause':
            if self.current_goal_active:
                self.get_logger().info("Received 'pause' command, canceling current goal...")
                self.cancel_goal()
            else:
                # 목표가 활성화되지 않았더라도, 안전하게 취소 요청 전송
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
                # `pause`로 취소했으므로, 마지막 실행된 목표를 유지
                if self.last_goal_index is not None:
                    self.get_logger().info(f"Keeping last_goal_index={self.last_goal_index} for potential resume.")
            else:
                self.get_logger().error(f"Failed to cancel goals, return code: {response.return_code}")
        except Exception as e:
            self.get_logger().error(f"Error processing cancel response: {e}")


    def handle_user_input(self):
        while rclpy.ok():
            try:
                self.get_logger().info("Choose a goal from 1 to 5 (or type 0 to exit):")
                choice = int(input("Enter your choice: "))

                if choice == 0:
                    self.get_logger().info("Exiting...")
                    rclpy.shutdown()
                    break

                if 1 <= choice <= len(self.goal_poses):
                    self.send_goal(choice)
                    break
                else:
                    self.get_logger().error("Invalid choice. Please choose a valid goal.")
            except ValueError:
                self.get_logger().error("Invalid input. Please enter a number.")


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
