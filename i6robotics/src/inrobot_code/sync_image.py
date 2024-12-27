import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, LaserScan 
from cv_bridge import CvBridge
import numpy as np
import cv2
import socket
import pickle
import time
import threading

from message_filters import ApproximateTimeSynchronizer, Subscriber

class ImageListener(Node):
    def __init__(self):
        super().__init__('image_listener')

        self.bridge = CvBridge()

        self.rgb_sub = Subscriber(self, Image, '/camera/color/image_raw')

        self.depth_sub = Subscriber(self, Image, '/camera/depth/image_raw')

        self.lidar_sub = Subscriber(self, LaserScan, '/scan')

        self.ts = ApproximateTimeSynchronizer(
            [self.rgb_sub, self.depth_sub, self.lidar_sub],
            queue_size=10,
            slop=0.1
        )
        self.ts.registerCallback(self.image_callback)
        self.rgb_image = None
        self.depth_image = None

        self.ACK = True
        self.count = 0
        self.get_logger().info("Image Subscriber Node has started.")

    def image_callback(self, rgb_image, depth_image, lidar_data):
        self.rgb_image = self.bridge.imgmsg_to_cv2(rgb_image, desired_encoding='bgr8')
        self.depth_image = self.bridge.imgmsg_to_cv2(depth_image, desired_encoding='passthrough')    
        self.lidar_data = lidar_data


        # print(len(self.rgb_image.tobytes()))
        # print(len(cv2.imencode('.jpg', cv2.resize(self.rgb_image, (200,320), interpolation=cv2.INTER_AREA))[1]))
        # print(len(cv2.imencode('.jpg', self.depth_image)[1]))
        # print(len(cv2.imencode('.jpg', self.rgb_image, [cv2.IMWRITE_JPEG_QUALITY, 60])[1]))
        # print(len(cv2.imencode('.jpg', self.depth_image, [cv2.IMWRITE_JPEG_QUALITY, 60])[1].tobytes()))
        
        # print(len(pickle.dumps(lidar_data)))
        # print()

        # lx = 0.3
        # az = 0.3
        # going = lx * 0.5
        # target_angle = az
        # target_index = int((target_angle - lidar_data.angle_min) / lidar_data.angle_increment)
        # # print(target_index)
        # # 100 ~ 500 +- 200
        # target_min = target_index - 175
        # target_max = target_index + 175
        # rng = range(target_min, target_max)
        # # print(rng)
        # danger = False
        # count = 0
        # distance = []
        # for i in rng:
        #     if 0 <= i <= 600:
        #         if lidar_data.ranges[i] < 0.15 + going:
        #             count += 1
        # if count > 10:
        #     danger = True
        # print(danger)

        # print(len(lidar_data.ranges))
        # if 0 <= target_index < len(lidar_data.ranges):
        

        #     distance = lidar_data.ranges[100]
        # print(distance)

        # # 장애물 확인
        # if distance < 0.5:  # 0.5m 이내에 장애물이 있으면
        #     stop_robot()
        # else:
        #     move_robot()

        # print(lidar_data.angle_min)
        # print(lidar_data.angle_increment)
        # print(lidar_data.angle_max)

        # if self.count > 20:
        #     rgb_image = self.bridge.imgmsg_to_cv2(rgb_image, desired_encoding='bgr8')

        #     depth_image = self.bridge.imgmsg_to_cv2(depth_image, desired_encoding='passthrough')     
        #     rgb_image_cropped = rgb_image[30:430, :, :]
        #     depth_image_expanded = depth_image[:, :, np.newaxis].astype(np.uint8)
        #     image = np.concatenate((rgb_image_cropped, depth_image_expanded), axis=2)
        #     image = cv2.resize(image, (200,320), interpolation=cv2.INTER_AREA)

        #     # data = pickle.dumps(image)
        #     # print(image.dtype)
        #     # _, data = cv2.imencode('.jpg', image)
        #     data = pickle.dumps(image)
        #     self.client_socket.sendall(len(data).to_bytes(4, byteorder='big'))
        #     self.client_socket.sendall(data)

        #     self.count = 0
        # else:
        #     self.count += 1

        # image = temp_rgb[:,:,:3].astype(np.uint8)
        # cv2.imshow("color", image)
        # depth_image = temp_rgb[:,:,3:]
        # depth_frame_normalized = cv2.normalize(depth_image, None, 0, 255, cv2.NORM_MINMAX)
        # depth_frame_normalized = np.uint8(depth_frame_normalized)
        # cv2.imshow("depth", depth_frame_normalized)
        # cv2.waitKey(1)

        # data = rgb_image + depth_image
        # print(data.shape)
        # exit()

        # rgb_image = self.bridge.imgmsg_to_cv2(rgb_image, desired_encoding='bgr8')
        # _, rgb_image_encoded = cv2.imencode('.jpg', rgb_image)
        # rgb_data = pickle.dumps(rgb_image_encoded)
        # self.client_socket.sendall(len(rgb_data).to_bytes(4, byteorder='big'))
        # self.client_socket.sendall(rgb_data)

        # depth_image = self.bridge.imgmsg_to_cv2(depth_image, desired_encoding='passthrough')
        # _, depth_image_encoded = cv2.imencode('.jpg', depth_image)
        # depth_data = pickle.dumps(depth_image_encoded)
        # self.client_socket.sendall(len(depth_data).to_bytes(4, byteorder='big'))
        # self.client_socket.sendall(depth_data)

        # rgb_frame = self.bridge.imgmsg_to_cv2(rgb_image, desired_encoding='bgr8')
        # cv2.imshow("color", rgb_frame)
        # depth_frame = self.bridge.imgmsg_to_cv2(depth_image, desired_encoding="passthrough")
        # depth_frame_normalized = cv2.normalize(depth_frame, None, 0, 255, cv2.NORM_MINMAX)
        # depth_frame_normalized = np.uint8(depth_frame_normalized)
        # cv2.imshow("depth", depth_frame_normalized)

        # # depth image = (640,400)
        # # color image = (640,480)
        # # depth image의 아래 부분이 80정도 작은듯
        # cv2.waitKey(1)

        self.get_logger().info('sync')


