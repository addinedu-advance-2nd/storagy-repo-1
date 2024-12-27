import cv2
from pyzbar.pyzbar import decode
import rclpy
from rclpy.node import Node
from std_msgs.msg import String, Int32
import mediapipe as mp
import numpy as np
from std_srvs.srv import Trigger
from std_srvs.srv import SetBool
from ultralytics import YOLO

class TorsoAndQRCodeNode(Node):
    def __init__(self):
        super().__init__('torso_and_qr_code_node')

        # ROS2 Publishers
        self.torso_publisher = self.create_publisher(String, 'control_command', 10)
        self.qr_publisher = self.create_publisher(Int32, 'qr_code', 10)

        # MediaPipe Pose 초기화
        self.mp_pose = mp.solutions.pose
        self.pose = self.mp_pose.Pose(min_detection_confidence=0.5, min_tracking_confidence=0.5)

        # Services for toggling
        self.torso_toggle_service = self.create_service(
            SetBool, 'toggle_control_command', self.handle_torso_toggle_request)
        self.qr_toggle_service = self.create_service(
            SetBool, 'toggle_qr_command', self.handle_qr_toggle_request)
        # Webcam initialization
        self.cap = cv2.VideoCapture(0)
        # self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 960)
        # self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)

        # Load a model
        self.model = YOLO("yolo11m.pt")

        # Thresholds and state variables
        self.torso_length_threshold = 300
        self.is_torso_publishing = False
        self.is_qr_publishing = True
        self.previous_torso_message = None

        # QR Code stability
        self.stable_threshold = 3
        self.qr_code_counts = {}

        # Timer for processing frames
        self.timer = self.create_timer(0.1, self.process_frame)

    def handle_torso_toggle_request(self, request, response):
        self.is_torso_publishing = request.data
        state = "started" if self.is_torso_publishing else "stopped"
        response.success = True
        response.message = f"Torso control command publishing {state}"

            # 토픽 퍼블리싱 시작 시 'pause' 메시지 발행
        if self.is_torso_publishing:
            initial_torso_msg = String()
            initial_torso_msg.data = "pause"
            self.torso_publisher.publish(initial_torso_msg)
            self.previous_torso_message = "pause"  # 상태 초기화
            self.get_logger().info("Published initial torso command: pause")

        self.get_logger().info(response.message)
        return response

    def handle_qr_toggle_request(self, request, response):
        self.is_qr_publishing = request.data
        state = "started" if self.is_qr_publishing else "stopped"
        response.success = True
        response.message = f"QR code publishing {state}"
        self.get_logger().info(response.message)
        return response

    def publish_qr_code(self, qr_code):
        msg = Int32()
        msg.data = qr_code
        self.qr_publisher.publish(msg)
        self.get_logger().info(f"Published QR Code: {qr_code}")

    def update_qr_code_states(self, current_qr_codes):
        for qr_code in current_qr_codes:
            if qr_code not in self.qr_code_counts:
                self.qr_code_counts[qr_code] = 1
            else:
                self.qr_code_counts[qr_code] += 1

            if self.qr_code_counts[qr_code] == self.stable_threshold:
                self.publish_qr_code(qr_code)

        for qr_code in list(self.qr_code_counts.keys()):
            if qr_code not in current_qr_codes:
                self.qr_code_counts.pop(qr_code, None)

    def process_frame(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().error("Failed to read frame from webcam")
            return

        # Copy frame for QR Code processing
        qr_frame = frame.copy()

        # Torso Detection
        if self.is_torso_publishing:
            # # 사람 인식 부분
            # results = self.model.predict(source=frame, conf=0.5)
            # predicted_frame = results[0].plot()

            # # cv2.imshow("YOLO image", predicted_frame)
            # human_bbox = []
            # biggest_index = -1
            # biggest_bbox_size = 0
            # count = 0
            # for result in results:
            #     boxes = result.boxes
            #     for box in boxes:
            #         class_id = int(box.cls[0])
            #         if class_id == 0: # 사람이면
            #             x1, y1, x2, y2 = map(int, box.xyxy[0])  # 바운딩 박스 좌표
            #             bbox = [x1, y1, x2, y2]
            #             print(bbox)
            #             human_bbox.append(bbox)
            #             bbox_size = (x2-x1) * (y2-y1)
            #             if bbox_size > 50 and bbox_size > biggest_bbox_size:
            #                 biggest_bbox_size = bbox_size
            #                 biggest_index = count
            #                 count += 1

            # if biggest_index != -1:
            #     frame = frame[human_bbox[biggest_index][1]:human_bbox[biggest_index][3],
            #                   human_bbox[biggest_index][0]:human_bbox[biggest_index][2],:]
            # print(frame.shape)
            rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            results = self.pose.process(rgb_frame)
    
            torso_msg = String()
            if results.pose_landmarks:
                mp.solutions.drawing_utils.draw_landmarks(
                    frame, results.pose_landmarks, self.mp_pose.POSE_CONNECTIONS
                )

                landmarks = results.pose_landmarks.landmark
                left_shoulder = landmarks[self.mp_pose.PoseLandmark.LEFT_SHOULDER.value]
                right_hip = landmarks[self.mp_pose.PoseLandmark.RIGHT_HIP.value]

                left_shoulder_point = (int(left_shoulder.x * frame.shape[1]), int(left_shoulder.y * frame.shape[0]))
                right_hip_point = (int(right_hip.x * frame.shape[1]), int(right_hip.y * frame.shape[0]))

                torso_length = np.linalg.norm(np.array(left_shoulder_point) - np.array(right_hip_point))

                if torso_length > self.torso_length_threshold:
                    torso_msg.data = "resume"
                    message = "Torso size OK"
                    color = (0, 255, 0)
                else:
                    torso_msg.data = "pause"
                    message = "Torso too small"
                    color = (0, 0, 255)

                cv2.putText(frame, message, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, color, 2)
                cv2.circle(frame, left_shoulder_point, 5, (0, 255, 255), -1)
                cv2.circle(frame, right_hip_point, 5, (255, 0, 255), -1)

            else:
                torso_msg.data = "pause"

            if torso_msg.data != self.previous_torso_message:
                self.torso_publisher.publish(torso_msg)
                self.get_logger().info(f"Published torso command: {torso_msg.data}")
                self.previous_torso_message = torso_msg.data

        # QR Code Detection
        if self.is_qr_publishing:
            decoded_objects = decode(qr_frame)
            current_qr_codes = set()

            for obj in decoded_objects:
                qr_data = obj.data.decode("utf-8")
                if qr_data.isdigit():
                    qr_code = int(qr_data)
                    current_qr_codes.add(qr_code)

                    points = obj.polygon
                    if len(points) == 4:
                        pts = [(point.x, point.y) for point in points]
                        pts = np.array(pts, dtype=np.int32)
                        cv2.polylines(frame, [pts], isClosed=True, color=(0, 255, 0), thickness=2)

                    cv2.putText(frame, qr_data, (obj.rect.left, obj.rect.top - 10),
                                cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

            self.update_qr_code_states(current_qr_codes)

        # Display frame
        # cv2.imshow("Torso and QR Code Detection", frame)
        # if cv2.waitKey(1) & 0xFF == ord('q'):
        #     rclpy.shutdown()

    def destroy_node(self):
        self.cap.release()
        cv2.destroyAllWindows()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = TorsoAndQRCodeNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
