import rclpy as rp
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.action import ActionServer, ActionClient
from nav2_msgs.action import NavigateToPose
from action_msgs.msg import GoalStatus
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
from nav2_simple_commander.robot_navigator import BasicNavigator

from i6robotics_control_msgs.action import NavOrder


done_flag = None

class StoragyNavToDestination(Node):
    def __init__(self, Nav2pose_node):
        super().__init__('i6robotics_control_nav_action_node')
        self.get_logger().info("Action Server Initialized")

        self.action_server = ActionServer(
            self,
            NavOrder,
            '/i6robotics_navigation_server',
            self.execute_callback
        )
        self.Nav2pose_node = Nav2pose_node  # Action Client Node

        self.navigator = BasicNavigator()
        self.navigator.lifecycleStartup()
        self.navigator.waitUntilNav2Active()


    def execute_callback(self, goal_handle):
        global done_flag
        self.get_logger().info(f"New goal received: {goal_handle.request.goal_pose}")
        
        # nav action 객체의 feedback msg <= client에서 발생한 것으로 활용
        feedback_msg = NavOrder.Feedback()
        def feedback_callback(feedback):
            feedback_msg.current_pose = feedback.feedback.current_pose
            feedback_msg.distance_remaining = feedback.feedback.distance_remaining
            #print("ETA:", feedback.feedback.estimated_time_remaining)
            #self.get_logger().info(f"Feedback received: {feedback_msg}")
            goal_handle.publish_feedback(feedback_msg)

        print("42")
        """if done_flag == True:
            goal_handle.succeed()"""
        done_flag = False
        self.Nav2pose_node.send_goal(goal_handle.request.goal_pose, feedback_callback)
        print("44")
        i=0
        """while done_flag != True:
            if i%10 == 0:
                print("wait")
            i +=1"""

        goal_handle.succeed()  # 종료
        result = NavOrder.Result()
        result.result = "Goal Sent to Client"
        return result


class NavToPoseActionClient(Node):
    def __init__(self):
        super().__init__('nav_to_pose_action_client')
        self.get_logger().info("Action Client Initialized")
        self.nav_to_pose_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self.initial_pose_pub = self.create_publisher(PoseWithCovarianceStamped,
                                                      'initialpose',
                                                      10)
        self.initial_pose = PoseStamped() # 데이터 타입 잡기
        self.initial_pose.header.frame_id = 'map'
        
        self.destination_pose = PoseStamped() # 데이터 타입 잡기
        self.destination_pose.header.frame_id = 'map'
        self.is_first_order = True

    def send_goal(self, goal_pose, feedback_callback=None):
        if self.is_first_order:
            self.initial_pose.header.stamp = self.get_clock().now().to_msg()
            self.initial_pose.pose.position.x = -0.169 
            self.initial_pose.pose.position.y = 0.25
            self.initial_pose.pose.position.z = 0.0
            self.initial_pose.pose.orientation.z = 0.0
            self.initial_pose.pose.orientation.w = 0.999

            msg = PoseWithCovarianceStamped()
            msg.pose.pose = self.initial_pose.pose
            msg.header.frame_id = self.initial_pose.header.frame_id
            msg.header.stamp = self.initial_pose.header.stamp
            self.get_logger().info('Publishing Initial Pose')
            self.initial_pose_pub.publish(msg)
            self.is_first_order = False


        self.get_logger().info(f"Sending goal to NavigateToPose: {goal_pose}")
        
        # destination
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = PoseStamped()
        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        goal_msg.pose.pose = goal_pose

        # send_goal => Navigate to pose
        while not self.nav_to_pose_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info("Waiting for NavigateToPose action server...")
        
        send_goal_future = self.nav_to_pose_client.send_goal_async(goal_msg, feedback_callback=feedback_callback)
        send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn("Goal rejected by NavigateToPose server")
            return
        self.get_logger().info("Goal accepted by NavigateToPose server")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.result_callback)

    def result_callback(self, future):
        global done_flag
        result = future.result()
        if result.status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info("Goal succeeded!")
        elif result.status == GoalStatus.STATUS_ABORTED:
            self.get_logger().warn("Goal aborted!")
        elif result.status == GoalStatus.STATUS_CANCELED:
            self.get_logger().warn("Goal canceled!")
        else:
            self.get_logger().warn(f"Unknown result status: {result.status}")
        done_flag = True
        print("done!")

# Main 함수
def main(args=None):
    rp.init(args=args)
    executor = MultiThreadedExecutor()

    # Action Server와 Client 노드 생성
    client_node = NavToPoseActionClient()
    server_node = StoragyNavToDestination(client_node)

    # 노드 등록
    executor.add_node(client_node)
    executor.add_node(server_node)

    try:
        executor.spin()
    finally:
        executor.shutdown()
        server_node.destroy_node()
        client_node.destroy_node()
        rp.shutdown()

if __name__ == '__main__':
    main()
