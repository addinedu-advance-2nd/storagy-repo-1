import rclpy
import time
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import CompressedImage
from std_srvs.srv import SetBool
from cv_bridge import CvBridge
import cv2
import cv2.aruco as aruco
import numpy as np
import math
from rclpy.qos import QoSProfile, HistoryPolicy, ReliabilityPolicy, DurabilityPolicy

class ArucoMarkerDetector(Node):
    def __init__(self):
        super().__init__('aruco_marker_detector')
        qos_profile = QoSProfile(
            depth=5,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE)
        self.subscription = self.create_subscription(
            CompressedImage, 'compressed_image', self.camera_callback, qos_profile)
        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.bridge = CvBridge()
        # 카메라 캘리브레이션 값
        self.camera_matrix = np.array([
            [452.05,  0.00, 326.24],
            [0.00, 452.05, 243.60],
            [0.00,   0.00,   1.00],
        ])
        self.dist_coeffs = np.array([0.0457, -0.0672, -2.226e-05, -0.000114, 0.0])
        # 마커 크기 (10cm)
        self.marker_length = 0.1
        self.state = "Alignment"
        self.x_tvec_save = 0
        # ArUco 마커 사전 및 탐지 파라미터
        self.aruco_dict = cv2.aruco.getPredefinedDictionary(aruco.DICT_4X4_50)
        self.parameters = cv2.aruco.DetectorParameters()

        # Control_action_clients로부터 작동 관련 명령을 수신하는 Service server
        self.srv = self.create_service(SetBool, 'aruco_order', self.order_callback)
        self.get_logger().info('Aruco 정밀 복귀 명령 수신 서비스 서버가 시작되었습니다.')
        
        self.activate = False

    def order_callback(self, request, response):
        self.get_logger().info(f"Aruco order 수신 : {request.data}")
        if request.data == True:
            self.activate = True
            response.success = True
        elif request.data == False:
            self.activate = False
            response.success = True
        else:
            response.success = False
        self.get_logger().info(f"Aruco order response : {response.success}")
        return response

    def camera_callback(self, msg):
        if not self.activate:
            return

        frame = self.bridge.compressed_imgmsg_to_cv2(msg, desired_encoding='bgr8')  # ROS 메시지 -> numpy 배열 변환
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)  # 이미지 -> 그레이스케일 변환
        corners, ids, _ = aruco.detectMarkers(gray, self.aruco_dict, parameters=self.parameters)
        if ids is not None:
            rvecs, tvecs, _ = aruco.estimatePoseSingleMarkers(
                corners, self.marker_length, self.camera_matrix, self.dist_coeffs)
            for i in range(len(ids)):
                tvec = tvecs[i][0]
                x_tvec = tvec[0]
                z_tvec = tvec[2]
                rotation_matrix, _ = cv2.Rodrigues(rvecs[i])
                rotation_degree = self.rotMat2degree(rotation_matrix)
                self.get_logger().info(f'Translation: {tvecs[i]}')
                # self.get_logger().info(f'Angle (Euler Angles): {rotation_degree}')
                self.get_logger().info(f'Pitch (Y-axis rotation): {rotation_degree[1]}')  # y값(yaw)만 출력
                if self.state == "Alignment":
                    self.align_to_pitch(rotation_degree[1],x_tvec)
                    # self.align_to_pitch(rotation_degree[1], x_tvec)
                    self.x_tvec_save = x_tvec
                elif self.state == "Rotation":
                    if self.x_tvec_save < 0:
                        self.rotate_angle(205, self.x_tvec_save)  # + 값 시계
                    elif self.x_tvec_save > 0: # 225
                        self.rotate_angle(-205, self.x_tvec_save)  # - 값 반시계
                elif self.state == "Linear":
                    self.move_linear(z_tvec)
                elif self.state == "Complete":
                    # 반바꾸 돌기.
                    segment_angle = 195.00 / 10
                    segment_radians = math.radians(segment_angle)
                    max_angular_speed = 0.5
                    twist = Twist()
                    count = 0
                    while True:
                        count += 1
                        angular_z = segment_radians
                        if abs(angular_z) > max_angular_speed:
                            angular_z = max_angular_speed * np.sign(angular_z)
                        twist.angular.z = angular_z
                        self.cmd_vel_publisher.publish(twist)
                        self.get_logger().info(f"angular.z = {angular_z:.2f}")
                        if count == 20:
                            break
                        time.sleep(1.0)
                    twist.angular.z = 0.0
                    self.cmd_vel_publisher.publish(twist)
                    self.get_logger().info("Rotation complete.")
                    self.activate = False
                    time.sleep(1.0)
                cv2.drawFrameAxes(frame, self.camera_matrix, self.dist_coeffs, rvecs[i], tvecs[i], self.marker_length)
                cv2.aruco.drawDetectedMarkers(frame, corners, ids)
        # else:
        #     self.search_for_marker()
        cv2.imshow('ArUco Marker Detection', frame)
        cv2.waitKey(1)

    def rotMat2degree(self, rotation_matrix):
        sy = math.sqrt(rotation_matrix[0, 0] ** 2 + rotation_matrix[1, 0] ** 2)
        singular = sy < 1e-6
        if not singular:
            x = math.atan2(rotation_matrix[2, 1], rotation_matrix[2, 2])  # Roll (X-axis)
            y = math.atan2(-rotation_matrix[2, 0], sy)  # Pitch (Y-axis)
            z = math.atan2(rotation_matrix[1, 0], rotation_matrix[0, 0])  # Yaw (Z-axis)
        else:
            x = math.atan2(-rotation_matrix[1, 2], rotation_matrix[1, 1])
            y = math.atan2(-rotation_matrix[2, 0], sy)
            z = 0
        x = math.degrees(x)
        y = math.degrees(y)
        z = math.degrees(z)
        return x, y, z
    def align_to_pitch(self, pitch_angle,x_tvec):  # (self, pitch_angle)
        # 라디안으로 변환
        time.sleep(2)
        angular_z = math.radians(pitch_angle)
        print(f'pitch_angle: {angular_z}')
        max_angular_speed = 0.3
        twist = Twist()
        if abs(angular_z) > max_angular_speed:
            angular_z = max_angular_speed * np.sign(angular_z)
        if abs(angular_z) > 0.02: # 0.02
            twist.angular.z = -angular_z  # Pitch 방향 회전
            self.cmd_vel_publisher.publish(twist)
            self.get_logger().info(f"Applying angular.z: {angular_z:.2f}")
        else:
            twist.linear.x = 0.0
            twist.angular.z = 0.0
            self.cmd_vel_publisher.publish(twist)
            self.get_logger().info("Pitch alignment complete.")
            time.sleep(1)
            # if self.state != "Linear":
            #     self.state = "Rotation"
            if abs(x_tvec) < 0.05:
                # self.get_logger().info("x_tvec is small, staying in Alignment.")
                self.state = "Complete"
            else:
                self.state = "Rotation"
    def rotate_angle(self,angle,x_tvec):
        segment_angle = angle / 10
        segment_radians = math.radians(segment_angle)
        max_angular_speed = 0.5
        twist = Twist()
        for i in range(10):
            angular_z = segment_radians
            if abs(angular_z) > max_angular_speed:
                angular_z = max_angular_speed * np.sign(angular_z)
            twist.angular.z = angular_z
            self.cmd_vel_publisher.publish(twist)
            self.get_logger().info(f"angular.z = {angular_z:.2f}")
            time.sleep(1.0)
        twist.angular.z = 0.0
        self.cmd_vel_publisher.publish(twist)
        self.get_logger().info("Rotation complete.")
        # 직선이동
        total_distance = abs(x_tvec) * 2.0
        max_linear_speed = 0.4
        segment_distance = total_distance / 3
        for i in range(3):
            twist.linear.x = min(segment_distance, max_linear_speed)  # 한 번에 이동할 거리와 속도 설정
            self.cmd_vel_publisher.publish(twist)
            self.get_logger().info(f"Moving linear.x: {twist.linear.x:.2f}")
            time.sleep(1)
            total_distance -= abs(twist.linear.x)
            if total_distance < 0.02:
                break
        twist.linear.x = 0.0
        self.cmd_vel_publisher.publish(twist)
        self.get_logger().info("Linear movement complete.")
        # 반대 이동.
        for i in range(10):
            angular_z = -segment_radians
            if abs(angular_z) > max_angular_speed:
                angular_z = max_angular_speed * np.sign(angular_z)
            twist.angular.z = angular_z
            self.cmd_vel_publisher.publish(twist)
            self.get_logger().info(f"angular.z = {angular_z:.2f}")
            time.sleep(1)
        twist.angular.z = 0.0
        self.cmd_vel_publisher.publish(twist)
        self.get_logger().info("Reverse rotation complete.")
        self.state = "Linear"
    def move_linear(self,z_tvec):
        twist = Twist()
        max_linear_speed = 0.1
        if abs(z_tvec) > 0.5:
            twist.linear.x = max_linear_speed
            self.cmd_vel_publisher.publish(twist)
            self.get_logger().info(f"Moving forward. z_tvec: {z_tvec:.2f}")
            time.sleep(0.1)
        else:
            twist.linear.x = 0.0
            self.cmd_vel_publisher.publish(twist)
            self.get_logger().info("Linear movement stop")
            self.state = "Alignment"
def main(args=None):
    rclpy.init(args=args)
    node = ArucoMarkerDetector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
if __name__ == '__main__':
    main()