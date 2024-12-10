import rclpy as rp
from rclpy.node import Node
from rclpy.action import ActionServer
import time
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped, Pose
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
from rclpy.duration import Duration

from nav2_msgs.action import NavigateToPose

# 멀티쓰레드
from rclpy.executors import MultiThreadedExecutor

#노드
#from i6robotics_control.i6robotics_nav_order_sub_node import StoragyNavOrderSubscriber
from i6robotics_control_msgs.action import NavOrder #액션 정의


"""
Pose
Point position
        float64 x
        float64 y
        float64 z
Quaternion orientation
        float64 x 0
        float64 y 0
        float64 z 0
        float64 w 1

PoseStamped
std_msgs/Header header
        builtin_interfaces/Time stamp
                int32 sec
                uint32 nanosec
        string frame_id
Pose pose
        Point position
                float64 x
                float64 y
                float64 z
        Quaternion orientation
                float64 x 0
                float64 y 0
                float64 z 0
                float64 w 1

NavigateToPose - action
    #goal definition
    geometry_msgs/PoseStamped pose
    string behavior_tree
    ---
    #result definition
    std_msgs/Empty result
    ---
    #feedback definition
    geometry_msgs/PoseStamped current_pose
    builtin_interfaces/Duration navigation_time
    builtin_interfaces/Duration estimated_time_remaining
    int16 number_of_recoveries
    float32 distance_remaining


i6robotics_control_msgs -NavOrder.action
    #Request
    geometry_msgs/Pose goal_pose
    ---
    #Result

    ---
    # Feedback
    geometry_msgs/PoseStamped current_pose
    float32 distance_remaining

"""


"""class StoragyNavOrderSub_Action(StoragyNavOrderSubscriber):
    def __init__(self, ac_server):
        super().__init__()
        self.ac_server = ac_server

    def callback(self, msg):
        print("New order(msg): ",msg)
        self.ac_server.destination_pose.pose.position.x = msg.position.x
        self.ac_server.destination_pose.pose.position.y = msg.position.y
        self.ac_server.destination_pose.pose.orientation.w = msg.orientation.w"""

class StoragyNavToDestination(Node):

    def __init__(self):
        super().__init__('i6robotics_control_simplecmd_node')
        
        self.is_first_time = True
        self.is_stop = False

        """self.subscription_position = self.create_subscription(
            PoseWithCovarianceStamped, 
            'amcl_pose', 
            self.check_position, 
            5 )"""
        #self.subscription_position  
        self.get_logger().info("Loading")

        self.navigator = BasicNavigator()
        self.navigator.lifecycleStartup()
        self.navigator.waitUntilNav2Active()

        self.initial_pose = PoseStamped() # 데이터 타입 잡기
        self.initial_pose.header.frame_id = 'map'
        
        self.destination_pose = PoseStamped() # 데이터 타입 잡기
        self.destination_pose.header.frame_id = 'map'
        self.result = self.navigator.getResult()

        self.action_server = ActionServer( # actionserver생성명령
            self,
            NavOrder, #액션타입
            '/i6robotics_navigation_server', #액션서버명
            self.execute_callback
        )

    def check_position(self,msg):
        print(msg)
        
    def execute_callback(self, goal_handle):
        if self.is_first_time:
            self.initial_pose.header.stamp = self.navigator.get_clock().now().to_msg()
            self.initial_pose.pose.position.x = -0.169 
            self.initial_pose.pose.position.y = 0.25
            self.initial_pose.pose.position.z = 0.0
            self.initial_pose.pose.orientation.z = 0.0
            self.initial_pose.pose.orientation.w = 0.999
            self.navigator.setInitialPose(self.initial_pose)
            print('first time!')
            self.is_first_time = False
        
        # charge point
        print("rcv message(goal_handle): ", goal_handle.request)

        self.destination_pose.header.stamp = self.navigator.get_clock().now().to_msg()
        self.destination_pose.pose.position.x = goal_handle.request.goal_pose.position.x 
        self.destination_pose.pose.position.y = goal_handle.request.goal_pose.position.y 
        self.destination_pose.pose.position.z =  goal_handle.request.goal_pose.position.z
        self.destination_pose.pose.orientation.x = goal_handle.request.goal_pose.orientation.x
        self.destination_pose.pose.orientation.y = goal_handle.request.goal_pose.orientation.y
        self.destination_pose.pose.orientation.z =  goal_handle.request.goal_pose.orientation.z
        self.destination_pose.pose.orientation.w =  goal_handle.request.goal_pose.orientation.w 
        
        print("storagy's goal:\n", 
                "x = ", self.destination_pose.pose.position.x,
                "\n y = ", self.destination_pose.pose.position.y, 
                "\n z = ", self.destination_pose.pose.position.z)
        
        #behavior_tree = " "
        self.navigator.goToPose(self.destination_pose) #, behavior_tree)
        time.sleep(0.1)

        feedback_msg = NavOrder.Feedback()
        
        while not self.navigator.isTaskComplete():
            feedback = self.navigator.getFeedback()
            if feedback:
                print("Navigation time: ",feedback.navigation_time)
                print("Recoveries: ",feedback.number_of_recoveries)
                #print("ETA: ",feedback.estimated_time_remaining)
                print("Current_pose: ", feedback.current_pose)
                print("Distance remaining: " + 
                      '{:.2f}'.format(feedback.distance_remaining) + 
                      ' meters.')
                
                feedback_msg = NavOrder.Feedback()
                feedback_msg.current_pose = feedback.current_pose
                feedback_msg.distance_remaining = feedback.distance_remaining
                goal_handle.publish_feedback(feedback_msg)

        # Do something depending on the return code
        result = self.navigator.getResult()
        """if self.navigator.isTaskComplete():
            self.state = "drive_mode"""

        if result == TaskResult.SUCCEEDED:
            print('Goal succeeded!')
            goal_handle.succeed()
            
        elif result == TaskResult.CANCELED:
            print('Goal was canceled!')
            
        elif result == TaskResult.FAILED:
            print('Goal failed!')
            
        else:
            print('Goal has an invalid return status!')
            
        result = NavOrder.Result()

        return result
    

def main(args = None):
    rp.init(args=args)

    executor = MultiThreadedExecutor()
    ac = StoragyNavToDestination() # action server
    
    executor.add_node(ac)

    try:
        executor.spin()

    finally:
        executor.shutdown()
        ac.destroy_node()
        
        rp.shutdown()

if __name__ == '__main__':
    main()