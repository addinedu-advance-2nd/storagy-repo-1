import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage, Image, LaserScan
import cv2
import numpy as np
import threading
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy, DurabilityPolicy
from cv_bridge import CvBridge

bridge = CvBridge()

qos_profile = QoSProfile(
    depth=5,
    history=HistoryPolicy.KEEP_LAST,
    reliability=ReliabilityPolicy.BEST_EFFORT,
    durability=DurabilityPolicy.VOLATILE)

class ImageSubscriber(Node):
    def __init__(self):
        super().__init__('image_subscriber')
        self.subscription_rgb = self.create_subscription(
            CompressedImage,
            'compressed_image',
            self.listener_callback_rgb,
            qos_profile)
        self.subscription_rgb

        self.subscription_depth = self.create_subscription(
            Image,
            'depth_image',
            self.listener_callback_depth,
            qos_profile)
        self.subscription_depth

        self.subscription_lidar = self.create_subscription(
            LaserScan,
            'lidar_data',
            self.listener_callback_lidar,
            qos_profile)
        self.subscription_lidar

        self.latest_frame = None  # 최신 프레임 저장
        self.lock = threading.Lock()  # 스레드 안전을 위한 락

    def listener_callback_rgb(self, msg):
        # bridge.compressed_imgmsg_to_cv2를 사용하여 압축된 이미지 해제
        image_np = bridge.compressed_imgmsg_to_cv2(msg, "bgr8")
        cv2.imshow('RGB Image', image_np)
        cv2.waitKey(1)

    def listener_callback_depth(self, msg):
        # bridge.compressed_imgmsg_to_cv2를 사용하여 압축된 이미지 해제
        image_np = bridge.imgmsg_to_cv2(msg, "passthrough")
        image_np = cv2.normalize(image_np, None, 0, 255, cv2.NORM_MINMAX)
        image_np = np.uint8(image_np)
        cv2.imshow('Depth Image', image_np)
        cv2.waitKey(1)

    def listener_callback_lidar(self, msg):
        # bridge.compressed_imgmsg_to_cv2를 사용하여 압축된 이미지 해제
        print('Lidar data 획득')
    


def main(args=None):
    rclpy.init(args=args)
    image_subscriber = ImageSubscriber()

    # # OpenCV 이미지를 표시하는 스레드 시작
    # display_thread = threading.Thread(target=image_subscriber.display_image)
    # display_thread.start()

    try:
        rclpy.spin(image_subscriber)
    except KeyboardInterrupt:
        image_subscriber.get_logger().info('Shutting down node.')
    finally:
        cv2.destroyAllWindows()
        image_subscriber.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()