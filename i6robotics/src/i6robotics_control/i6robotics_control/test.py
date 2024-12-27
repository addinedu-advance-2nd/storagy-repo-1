import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CompressedImage
import numpy as np
import cv2
from rclpy.qos import qos_profile_sensor_data, QoSProfile, HistoryPolicy, ReliabilityPolicy, DurabilityPolicy
from cv_bridge import CvBridge

bridge = CvBridge()
qos_profile = QoSProfile(
            depth = 10,
            history = HistoryPolicy.KEEP_LAST,
            reliability = ReliabilityPolicy.BEST_EFFORT,
            durability = DurabilityPolicy.VOLATILE
            )

class CompressedImagePublisher(Node):
    def __init__(self):
        super().__init__('compressed_image_publisher')
        self.subscription = self.create_subscription(
            Image, '/camera/color/image_raw', self.camera_callback, 10
        )
        self.publisher = self.create_publisher(
            CompressedImage,
            'compressed_image',
            qos_profile)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.image = None
        self.depth_image = None
        self.lidar_data = None

    def camera_callback(self, msg):
        # self.image = msg
        frame = bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        print(frame.dtype)
        img_msg = bridge.cv2_to_compressed_imgmsg(frame)
        print(type(img_msg))

    def timer_callback(self):
        if self.image is not None:
            frame = bridge.imgmsg_to_cv2(self.image, desired_encoding='bgr8')
            img_msg = bridge.cv2_to_compressed_imgmsg(frame)
            self.publisher.publish(img_msg)
            self.get_logger().info('이미지 pub')

    def destroy_node(self):
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    compressed_image_publisher = CompressedImagePublisher()
    try:
        rclpy.spin(compressed_image_publisher)
    except KeyboardInterrupt:
        compressed_image_publisher.get_logger().info('Shutting down node.')
    finally:
        compressed_image_publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()