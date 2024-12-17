import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.callback_groups import ReentrantCallbackGroup
from i6robotics_control_msgs.action import Follow

import socket
import threading
import time
import pickle
import cv2
import numpy as np
import torch

from ultralytics import YOLO
from sam2.build_sam import build_sam2_camera_predictor

class FollowActionServer(Node):
    def __init__(self):
        super().__init__('follow_action_server')
        self._action_server = ActionServer(
            self,
            Follow,
            'follow',
            callback_group=ReentrantCallbackGroup(),
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback
        )

        # 이미지 통신 연결 및 receive 쓰레드 생성
        self.socket_connect = Socket_Connect()
        image_receive_thread = threading.Thread(target=self.socket_connect.data_receive)
        image_receive_thread.start()
        print("data_receive thread start")

        # Load a model
        self.model = YOLO("yolo11s.pt")
        
        # SAM2 모델 생성
        sam2_checkpoint = "./checkpoints/sam2_hiera_tiny.pt"
        model_cfg = "sam2_hiera_t.yaml"
        self.predictor = build_sam2_camera_predictor(model_cfg, sam2_checkpoint)

        time.sleep(2)

    async def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        
        # 동작.
        max_spin_speed = 0.5
        self.if_init = False
        target_bbox = [0, 0, 0, 0]
        lx = 0.0
        az = 0.0
        count = 0
        self.found_customer = False
        while True:
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                self.get_logger().info('cancel')
                return Follow.Result()
            self.socket_connect.new_frame = False
            print("ACK (이미지 요청) 전송")
            self.socket_connect.data_send(0x04, b"ACK")
            while True:
                if self.socket_connect.new_frame:
                    break

            frame = self.socket_connect.image_data.copy()
            height = frame.shape[0]
            width = frame.shape[1]
            
            # 바운딩 박스 선택
            if not self.found_customer:
                results = self.model.predict(source=frame, conf=0.25)
                predicted_frame = results[0].plot()
                cv2.imshow("Camera", predicted_frame)
                cv2.waitKey(1)

                human_bbox = []
                phone_bbox = []
                for result in results:
                    boxes = result.boxes
                    for box in boxes:
                        class_id = int(box.cls[0])
                        if class_id == 0: # 사람이면
                            x1, y1, x2, y2 = map(int, box.xyxy[0])  # 바운딩 박스 좌표
                            bbox = [x1, y1, x2, y2]
                            human_bbox.append(bbox)
                        if class_id == 67:
                            x1, y1, x2, y2 = map(int, box.xyxy[0])  # 바운딩 박스 좌표
                            bbox = [x1, y1, x2, y2]
                            phone_bbox=bbox

                target_index = None
                if len(phone_bbox) > 0:
                    phone_center_x = (phone_bbox[0] + phone_bbox[2]) / 2
                    phone_center_y = (phone_bbox[1] + phone_bbox[3]) / 2    
                    for i in range(len(human_bbox)):
                        if human_bbox[i][0] <= phone_center_x <= human_bbox[i][2] and human_bbox[i][1] <= phone_center_y <= human_bbox[i][3]:
                            target_index = i
                    if target_index is None:
                        continue
                    bbox = human_bbox[target_index] 
                    print(human_bbox[target_index])
                    found_customer = True
            else:
                # cv2.destroyAllWindows()
                self.socket_connect.stop = True
                with torch.inference_mode(), torch.autocast("cuda", dtype=torch.float16):
                    if not self.if_init:
                        self.if_init = True
                        self.predictor.load_first_frame(frame)
                        using_box = True 
                        ann_frame_idx = 0
                        ann_obj_id = (1)
                        labels = np.array([1], dtype=np.int32)
                        cv2.rectangle(frame, (bbox[0], bbox[1]), (bbox[2], bbox[3]), (255, 0, 0), 2)
                        bbox = np.array([[bbox[0], bbox[1]], [bbox[2], bbox[3]]], dtype=np.float32)
                        _, out_obj_ids, out_mask_logits = self.predictor.add_new_prompt(
                                frame_idx=ann_frame_idx, obj_id=ann_obj_id, bbox=bbox
                            )
                    else:
                        # cmd_vel_pub_node.stop = True
                        if count % 1 == 0:
                            print("SAM2 동작")
                            out_obj_ids, out_mask_logits = self.predictor.track(frame)
                            print("SAM2 완료")
                            prev_out_obj_ids = out_obj_ids
                            prev_out_mask_logits = out_mask_logits
                        else:
                            print("SAM2 패스")
                            out_obj_ids = prev_out_obj_ids
                            out_mask_logits = prev_out_mask_logits
                        count += 1

                        # cmd_vel_pub_node.stop = False
                        # print("SAM2 동작 끝")
                            
                        all_mask = np.zeros((height, width, 1), dtype=np.uint8)
                        print(len(out_obj_ids))
                        for i in range(0, len(out_obj_ids)):
                            out_mask = (out_mask_logits[i] > 0.0).permute(1, 2, 0).cpu().numpy().astype(np.uint8) * 255
                            all_mask = cv2.bitwise_or(all_mask, out_mask)
                            non_zero_indices = np.argwhere(all_mask)
                            if len(non_zero_indices) == 0:
                                target_bbox = [0, 0, 0, 0]
                            else:
                                y_min, x_min = non_zero_indices.min(axis=0).tolist()
                                y_max, x_max = non_zero_indices.max(axis=0).tolist()
                                target_bbox = [x_min, y_min, x_max - x_min, y_max - y_min]
                                
                                index = np.random.choice(len(non_zero_indices))
                                target_y = non_zero_indices[index][0]
                                target_x = non_zero_indices[index][1]
                                if target_y > height:
                                    target_y = height-1
                                if target_x > width:
                                    target_x = width-1
                                center_y, center_x = non_zero_indices.mean(axis=0).tolist()

                        all_mask = cv2.cvtColor(all_mask, cv2.COLOR_GRAY2RGB)
                        frame = cv2.addWeighted(frame, 1, all_mask, 0.5, 0)
                        frame = cv2.rectangle(frame, (target_bbox[0], target_bbox[1]), 
                                                (target_bbox[0] + target_bbox[2], 
                                                target_bbox[1] + target_bbox[3]), 
                                            (0, 255, 0), 2)

                        
                    
                    self.socket_connect.stop = False
                    
                    if target_bbox != [0, 0, 0, 0]:
                        print("Depth 정보 전송 요청")
                        self.socket_connect.data_send(0x02, f"{int(target_y)}/{int(target_x)}")
                        while True:
                            if self.socket_connect.new_depth == True:
                                break
                        # print("depth : ", self.socket_connect.depth)
                        self.socket_connect.new_depth = False
                                            
                        # 거리를 일정하게 유지
                        depth = self.socket_connect.depth
                        depth_threshold = 800
                        max_depth = 2500
                        max_depth_speed = 0.25
                        if depth == 0.0:
                            print("객체 거리 확보 실패")
                            # lx = 0.0
                        else:
                            if depth < depth_threshold:
                                print("거리가 가까움")
                                lx = 0.0
                            elif depth > depth_threshold:
                                print("거리가 멈. 앞으로 전진")
                                # lx = max_depth_speed * (depth/max_depth)
                                lx = max_depth_speed
                        if lx > max_depth_speed:
                            lx = max_depth_speed

                        angle_threshold = 120
                        # 방향을 일정하게 유지
                        if center_x < width/2.0 - angle_threshold:
                            print(f"중앙점보다 {abs(center_x-width/2.0)}왼쪽에 있음")
                            # az = max_spin_speed
                            az = max_spin_speed * (1 - center_x / 640)**2
                            # az = 0.3
                        elif center_x > width/2.0 + angle_threshold:
                            print(f"중앙점보다 {abs(center_x-width/2.0)}오른쪽에 있음")
                            # az = -max_spin_speed
                            az = -(max_spin_speed * (center_x/640)**2)
                            # az = -0.3
                        else:
                            az = 0.0
                            print("가운데에 있음")   
                        
                        # 이동 예정 위치를 바탕으로 충돌 위험 감지
                        self.socket_connect.data_send(0x03, f"{float(lx)}/{float(az)}")
                        while True:
                            if self.socket_connect.new_danger == True:
                                break
                        self.socket_connect.new_danger = False

                        # if self.socket_connect.danger:               # 충돌 위험으로 예상되면 정지
                        #     cmd_vel_pub_node.lx = -(max_depth_speed/2)
                        #     cmd_vel_pub_node.az = 0.0
                        # else:
                        #     if lx != 0.0 or az != 0.0:
                        #         cmd_vel_pub_node.lx = lx
                        #         cmd_vel_pub_node.az = az
                        #     else:
                        #         cmd_vel_pub_node.lx = 0.0
                        #         cmd_vel_pub_node.az = 0.0
                #     else:
                #         cmd_vel_pub_node.lx = 0.0
                #         if cmd_vel_pub_node.az > 0.0:
                #             cmd_vel_pub_node.az = max_spin_speed
                #         elif cmd_vel_pub_node.az < 0.0:
                #             cmd_vel_pub_node.az = -max_spin_speed
                #         else:
                #             cmd_vel_pub_node.az = max_spin_speed
                # cmd_vel_pub_node.move_forward()        
                
                cv2.imshow("Camera", frame)

                if cv2.waitKey(1) & 0xFF == ord("q"):
                    break  
             


        # feedback_msg = Follow.Feedback()
        # # feedback_msg.string








        # for i in range(2, goal_handle.request.order):
        #     feedback_msg.sequence.append(
        #         feedback_msg.sequence[i - 1] + feedback_msg.sequence[i - 2]
        #     )
        #     self.get_logger().info(f'Feedback: {feedback_msg.sequence}')
        #     goal_handle.publish_feedback(feedback_msg)
        #     # time.sleep(1.0)  # 1초 지연

        # goal_handle.succeed()

        # result = Fibonacci.Result()
        # result.sequence = feedback_msg.sequence
        # return result

    def goal_callback(self, goal_request):
        self.get_logger().info('Goal received.')
        return rclpy.action.GoalResponse.ACCEPT
    
    def cancel_callback(self, cancel_request):
        self.get_logger().info('Cancel request received.')
        return rclpy.action.CancelResponse.ACCEPT


