import rclpy
from rclpy.node import Node
from i6robotics_control_msgs.srv import Order
from geometry_msgs.msg import PoseStamped, Pose

class TestClient(Node):
    def __init__(self):
        super().__init__('test_client')
        self.client = self.create_client(Order, 'order')  # 서비스 이름
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('서비스 서버를 기다리는 중...')
        self.req = Order.Request()

    def send_request(self, goal_pose):
        self.req.order = 'nav_to_pose'
        self.req.goal_pose = goal_pose
        self.future = self.client.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.resuls()
    
if __name__=='__main__':
    rclpy.init(args=None)
    node = TestClient()
    goal_pose = Pose()
    goal_pose.position.x = 0.20
    goal_pose.position.y = -2.62
    goal_pose.position.z = 0.0
    goal_pose.orientation.x = 0.0
    goal_pose.orientation.y = 0.0
    goal_pose.orientation.z = -0.80
    goal_pose.orientation.w = 0.6

    response = node.send_request(goal_pose)
    node.destroy_node()
    rclpy.shutdown()