class Image_Sender():
    def __init__(self):
        super().__init__()

        HOST = '192.168.0.107'
        # HOST = '127.0.0.1'
        PORT = 12346

        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client_socket.connect((HOST, PORT))
        # self.client_socket.settimeout(1)
        self.previous_depth = None
        self.previous_lidar = None
        
        

        self.ACK = True

    def msg_receive(self):
        while True:
            if node.rgb_image is not None:
                break
        while True:
            try:
                header = self.client_socket.recv(5)
                if len(header) < 5:
                    raise Exception
                
                message_type = header[0]
                data_size = int.from_bytes(header[1:], byteorder='big')

                data = b""
                while len(data) < data_size:
                    packet = self.client_socket.recv(4096)
                    if not packet:
                        break
                    data += packet
            except KeyboardInterrupt:
                self.client_socket.close()
            except Exception as e:
                print(e)
            if message_type == 0x04:    # 이미지 데이터 요청 수신
                self.image_send()
            elif message_type == 0x02:  # 특정 좌표 Depth 위치 요청 수신.
                data = data.decode()
                data = data.split('/')
                depth_point = self.previous_depth[int(data[0]), int(data[1])]
                
                send_data = str(depth_point).encode()
                send_data_size = len(send_data)
                send_message_type = 0x02
                send_header = send_message_type.to_bytes(1, byteorder='big') + send_data_size.to_bytes(4, byteorder='big')
                self.client_socket.sendall(send_header)
                print("Depth 정보 전송")
                self.client_socket.sendall(send_data)
                print("Depth 정보 전송 완료")
            elif message_type == 0x03:  # lx와 az 정보 수신.
                data = data.decode()
                data = data.split('/')

                lx = float(data[0])
                az = float(data[1])
                # lx : 0.3 일때 약 15cm 이동. 즉 lx가 0.3일때 값이 0.15가 나오게끔 해야함
                going = lx * 0.5
                # target_angle = az * 0.1
                target_angle = az
                target_index = int((target_angle - self.previous_lidar.angle_min) / self.previous_lidar.angle_increment)
                target_min = target_index - 175
                target_max = target_index + 175
                rng = range(target_min, target_max)
                danger = False
                count = 0
                for i in rng:
                    if 0 <= i <= 600:
                        if self.previous_lidar.ranges[i] < 0.25 + going:
                            count += 1
                if count > 10:
                    danger = True
                
                if danger:
                    send_data = b'y'
                else:
                    send_data = b'n'
                send_data_size = len(send_data)
                send_message_type = 0x03
                send_header = send_message_type.to_bytes(1, byteorder='big') + send_data_size.to_bytes(4, byteorder='big')
                self.client_socket.sendall(send_header)
                print("충돌 위험 정보 전송")
                self.client_socket.sendall(send_data)
                print("충돌 위험 정보 전송 완료")



                




    def image_send(self):
        if node.rgb_image is not None:
            rgb_image_cropped = node.rgb_image[40:440, :, :]
            _, rgb_image_cropped = cv2.imencode('.jpg', rgb_image_cropped, [cv2.IMWRITE_JPEG_QUALITY, 90])
            self.previous_depth = node.depth_image.copy()
            self.previous_lidar = node.lidar_data

            send_data = pickle.dumps(rgb_image_cropped)
            send_data_size = len(send_data)
            send_message_type = 0x01
            send_header = send_message_type.to_bytes(1, byteorder='big') + send_data_size.to_bytes(4, byteorder='big')
            self.client_socket.sendall(send_header)
            print("Color image 전송")
            self.client_socket.sendall(send_data)
            print("Color image 전송 완료")




if __name__=="__main__":
    rclpy.init(args=None)
    node = ImageListener()

    image_sender = Image_Sender()
    image_send_thread = threading.Thread(target=image_sender.msg_receive)
    image_send_thread.start()

    # time.sleep(3)
    # thread = threading.Thread(target=image_sender.depth_send)
    # thread.start()

    rclpy.spin(node)
    node.client_socket.close()
    node.destroy_node()
    rclpy.shutdown()