class Socket_Connect():
    def __init__(self):
        super().__init__()

        HOST = '192.168.0.107'
        PORT = 12346

        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.bind((HOST, PORT))
        self.server_socket.listen(1)
        print("서버가 클라이언트를 기다립니다...")
        self.conn, addr = self.server_socket.accept()
        print(f"{addr} 연결됨")

        self.image_data = None
        self.count = 0
        self.stop = False

        self.depth = None
        
        self.danger = True

        self.new_frame = False
        self.new_depth = False
        self.new_danger = False

        
    def data_receive(self):
        while True:
            # if self.stop:
            #     time.sleep(0.01)
            #     continue
            try:
                header = self.conn.recv(5)
                if len(header) < 5:
                    raise Exception

                message_type = header[0]
                data_size = int.from_bytes(header[1:], byteorder='big')

                print("Data 읽기 시작")
                data = b""
                while len(data) < data_size:
                    # packet = self.conn.recv(4096)
                    packet = self.conn.recv(data_size)
                    if not packet:
                        break
                    data += packet
                print("Data 읽기 끝")
            except KeyboardInterrupt:
                self.conn.close()
                self.server_socket.close()
            except Exception as e:
                print(e)
            
            if message_type == 0x01:    # 이미지 데이터 수신
                data = pickle.loads(data)
                self.image_data = cv2.imdecode(data, cv2.IMREAD_COLOR)
                self.count +=1
                print("image data 수신 완료", self.count)
                self.new_frame = True
            elif message_type == 0x02:  # Depth 정보 수신
                self.depth = float(data.decode())
                self.new_depth = True
                print("Depth 정보 수신 완료. Depth 값 : ", self.depth)
            elif message_type == 0x03:  # 충돌 감지 정보 수신
                if data.decode() == 'y':
                    self.danger = True
                else:
                    self.danger = False
                self.new_danger = True
                print("충돌 위험 감지 정보 수신 완료. 위험 여부 : ", self.danger)




    def data_send(self, send_message_type, send_data):
        if send_message_type == 0x04:       # 간단한 상태 메시지 전송. ex) ACK
            send_data_size = len(send_data)
            send_header = send_message_type.to_bytes(1, byteorder='big') + send_data_size.to_bytes(4, byteorder='big')
            self.conn.sendall(send_header)
            self.conn.sendall(send_data)
        elif send_message_type == 0x02:     # 문자열 전송. ex) Depth 정보 요청. "target_y/target_x"
            send_data = send_data.encode()
            send_data_size = len(send_data)
            send_header = send_message_type.to_bytes(1, byteorder='big') + send_data_size.to_bytes(4, byteorder='big')
            self.conn.sendall(send_header)
            self.conn.sendall(send_data)
        elif send_message_type == 0x03:     # 문자열 전송. ex) 충돌 감지 정보 요청. "lx/az"
            send_data = send_data.encode()
            send_data_size = len(send_data)
            send_header = send_message_type.to_bytes(1, byteorder='big') + send_data_size.to_bytes(4, byteorder='big')
            self.conn.sendall(send_header)
            self.conn.sendall(send_data)



def main(args=None):
    rclpy.init(args=args)
    node = FollowActionServer()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
