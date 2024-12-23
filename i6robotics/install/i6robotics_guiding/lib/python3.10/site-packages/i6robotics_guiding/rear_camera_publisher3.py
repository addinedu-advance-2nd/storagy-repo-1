#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import cv2
import mediapipe as mp
import numpy as np


class TorsoControlNode(Node):
    def __init__(self):
        super().__init__('torso_control_node')

        # ROS2 Publisher
        self.publisher_ = self.create_publisher(String, 'control_command', 10)

        # MediaPipe Pose 초기화
        self.mp_pose = mp.solutions.pose
        self.pose = self.mp_pose.Pose(min_detection_confidence=0.5, min_tracking_confidence=0.5)

        # 웹캠 초기화
        self.cap = cv2.VideoCapture(0)

        # 상체 크기 기준 (픽셀 단위)
        self.torso_length_threshold = 260

        self.previous_message = None  # 이전에 발행된 메시지 저장
        self.timer = self.create_timer(0.1, self.process_frame)  # 0.1초마다 실행

    def process_frame(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().error("Failed to read frame from webcam")
            return

        # RGB 변환
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # Pose 모델로 자세 추출
        results = self.pose.process(rgb_frame)

        msg = String()
        if results.pose_landmarks:

            mp.solutions.drawing_utils.draw_landmarks(
                frame, results.pose_landmarks, self.mp_pose.POSE_CONNECTIONS
            )        

            # 주요 키포인트 좌표 추출
            landmarks = results.pose_landmarks.landmark
            left_shoulder = landmarks[self.mp_pose.PoseLandmark.LEFT_SHOULDER.value]
            right_hip = landmarks[self.mp_pose.PoseLandmark.RIGHT_HIP.value]

            # 픽셀 좌표로 변환
            left_shoulder_point = (int(left_shoulder.x * frame.shape[1]), int(left_shoulder.y * frame.shape[0]))
            right_hip_point = (int(right_hip.x * frame.shape[1]), int(right_hip.y * frame.shape[0]))

            # 몸통 길이 계산 (픽셀 단위)
            torso_length = np.linalg.norm(np.array(left_shoulder_point) - np.array(right_hip_point))

            # 길이 기준 판단
            if torso_length > self.torso_length_threshold:
                msg.data = "resume"
                message = "Torso size OK"
                color = (0, 255, 0)  # 초록색
            else:
                msg.data = "pause"
                message = "Torso too small"
                color = (0, 0, 255)  # 빨간색

            # 메시지와 키포인트 시각화
            cv2.putText(frame, message, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, color, 2)
            cv2.circle(frame, left_shoulder_point, 5, (0, 255, 255), -1)  # 어깨 점 표시
            cv2.circle(frame, right_hip_point, 5, (255, 0, 255), -1)      # 엉덩이 점 표시
        else:
            # 아무것도 인식되지 않은 경우
            msg.data = "pause"
            message = "No pose detected"
            color = (0, 0, 255)  # 빨간색
            cv2.putText(frame, message, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, color, 2)

        # 메시지 발행 (중복 메시지 방지)
        if msg.data != self.previous_message:
            self.publisher_.publish(msg)
            self.get_logger().info(f"Publishing: {msg.data}")
            self.previous_message = msg.data

        # 화면 출력
        cv2.imshow("Torso Length Detection", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            rclpy.shutdown()

    def destroy_node(self):
        self.cap.release()
        cv2.destroyAllWindows()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = TorsoControlNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
