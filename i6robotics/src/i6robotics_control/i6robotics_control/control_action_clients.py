import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped, Pose, PoseWithCovarianceStamped
from action_msgs.msg import GoalStatus
from i6robotics_control_msgs.srv import Order
from i6robotics_control_msgs.action import Follow
from i6robotics_control_msgs.msg import NavOrderFeedback

import threading
import time

class MyActionClient(Node):
    def __init__(self):
        super().__init__('my_action_client')
        # 각 액션 서버에게 요청을 보내는 Clients
        self.nav_to_pose_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self.follow_client = ActionClient(self, Follow, 'follow')
        self.initial_pose_pub = self.create_publisher(PoseWithCovarianceStamped,
                                                      'initialpose',
                                                      10)
        self.publisher = self.create_publisher(
            NavOrderFeedback, #메시지 타입
            '/i6robotics_navigation_feedback', #발행할 토픽
            10
        )
        
        # UI로부터 요청을 수락하는 Service server
        self.srv = self.create_service(Order, 'order', self.order_callback)
        self.get_logger().info('주행 명령 수신 서비스 서버가 시작되었습니다.')

        self.current_pose = PoseStamped() 
        self.current_pose.header.frame_id = 'map'
        self.initilize_current_pose()

        self.follow_goal_handle = None

    def initilize_current_pose(self):
        self.current_pose.header.stamp = self.get_clock().now().to_msg()
        self.current_pose.pose.position.x = -0.169 
        self.current_pose.pose.position.y = 0.25
        self.current_pose.pose.position.z = 0.0
        self.current_pose.pose.orientation.z = 0.0
        self.current_pose.pose.orientation.w = 0.999

        msg = PoseWithCovarianceStamped()
        msg.pose.pose = self.initial_pose.pose
        msg.header.frame_id = self.initial_pose.header.frame_id
        msg.header.stamp = self.initial_pose.header.stamp
        self.get_logger().info('Publishing Initial Pose')
        self.initial_pose_pub.publish(msg)
        

    # Service Server. 주행 명령 수신 서비스 서버
    def order_callback(self, request, response):
        if request.order == 'follow_on':
            pass
        elif request.order == 'follow_off':
            pass
        elif request.order == 'nav_to_pose':
            if request.goal_pose is not None:
                goal_pose = request.goal_pose
                self.nav_to_pose_send_goal(goal_pose)
                response.accepted = True
            else:
                response.accepted = False
        elif request.order == 'nav_to_pose_client':
            pass
        elif request.order == 'nav_to_station':
            pass
        else:
            response.accepted = False
        return response


    # Action Client. nav_to_pose_client
    def nav_to_pose_send_goal(self, goal_pose, feedback_callback=None):
        # destination
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = PoseStamped()
        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        goal_msg.pose.pose = goal_pose

        self.get_logger().info(f"Sending goal to NavigateToPose: {goal_pose}")

        # send_goal => Navigate to pose
        while not self.nav_to_pose_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info("Waiting for NavigateToPose action server...")
        
        send_goal_future = self.nav_to_pose_client.send_goal_async(goal_msg, feedback_callback=self.nav_to_pose_feedback_callback)
        send_goal_future.add_done_callback(self.nav_to_pose_goal_response_callback)

    def nav_to_pose_goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn("Goal rejected by NavigateToPose server")
            return
        self.get_logger().info("Goal accepted by NavigateToPose server")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.nav_to_pose_result_callback)

    def nav_to_pose_feedback_callback(self, feedback_msg):
        self.current_pose = feedback_msg.feedback.current_pose

        msg = NavOrderFeedback() #Twist 타입의 메시지 정의
        msg.current_pose = feedback_msg.feedback.current_pose
        if feedback_msg.feedback.distance_remaining :
            msg.distance_remaining = round(feedback_msg.feedback.distance_remaining, 2)
        else:
            msg.distance_remaining = feedback_msg.feedback.distance_remaining
            
        # 메시지 퍼블리시
        self.publisher.publish(msg) 
        
        # self.get_logger().info(f'Feedback: {feedback_msg.feedback}')

    def nav_to_pose_result_callback(self, future):
        result = future.result()
        if result.status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info("Goal succeeded!")
        elif result.status == GoalStatus.STATUS_ABORTED:
            self.get_logger().warn("Goal aborted!")
        elif result.status == GoalStatus.STATUS_CANCELED:
            self.get_logger().warn("Goal canceled!")
        else:
            self.get_logger().warn(f"Unknown result status: {result.status}")


    # Action Client. follow_client
    def follow_send_goal(self, feedback_callback=None):
        goal_msg = Follow.Goal()

        self.get_logger().info(f"Sending goal to Follow")

        # send_goal => Follow
        while not self.follow_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info("Waiting for Follow action server...")
        
        send_goal_future = self.follow_client.send_goal_async(goal_msg, feedback_callback=self.follow_feedback_callback)
        send_goal_future.add_done_callback(self.follow_goal_response_callback)

    def follow_goal_response_callback(self, future):
        self.follow_goal_handle = future.result()
        if not self.follow_goal_handle.accepted:
            self.get_logger().warn("Goal rejected by Follow server")
            return
        self.get_logger().info("Goal accepted by Follow server")
        result_future = self.follow_goal_handle.get_result_async()
        result_future.add_done_callback(self.follow_result_callback)

    def follow_feedback_callback(self, feedback_msg):
        self.get_logger().info(f'Feedback: {feedback_msg.feedback}')

    def follow_result_callback(self, future):
        result = future.result()
        if result.status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info("Goal succeeded!")
        elif result.status == GoalStatus.STATUS_ABORTED:
            self.get_logger().warn("Goal aborted!")
        elif result.status == GoalStatus.STATUS_CANCELED:
            self.get_logger().warn("Goal canceled!")
        else:
            self.get_logger().warn(f"Unknown result status: {result.status}")

    def follow_send_cancel_request(self):
        self.get_logger().info('Sending goal cancel to Follow')
        cancel_future = self.follow_goal_handle.cancel_goal_async()
        cancel_future.add_done_callback(self.follow_cancel_done_callback)

    def follow_cancel_done_callback(self, future):
        cancel_response = future.result()
        if len(cancel_response.goals_canceling) > 0:
            self.get_logger().info('Goal successfully cancelled.')
        else:
            self.get_logger().info('Goal cancellation failed or was not possible.')    

