import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped, Pose, PoseWithCovarianceStamped
from action_msgs.msg import GoalStatus
from i6robotics_control_msgs.srv import Order, FollowOrder
from i6robotics_control_msgs.action import Follow
from guiding_services.srv import SetGoalPose
from std_srvs.srv import SetBool
from i6robotics_control_msgs.msg import NavOrderFeedback
from geometry_msgs.msg import Twist

import threading
import time

class MyActionClient(Node):
    def __init__(self):
        super().__init__('my_action_client')
        # 각 액션 서버에게 요청을 보내는 Clients
        self.nav_to_pose_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        # self.follow_client = ActionClient(self, Follow, 'follow')
        self.follow_service_client = self.create_client(FollowOrder, 'follow_order')
        self.nav_with_customer_client = self.create_client(SetGoalPose, 'set_goal_pose')
        self.aruco_client = self.create_client(SetBool, 'aruco_order')
        self.initial_pose_pub = self.create_publisher(PoseWithCovarianceStamped,
                                                      'initialpose',
                                                      10)
        self.publisher = self.create_publisher(
            NavOrderFeedback, #메시지 타입
            '/i6robotics_navigation_feedback', #발행할 토픽
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

        # UI로부터 요청을 수락하는 Service server
        self.srv = self.create_service(Order, 'order', self.order_callback)
        self.get_logger().info('주행 명령 수신 서비스 서버가 시작되었습니다.')

        self.current_pose = PoseStamped() 
        self.current_pose.header.frame_id = 'map'
        # self.initilize_current_pose()

        # self.initilize_start_pose()
        self.comeon = True
        self.go_station = False
        self.follow_init = False
        
    # def initilize_start_pose(self):
    #     init_pose = PoseWithCovarianceStamped()
    #     init_pose.header.frame_id = 'map'
    #     init_pose.header.stamp = self.get_clock().now().to_msg()
    #     init_pose.pose.pose.position.x = -0.34
    #     init_pose.pose.pose.position.y = 1.42
    #     init_pose.pose.pose.position.z = 0.0
    #     init_pose.pose.pose.orientation.z = 0.0
    #     init_pose.pose.pose.orientation.w = 0.999
    #     self.get_logger().info('Publishing Initial Pose')
    #     self.initial_pose_pub.publish(init_pose)


    # def initilize_current_pose(self):
    #     self.current_pose.header.stamp = self.get_clock().now().to_msg()
    #     self.current_pose.pose.position.x = -0.34
    #     self.current_pose.pose.position.y = 1.42
    #     self.current_pose.pose.position.z = 0.0
    #     self.current_pose.pose.orientation.z = -0.0084
    #     self.current_pose.pose.orientation.w = 0.999

    #     msg = PoseWithCovarianceStamped()
    #     msg.pose.pose = self.current_pose.pose
    #     msg.header.frame_id = self.current_pose.header.frame_id
    #     msg.header.stamp = self.current_pose.header.stamp
    #     self.get_logger().info('Publishing Initial Pose')
    #     self.initial_pose_pub.publish(msg)
        

    # Service Server. 주행 명령 수신 서비스 서버
    def order_callback(self, request, response):
        self.get_logger().info(f"Received order : {request.order}")
        if request.order == 'follow_on':
            if self.follow_init == False:
                self.follow_send_order('follow_start')
                self.follow_init = True
            else:
                self.follow_send_order('follow_on')
            response.accepted = True
        elif request.order == 'follow_off':
            self.follow_send_order('follow_off')
            response.accepted = True
        elif request.order == 'follow_reset':
            self.follow_send_order('follow_reset')
            response.accepted = True
        elif request.order == 'nav_to_pose':
            if request.goal_pose is not None:
                goal_pose = request.goal_pose
                self.nav_to_pose_send_goal(goal_pose)
                response.accepted = True
            else:
                response.accepted = False
        elif request.order == 'nav_to_pose_with_client':
            if request.goal_pose is not None:
                # 최초 안내 명령 보내기 전 한 바퀴 회전.
                self.msg.angular.z = 0.5
                for i in range(11):
                    self.cmd_vel_publisher.publish(self.msg)
                    time.sleep(0.8)
                goal_pose = request.goal_pose
                self.nav_with_customer_send_goal(goal_pose)
                response.accepted = True
            else:
                response.accepted = False
        elif request.order == 'nav_to_station':
            goal_pose = Pose() 
            goal_pose.position.x = 0.1 # -0.169
            goal_pose.position.y = 0.25
            goal_pose.position.z = 0.0
            goal_pose.orientation.z = -0.99
            goal_pose.orientation.w = 0.001
            self.go_station = True
            self.nav_to_pose_send_goal(goal_pose)
            response.accepted = True
        else:
            response.accepted = False
        return response

    # Service Client. nav_with_customer client
    def nav_with_customer_send_goal(self, goal_pose):
        while not self.nav_with_customer_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('nav with customer 서비스 서버를 기다리는 중...')
        req = SetGoalPose.Request()
        req.goal_pose = goal_pose
        self.nav_with_customer_future = self.nav_with_customer_client.call_async(req)
        while self.nav_with_customer_future.done():
            rclpy.spin_once(node)
        self.get_logger().info('Sending goal to nav with customer server')
        return self.nav_with_customer_future.result()

# 2.9 -1.86 -0.67 0.75
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
            # 첫 카트 호출 시 고객 팔로우 인식 시작
            if self.comeon == True:
                self.follow_send_order('follow_start')
                self.follow_init = True
                self.comeon = False

            # 성공했을 시 아루코마커 정렬 시작
            if self.go_station == True:
                while not self.aruco_client.wait_for_service(timeout_sec=1.0):
                    self.get_logger().info('aruco 서버를 기다리는 중...')
                req = SetBool.Request()
                req.data = True
                self.aruco_future = self.aruco_client.call_async(req)
                while self.aruco_future.done():
                    rclpy.spin_once(node)
                self.get_logger().info('Sending True to aruco server')
        elif result.status == GoalStatus.STATUS_ABORTED:
            # 실패했을 시 아루코마커 정렬 X
            self.get_logger().warn("Goal aborted!")
        elif result.status == GoalStatus.STATUS_CANCELED:
            self.get_logger().warn("Goal canceled!")
            # 실패했을 시 아루코마커 정렬 X
        else:
            self.get_logger().warn(f"Unknown result status: {result.status}")
        self.go_station = False

    def follow_send_order(self, order):
        while not self.follow_service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Follow 서비스 서버를 기다리는 중...')
        req = FollowOrder.Request()
        req.order = order
        self.follow_future = self.follow_service_client.call_async(req)
        self.get_logger().info('Sending order to follow server')
        while self.follow_future.done():
            rclpy.spin_once(node)
        return self.follow_future.result()
    

if __name__ == '__main__':
    rclpy.init(args=None)
    node = MyActionClient()
    # keyboard_thread = threading.Thread(target=listen_to_keyboard, daemon=True)
    # keyboard_thread.start()
    

    rclpy.spin(node)