# # 추후 노드 안에 통신 수신으로 재구현. 지금은 테스트용
# def listen_to_keyboard():
#     while True:
#         user_input = input("Enter a number (1, 2, or 3 to perform an action, q to quit): ")
#         if user_input == '1':
#             goal_pose = Pose()
#             goal_pose.position.x = 0.20
#             goal_pose.position.y = -2.62
#             goal_pose.position.z = 0.0
#             goal_pose.orientation.x = 0.0
#             goal_pose.orientation.y = 0.0
#             goal_pose.orientation.z = -0.80
#             goal_pose.orientation.w = 0.6
#             node.nav_to_pose_send_goal(goal_pose)
#         elif user_input == '2':
#             goal_pose = Pose()
#             goal_pose.position.x = -0.06 
#             goal_pose.position.y = 0.05
#             goal_pose.position.z = 0.0
#             goal_pose.orientation.x = 0.0
#             goal_pose.orientation.y = 0.0
#             goal_pose.orientation.z = 0.0
#             goal_pose.orientation.w = 0.999
#             node.nav_to_pose_send_goal(goal_pose)
#         elif user_input == '3':
#             # Follow
#             # Follow 액션 서버를 만들고
#             # Follow Client를 만들어서 연결
#             node.follow_send_goal()
#         elif user_input == '4':
#             node.follow_send_cancel_request()    
#         elif user_input.lower() == 'q':
#             print("Exiting...")
#             break
#         else:
#             print("Invalid input. Please enter 1, 2, 3, or q.")




if __name__ == '__main__':
    rclpy.init(args=None)
    node = MyActionClient()
    # keyboard_thread = threading.Thread(target=listen_to_keyboard, daemon=True)
    # keyboard_thread.start()

    rclpy.spin(node)
