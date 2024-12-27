import sys
import rclpy
import os
from rclpy.node import Node
from rclpy.action import ActionClient
from nav2_msgs.action import NavigateToPose

from action_msgs.msg import GoalStatusArray

from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QVBoxLayout, QWidget, QLabel, QScrollArea
from PyQt5.QtWidgets import QToolButton, QHBoxLayout, QProgressBar, QSpacerItem, QSizePolicy, QGridLayout
from PyQt5.QtCore import Qt, QObject, pyqtSignal, QTimer, QThread
from PyQt5.QtGui import QIcon, QPixmap
from playsound import playsound
from geometry_msgs.msg import Pose, Twist
from i6robotics_control_msgs.srv import Order
from std_srvs.srv import Trigger
from std_srvs.srv import SetBool
from std_msgs.msg import Int32, Bool  # Int32 메시지 타입 임포트
from threading import Event
import time

class OrderClient(Node):
    def __init__(self):
        super().__init__('order_client')

        

        self.client = self.create_client(Order, 'order')
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')
        self.req = Order.Request()

        self.toggle_client = self.create_client(SetBool, 'toggle_control_command')
        while not self.toggle_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Toggle service not available, waiting...')
        
        self.toggle_qr_client = self.create_client(SetBool, 'toggle_qr_command')
        while not self.toggle_qr_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Toggle service not available, waiting...')

        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.msg = Twist()
        self.msg.linear.x = 0.0
        self.msg.linear.y = 0.0
        self.msg.linear.z = 0.0
        self.msg.angular.x = 0.0
        self.msg.angular.y = 0.0
        self.msg.angular.z = 0.0

        # NavigateToPose 액션 클라이언트 초기화
        self.nav_to_pose_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self.goal_status = None
        self.event = Event()

        self.create_subscription(
            GoalStatusArray,
            '/navigate_to_pose/_action/status',
            self.status_callback,
            10
        )

        self.create_subscription(
            Bool,
            'follow_state',
            self.follow_state_callback,
            10
        )
        
        self.qr_mapping = {
            1: "칙촉",
            2: "쿠크다스",
            3: "초코",
            4: "콜라",
            5: "상추"
        }
    


    def send_request(self, order_type, goal_pose=Pose()):
        self.req.order = order_type
        self.req.goal_pose = goal_pose
        self.future = self.client.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

    
    def set_control_command(self, enable: bool):
        """Set control command: True to enable, False to disable."""
        time.sleep(4.0)
        toggle_req = SetBool.Request()
        toggle_req.data = enable
        toggle_future = self.toggle_client.call_async(toggle_req)
        rclpy.spin_until_future_complete(self, toggle_future)
        return toggle_future.result()
    
    def set_qr_command(self, enable: bool):
        """Set QR code command: True to enable, False to disable."""
        toggle_qr_req = SetBool.Request()
        toggle_qr_req.data = enable
        toggle_qr_future = self.toggle_qr_client.call_async(toggle_qr_req)
        rclpy.spin_until_future_complete(self, toggle_qr_future)
        return toggle_qr_future.result()

    def status_callback(self, msg):
        """상태 메시지 콜백"""
        if msg.status_list:
            self.goal_status = msg.status_list[-1].status
            if self.goal_status == 4:  # SUCCEEDED 상태
                self.get_logger().info("NavigateToPose 성공!")
                self.event.set()

    def follow_state_callback(self, msg):
        """팔로우 고객 인식 메시지 콜백"""
        if msg.data == True:
            window.label.setText("쇼핑 메이트")
            self.get_logger().info("첫 고객 인식 성공!")

    def check_navigation_status(self):
        """NavigateToPose 액션 서버에서 SUCCEEDED 상태 확인"""
        self.goal_status = None  # 상태 초기화
        self.event.clear()

        # 이벤트 대기 (타임아웃 설정 가능)
        self.event.wait(timeout=30) # 최대 30초 대기
        return self.goal_status == 4
    
class ROS2Worker(QThread):
    qr_code_signal = pyqtSignal(int)  # QR 코드 데이터를 UI로 전달하는 Signal

    def __init__(self, order_client):
        super().__init__()
        self.order_client = order_client
        self.running = True  # ROS2Worker 상태 관리 플래그

        # QR 코드 구독 설정
        self.order_client.create_subscription(
            Int32,
            '/qr_code',
            self.qr_code_callback,
            10
        )
    def run(self):
        """ROS2 노드 실행"""
        while self.running:
            try:
                rclpy.spin_once(self.order_client, timeout_sec=0.1)
            except Exception as e:
                print(f"ROS2Worker error: {e}")
                break

    def pause(self):
        """ROS2Worker 동작 일시 중단"""
        self.running = False

    def resume(self):
        """ROS2Worker 동작 재개"""
        self.running = True


    def qr_code_callback(self, msg):
        """QR 코드 메시지를 수신하여 처리"""
        self.qr_code_status = msg.data
        self.qr_code_signal.emit(self.qr_code_status)  # Signal로 UI에 전달



class ROS2UI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("i6robotics Cart UI")
        self.setGeometry(0, 0, 800, 1000)

        self.setFixedSize(800, 1000)
        self.cart = []
        
        self.setStyleSheet("""
            QMainWindow {
                background-color: #F5F5F5;
            }
            QPushButton {
                background-color: #4CAF50;
                color: white;
                border-radius: 15px;
                padding: 20px; /* 버튼 내부 여백을 크게 */
                font-size: 42px; /* 버튼 글자 크기 3배 확대 */
                font-weight: bold;
            }
            QPushButton:hover {
                background-color: #45A049;
            }
            QLabel {
                font-size: 48px; /* 라벨 글자 크기 3배 확대 */
                font-weight: bold;
                color: #333333;
            }
            QScrollArea {
                border: none;
            }
            QScrollBar:vertical {
                background: #DDDDDD;
                width: 15px;
                margin: 2px 2px 2px 2px;
            }
            QScrollBar::handle:vertical {
                background: #4CAF50;
                border-radius: 7px;
            }
            QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
                background: none;
            }
        """)

        # ROS2 서비스 클라이언트 노드
        rclpy.init()
        self.order_client = OrderClient()
        self.ros2_worker = ROS2Worker(self.order_client)
        self.ros2_worker.qr_code_signal.connect(self.handle_qr_code)
        self.ros2_worker.start()

        self.first_screen = True

        # 메인 화면 초기화
        self.init_main_screen()

        self.label.setText("QR코드를 인식시켜주세요")

        # 카테고리 및 상품 데이터
        self.categories = {
            "과자": [
                ("칙촉", 2.65, -2.17, 0.0, 0.999, 3000, "images/choco.jpg"), ("쿠크다스", 2.8, -1.6, 0.01, 0.67, 3000, "images/couque_cake.jpg"), ("치즈과자", 2.8, -1.6, 0.01, 0.67, 3000, "images/choco.jpg"),
                ("버터과자", 2.8, -1.6, 0.01, 0.67, 3000, "images/choco.jpg"), ("허니과자", 2.8, -1.6, 0.01, 0.67, 3000, "images/choco.jpg"), ("오트밀과자", 2.8, -1.6, 0.01, 0.67, 3000, "images/choco.jpg"),
                ("초코칩과자", 2.8, -1.6, 0.01, 0.67, 3000, "images/choco.jpg"), ("크래커", 2.8, -1.6, 0.01, 0.67, 3000, "images/choco.jpg"), ("비스킷", 2.8, -1.6, 0.01, 0.67, 3000, "images/choco.jpg"), ("피넛과자", 2.8, -1.6, 0.67, 0.01, 3000, "images/choco.jpg")
            ],
            "라면": [
                ("신라면", 1.43, -2.26, 0.01, 0.99, 1000, "images/ramen.jpg"), ("진라면", 1.43, -2.26, 0.01, 0.99, 1000, "images/ramen.jpg"), ("불닭볶음면", 1.43, -2.26, 0.01, 0.99, 1000, "images/ramen.jpg"),
                ("너구리", 1.43, -2.26, 0.01, 0.99, 1000, "images/ramen.jpg"), ("안성탕면", 1.43, -2.26, 0.01, 0.99, 1000, "images/ramen.jpg"), ("삼양라면", 1.43, -2.26, 0.01, 0.99, 1000, "images/ramen.jpg"),
                ("짜파게티", 1.43, -2.26, 0.01, 0.99, 1000, "images/ramen.jpg"), ("틈새라면", 1.43, -2.26, 0.01, 0.99, 1000, "images/ramen.jpg"), ("왕뚜껑", 1.43, -2.26, 0.01, 0.99, 1000, "images/ramen.jpg"), ("컵누들", 1.43, -2.26, 0.01, 0.99, 1000, "images/ramen.jpg")
            ],
            "아이스크림": [
                ("초코", 2.57, -0.14, 0.01, 0.73, 3000, "images/icecream.jpg"), ("바닐라", 2.57, -0.14, 0.01, 0.73, 3000, "images/icecream.jpg"), ("딸기", 2.57, -0.14, 0.01, 0.73, 3000, "images/icecream.jpg"),
                ("녹차", 2.57, -0.14, 0.01, 0.73, 3000, "images/icecream.jpg"), ("민트초코", 2.57, -0.14, 0.01, 0.73, 3000, "images/icecream.jpg"), ("쿠키앤크림", 2.57, -0.14, 0.01, 0.73, 3000, "images/icecream.jpg"),
                ("망고", 2.57, -0.14, 0.01, 0.73, 3000, "images/icecream.jpg"), ("블루베리", 2.57, -0.14, 0.01, 0.73, 3000, "images/icecream.jpg"), ("오레오", 2.57, -0.14, 0.01, 0.73, 3000, "images/icecream.jpg"), ("레몬", 2.57, -0.14, 0.73, 0.01, 3000, "images/icecream.jpg")
            ],
            "음료수": [
                ("콜라", 1.87, -2.19, 0.01, 0.01, 2000, "images/drink.jpg"), ("사이다", 1.87, -2.19, 0.01, 0.01, 1500, "images/drink.jpg"), ("오렌지주스", 1.87, -2.19, 0.01, 0.01, 1500, "images/drink.jpg"),
                ("커피", 1.87, -2.19, 0.01, 0.01, 1000, "images/drink.jpg"), ("녹차", 1.87, -2.19, 0.01, 0.01, 1500, "images/drink.jpg"), ("홍차", 1.87, -2.19, 0.01, 0.01, 1500, "images/drink.jpg"),
                ("에너지드링크", 1.87, -2.19, 0.01, 0.01, 2000, "images/drink.jpg"), ("스무디", 1.87, -2.19, 0.01, 0.01, 3000, "images/drink.jpg"), ("탄산수", 1.87, -2.19, 0.01, 0.01, 1500, "images/drink.jpg"), ("우유", 1.87, -2.19, 0.01, 0.01, 1500, "images/drink.jpg")
            ],
            "야채": [
                ("상추", 1.87, -2.19, 0.01, 0.01, 2000, "images/vegetable.jpg"), ("당근", 1.87, -2.19, 0.01, 0.01, 2000, "images/vegetable.jpg"), ("오이", 1.87, -2.19, 0.01, 0.01, 2000, "images/vegetable.jpg"),
                ("양파", 1.87, -2.19, 0.01, 0.01, 2000, "images/vegetable.jpg"), ("고추", 1.87, -2.19, 0.01, 0.01, 2000, "images/vegetable.jpg"), ("감자", 1.87, -2.19, 0.01, 0.01, 2000, "images/vegetable.jpg"),
                ("호박", 1.87, -2.19, 0.01, 0.01, 2000, "images/vegetable.jpg"), ("버섯", 1.87, -2.19, 0.01, 0.01, 2000, "images/vegetable.jpg"), ("배추", 1.87, -2.19, 0.01, 0.01, 2000, "images/vegetable.jpg"), ("무", 1.87, -2.19, 0.01, 0.01, 2000, "images/vegetable.jpg")
            ]
        }
    def closeEvent(self, event):
        """UI 종료 이벤트"""
        self.ros2_worker.running = False  # ROS2Worker 실행 중단
        self.ros2_worker.wait()  # 스레드 종료 대기
        rclpy.shutdown()  # ROS2 시스템 종료
        super().closeEvent(event)

    def handle_qr_code(self, qr_code):
        """Signal로 전달된 QR 코드를 처리"""
        item_name = self.order_client.qr_mapping.get(qr_code, None)
        if item_name:
            self.add_to_cart(item_name)
        else:
            self.statusBar().showMessage(f"QR 코드 {qr_code}에 해당하는 항목이 없습니다!")

    def init_main_screen(self):
        self.main_widget = QWidget()
        self.main_layout = QVBoxLayout()

        self.label = QLabel("쇼핑 메이트")
        self.label.setAlignment(Qt.AlignCenter)
        self.main_layout.addWidget(self.label)    


        # 상단 레이아웃에 장바구니 버튼 추가
        top_layout = QHBoxLayout()
        cart_btn = QToolButton()
        cart_btn.setIcon(QIcon.fromTheme("user-trash"))  # 장바구니 아이콘 설정
        cart_btn.setText("🛒")
        cart_btn.setStyleSheet("""
            QToolButton {
                font-size: 60px;
                background: none;
                border: none;
                color: #333333;
            }
            QToolButton:hover {
                color: #4CAF50;
            }
        """)
        cart_btn.clicked.connect(self.show_cart)
        top_layout.addStretch()
        top_layout.addWidget(cart_btn)

        self.main_layout.addLayout(top_layout)


        self.follow_me_btn = QPushButton("따라와")
        self.follow_me_btn.clicked.connect(self.send_follow_request)
        self.main_layout.addWidget(self.follow_me_btn)

        self.search_btn = QPushButton("상품 찾기")
        self.search_btn.clicked.connect(self.show_categories)
        self.main_layout.addWidget(self.search_btn)

        self.pay_btn = QPushButton("결제")
        self.pay_btn.setStyleSheet("font-size: 36px; padding: 15px;")
        self.pay_btn.clicked.connect(self.checkout)
        self.main_layout.addWidget(self.pay_btn)

        self.main_widget.setLayout(self.main_layout)
        self.setCentralWidget(self.main_widget)

    

    def show_cart(self):
        """장바구니 화면을 표시"""
        self.cart_widget = QWidget()
        self.cart_layout = QVBoxLayout()

        # 뒤로가기 버튼
        back_btn = QToolButton()
        back_btn.setText("←")
        back_btn.setStyleSheet("""
            QToolButton {
                font-size: 24px;
                background-color: #F5F5F5;
                border: none;
                color: #4CAF50;
            }
            QToolButton:hover {
                color: #388E3C;
            }
        """)
        back_btn.clicked.connect(self.init_main_screen)
        self.cart_layout.addWidget(back_btn)

        self.cart_label = QLabel("장바구니")
        self.cart_label.setAlignment(Qt.AlignCenter)
        self.cart_label.setStyleSheet("font-size: 40px; font-weight: bold; color: #333333;")
        self.cart_layout.addWidget(self.cart_label)

        # 상품별 개수 계산
        item_counts = {}
        for item in self.cart:
            if item in item_counts:
                item_counts[item] += 1
            else:
                item_counts[item] = 1

        # 표 형태 레이아웃
        grid_layout = QGridLayout()

        # 헤더 추가
        headers = ["", "상품명", "수량", "가격"]
        for col, header in enumerate(headers):
            header_label = QLabel(header)
            header_label.setStyleSheet("font-size: 20px; font-weight: bold; background-color: #E0E0E0; padding: 5px; border-radius: 5px;")
            grid_layout.addWidget(header_label, 0, col)

        # 상품 목록 추가
        total_price = 0
        row = 1
        for item, count in item_counts.items():
            # 상품 정보 가져오기
            price = next((prod[5] for cat in self.categories.values() for prod in cat if prod[0] == item), 0)
            image_path = next((prod[6] for cat in self.categories.values() for prod in cat if prod[0] == item), None)
            total_price += price * count

            # 이미지 추가
            img_label = QLabel()
            pixmap = QPixmap(image_path)
            img_label.setPixmap(pixmap.scaled(100, 100, Qt.KeepAspectRatio))
            img_label.setStyleSheet("border: 1px solid #DDD; border-radius: 5px; padding: 2px;")
            grid_layout.addWidget(img_label, row, 0)

            # 상품명 추가
            name_label = QLabel(item)
            name_label.setStyleSheet("font-size: 18px; color: #333333;")
            grid_layout.addWidget(name_label, row, 1)

            # 수량 추가
            count_label = QLabel(f"{count}개")
            count_label.setStyleSheet("font-size: 18px; color: #333333;")
            grid_layout.addWidget(count_label, row, 2)

            # 가격 추가
            price_label = QLabel(f"{price * count}원")
            price_label.setStyleSheet("font-size: 18px; color: #333333;")
            grid_layout.addWidget(price_label, row, 3)

            row += 1

        # 상품 목록 레이아웃 추가
        grid_widget = QWidget()
        grid_widget.setLayout(grid_layout)
        grid_widget.setStyleSheet("background-color: #F9F9F9; padding: 10px; border-radius: 10px;")
        self.cart_layout.addWidget(grid_widget)

        # 총 가격 표시
        total_price_label = QLabel(f"총 가격: {total_price}원")
        total_price_label.setStyleSheet("font-size: 24px; font-weight: bold; color: #4CAF50; margin-top: 10px;")
        self.cart_layout.addWidget(total_price_label)

        # 결제 버튼 추가
        checkout_btn = QPushButton("결제하기")
        checkout_btn.setStyleSheet("""
            QPushButton {
                background-color: #4CAF50;
                color: white;
                border-radius: 15px;
                padding: 20px;
                font-size: 32px;
            }
            QPushButton:hover {
                background-color: #388E3C;
            }
        """)
        checkout_btn.clicked.connect(lambda: self.checkout(total_price))  # 총 가격 전달
        self.cart_layout.addWidget(checkout_btn)

        self.cart_widget.setLayout(self.cart_layout)
        self.setCentralWidget(self.cart_widget)


    def checkout(self, total_price):
        """결제 기능"""
        if not self.cart:
            self.statusBar().showMessage("장바구니가 비어 있습니다!")
            return
        # 결제 완료 화면 표시
        self.cart.clear()  # 장바구니 비우기
        self.show_payment_success_screen(total_price)

    def show_payment_success_screen(self, total_price):
        """결제 완료 화면"""
        success_widget = QWidget()
        success_layout = QVBoxLayout()

        # 완료 메시지
        success_label = QLabel(f"결제가 완료되었습니다!\n총 금액: {total_price}원")
        success_label.setAlignment(Qt.AlignCenter)
        success_label.setStyleSheet("font-size: 40px; font-weight: bold; color: #4CAF50;")
        success_layout.addWidget(success_label)

        # 카트 반납 버튼
        return_cart_btn = QPushButton("카트 반납")
        return_cart_btn.setStyleSheet("""
            QPushButton {
                background-color: #FF4444;
                color: white;
                border-radius: 15px;
                padding: 20px;
                font-size: 32px;
            }
            QPushButton:hover {
                background-color: #CC0000;
            }
        """)
        # 두 메소드를 순차적으로 실행
        return_cart_btn.clicked.connect(lambda: (self.send_order_station(), self.init_main_screen()))
        success_layout.addWidget(return_cart_btn)

        # 메인 화면으로 돌아가기 버튼
        back_btn = QPushButton("메인 화면으로")
        back_btn.setStyleSheet("""
            QPushButton {
                background-color: #4CAF50;
                color: white;
                border-radius: 15px;
                padding: 20px;
                font-size: 32px;
            }
            QPushButton:hover {
                background-color: #45A049;
            }
        """)
        back_btn.clicked.connect(lambda: (self.ros2_worker.resume(), self.init_main_screen()))
        success_layout.addWidget(back_btn)
        success_widget.setLayout(success_layout)
        self.setCentralWidget(success_widget)

    def send_follow_request(self):
        """자율주행 시작 요청 및 UI 업데이트"""
        result = self.order_client.send_request('follow_on', Pose())
        if result.accepted:
            self.statusBar().showMessage("자율주행 시작 성공!")

            # '따라와' 버튼 숨기기
            self.follow_me_btn.hide()

            self.label.setText("고객님을 따라가는 중입니다...")
            self.label.setAlignment(Qt.AlignCenter)
            
            self.show_autonomous_controls()
        else:
            self.statusBar().showMessage("따라와: 서비스 요청 실패!")

    def show_autonomous_controls(self):
        """자율주행 중 UI 추가: 진행바,  중단 버튼"""
        
    # '중단' 버튼 생성 및 추가
        self.stop_btn = QPushButton("중단")
        self.stop_btn.setStyleSheet("""
            QPushButton {
                background-color: #FF4444;
                color: white;
                border: 2px solid #CC0000;
                border-radius: 10px;
                padding: 20px;
                font-size: 42px;  /* 버튼 글자 크기와 스타일 동일하게 */
                font-weight: bold;
            }
            QPushButton:hover {
                background-color: #CC0000;
            }
            QPushButton:pressed {
                background-color: #990000;
            }
        """)

        self.stop_btn.clicked.connect(self.stop_autonomous_driving)
        
        # 기존 '따라와' 버튼 위치에 '자율주행 중단' 버튼 추가
        self.main_layout.insertWidget(self.main_layout.indexOf(self.follow_me_btn), self.stop_btn)
    

        # 진행 상태바 추가
        self.progress_bar = QProgressBar()
        self.progress_bar.setRange(0, 0)  # 무한 진행 상태
        self.progress_bar.setStyleSheet("""
            QProgressBar {
                border: 2px solid #4CAF50;
                border-radius: 10px;
                background-color: #E0E0E0;
                height: 30px;
            }
            QProgressBar::chunk {
                background-color: #4CAF50;
                border-radius: 10px;
                margin: 2px;
            }
        """)

        # 기존 메인 레이아웃에 동적 요소 추가
        #self.main_layout.insertWidget(0, self.stop_btn, alignment=Qt.AlignLeft)  # 중단 버튼을 상단에 추가
        self.main_layout.insertWidget(0, self.progress_bar)  # 진행 상태바를 두 번째에 추가

    def stop_autonomous_driving(self):
        """자율주행 중단 요청 및 UI 복원"""
        result = self.order_client.send_request('follow_off', Pose())
        if result.accepted:
            self.statusBar().showMessage("자율주행이 중단되었습니다.")

            # '자율주행 중단' 버튼 제거
            self.main_layout.removeWidget(self.stop_btn)
            self.stop_btn.deleteLater()
            # 진행 상태바 제거
            self.main_layout.removeWidget(self.progress_bar)
            self.progress_bar.deleteLater()

            # '따라와' 버튼 다시 표시
            self.follow_me_btn.show()

            self.label.setText("쇼핑 메이트")
            self.label.setAlignment(Qt.AlignCenter)
        else:
            self.statusBar().showMessage("자율주행 중단 실패!")

    def show_categories(self):
        result = self.order_client.send_request('follow_off', Pose())
        if result.accepted:
            self.statusBar().showMessage("자율주행이 중단되었습니다.")

        self.category_widget = QWidget()
        self.category_layout = QVBoxLayout()

        # 상단에 뒤로 가기 버튼 추가
        top_layout = QHBoxLayout()
        back_btn = QToolButton()
        back_btn.setText("←")  # 뒤로가기 아이콘 형태
        back_btn.setStyleSheet("""
            QToolButton {
                font-size: 36px; 
                background: none;
                border: none;
                color: #333333;
            }
            QToolButton:hover {
                color: #4CAF50;
            }
        """)
        back_btn.clicked.connect(self.init_main_screen)
        top_layout.addWidget(back_btn)
        top_layout.addStretch()  # 나머지 공간 확보

        self.category_layout.addLayout(top_layout)  # 상단 레이아웃 추가

        # 카테고리 라벨 추가
        self.category_label = QLabel("상품 카테고리")
        self.category_label.setAlignment(Qt.AlignCenter)
        self.category_layout.addWidget(self.category_label)

        # 카테고리 버튼 추가
        for category in self.categories.keys():
            btn = QPushButton(category)
            btn.setStyleSheet("font-size: 32px; padding: 15px;")
            btn.clicked.connect(lambda checked, cat=category: self.show_items(cat))
            self.category_layout.addWidget(btn)

            self.category_widget.setLayout(self.category_layout)
            self.setCentralWidget(self.category_widget)

    def show_items(self, category):
        self.current_category = category #현재 카테고리 저장
        self.item_widget = QWidget()
        self.item_layout = QVBoxLayout()

        # 상단에 뒤로 가기 버튼 추가
        top_layout = QHBoxLayout()
        back_btn = QToolButton()
        back_btn.setText("←")  # 뒤로가기 아이콘 형태
        back_btn.setStyleSheet("""
            QToolButton {
                font-size: 36px; 
                background: none;
                border: none;
                color: #333333;
            }
            QToolButton:hover {
                color: #4CAF50;
            }
        """)
        back_btn.clicked.connect(self.show_categories)
        top_layout.addWidget(back_btn)
        top_layout.addStretch()

        self.item_layout.addLayout(top_layout)

        # 타이틀 라벨
        self.item_label = QLabel(f"{category} 목록")
        self.item_label.setAlignment(Qt.AlignCenter)
        self.item_label.setStyleSheet("font-size: 40px;")
        self.item_layout.addWidget(self.item_label)

        scroll_area = QScrollArea()
        scroll_content = QWidget()
        scroll_layout = QVBoxLayout()

        for item_name, x, y, z, w, price, image in self.categories[category]:
            item_btn = QPushButton(item_name)
            item_btn.setStyleSheet("font-size: 32px; padding: 15px;")
            # 상품 정보를 전달
            item_btn.clicked.connect(lambda checked, n=item_name, x=x, y=y, w=w, z=z, p=price, img=image: self.show_product_info(n, x, y, z, w, p, img))
            scroll_layout.addWidget(item_btn)

        scroll_content.setLayout(scroll_layout)
        scroll_area.setWidget(scroll_content)
        scroll_area.setWidgetResizable(True)

        self.item_layout.addWidget(scroll_area)
        self.item_widget.setLayout(self.item_layout)
        self.setCentralWidget(self.item_widget)

    def show_product_info(self, item_name, x, y, z, w, price, image):
        """상품 정보를 보여주는 페이지"""
        self.info_widget = QWidget()
        self.info_layout = QVBoxLayout()

        #뒤로 가기 버튼 
        top_layout = QHBoxLayout()
        back_btn = QToolButton()
        back_btn.setText("←")
        back_btn.setStyleSheet("""
            QToolButton {
                font-size: 36px; 
                background: none;
                border: none;
                color: #333333;
            }
            QToolButton:hover {
                color: #4CAF50;
            }
        """)
        back_btn.clicked.connect(lambda: self.show_items(self.current_category))  # 현재 카테고리로 돌아가기
        top_layout.addWidget(back_btn)
        top_layout.addStretch()  # 나머지 공간 확보

        self.info_layout.addLayout(top_layout)

        # 이미지 경로를 현재 스크립트 파일 기준으로 설정
        current_dir = os.path.dirname(os.path.abspath(__file__))  # 현재 파일의 경로
        image_path = os.path.join(current_dir, image)  # 상대 경로를 기반으로 이미지 경로 설정


        # 상품 이미지
        img_label = QLabel()
        pixmap = QPixmap(image_path)
        if pixmap.isNull():  # 이미지 로딩 실패 시 디버깅 메시지
            print(f"Error: 이미지 로딩 실패 - {image_path}")
        img_label.setPixmap(pixmap.scaled(400, 400, Qt.KeepAspectRatio))
        self.info_layout.addWidget(img_label, alignment=Qt.AlignCenter)

        # 상품 이름과 가격
        name_label = QLabel(f"상품명: {item_name}")
        price_label = QLabel(f"가격: {price}원")
        name_label.setStyleSheet("font-size: 36px; font-weight: bold;")
        price_label.setStyleSheet("font-size: 32px;")
        self.info_layout.addWidget(name_label, alignment=Qt.AlignCenter)
        self.info_layout.addWidget(price_label, alignment=Qt.AlignCenter)

        # 버튼 레이아웃
        btn_layout = QHBoxLayout()

        add_to_cart_btn = QPushButton("장바구니에 담기")
        add_to_cart_btn.setStyleSheet("font-size: 28px; padding: 10px;")
        add_to_cart_btn.clicked.connect(lambda: self.add_to_cart(item_name))
        btn_layout.addWidget(add_to_cart_btn)

        guide_btn = QPushButton("상품으로 안내 시작")
        guide_btn.setStyleSheet("font-size: 28px; padding: 10px;")
        guide_btn.clicked.connect(lambda: self.start_guiding_to_product(item_name, x, y, z, w))
        btn_layout.addWidget(guide_btn)

        self.info_layout.addLayout(btn_layout)

        self.info_widget.setLayout(self.info_layout)
        self.setCentralWidget(self.info_widget)

    def start_guiding_to_product(self, item_name, x, y, z, w):
        """상품으로 안내 시작 로직"""
        self.show_guiding_screen("안내중입니다!")  # 안내중 화면 표시
        QTimer.singleShot(500, lambda: self.send_order_guide(item_name, x, y, z, w))

    def show_guiding_screen(self, message):
        """상품 안내 중 화면 표시"""
        self.guiding_widget = QWidget()
        self.guiding_layout = QVBoxLayout()

        # 상단에 뒤로 가기 버튼 추가
        top_layout = QHBoxLayout()
        back_btn = QToolButton()
        back_btn.setText("←")
        back_btn.setStyleSheet("""
            QToolButton {
                font-size: 36px; 
                background: none;
                border: none;
                color: #333333;
            }
            QToolButton:hover {
                color: #4CAF50;
            }
        """)
        back_btn.clicked.connect(self.init_main_screen)  # 메인 화면으로 돌아가기
        top_layout.addWidget(back_btn)
        top_layout.addStretch()  # 남은 공간 확보

        self.guiding_layout.addLayout(top_layout)

        # 안내 문구 추가
        guiding_label = QLabel(message)  # 전달받은 메시지 표시
        guiding_label.setAlignment(Qt.AlignCenter)
        guiding_label.setStyleSheet("font-size: 36px; font-weight: bold;")
        self.guiding_layout.addWidget(guiding_label, alignment=Qt.AlignCenter)
        # 레이아웃 설정
        self.guiding_widget.setLayout(self.guiding_layout)
        self.setCentralWidget(self.guiding_widget)
    
    def add_to_cart(self, item_name):
        """장바구니에 상품 추가"""
        self.cart.append(item_name)
        # self.label = QLabel("상품이 장바구니에 추가했습니다!")
        # self.label.setAlignment(Qt.AlignCenter)
        # self.main_layout.addWidget(self.label)
        playsound('./beep-07a.wav')
        self.statusBar().showMessage(f"{item_name}을(를) 장바구니에 추가했습니다!")

    def send_order_guide(self, item_name, x, y, z, w):
        """NavigateToPose 목표의 성공 여부를 확인"""
        goal_pose = Pose()
        goal_pose.position.x = x
        goal_pose.position.y = y
        goal_pose.position.z = 0.0
        goal_pose.orientation.x = 0.0
        goal_pose.orientation.y = 0.0
        goal_pose.orientation.z = z
        goal_pose.orientation.w = w
        # toggle_control_command 호출 (첫 번째 호출)
        control_result = self.order_client.set_control_command(True)
        qr_result = self.order_client.set_qr_command(False)
        if control_result.success and qr_result.success:
            self.statusBar().showMessage("Control command started, QR command stopped.")
        else:
            self.statusBar().showMessage("Failed to start control command or stop QR command.")

        # 1. ROS 서비스 요청
        result = self.order_client.send_request('nav_to_pose_with_client', goal_pose)
        if result.accepted:
            self.statusBar().showMessage("서비스 요청 성공!")
            
            # navigate_to_pose 서버의 succeeded 메시지 확인
            if self.order_client.check_navigation_status():
                
                # Disable control command and enable QR command
                control_result = self.order_client.set_control_command(False)
                qr_result = self.order_client.set_qr_command(True)
                if control_result.success and qr_result.success:
                    self.statusBar().showMessage("Control command stopped, QR command started.")
                else:
                    self.statusBar().showMessage("Failed to stop control command or start QR command.")
                self.order_client.msg.angular.z = 0.5
                for i in range(15):
                    self.order_client.cmd_vel_publisher.publish(self.order_client.msg)
                    time.sleep(0.8)
                self.show_guiding_screen("상품 위치로 도착하였습니다!")

                
            else:
                self.statusBar().showMessage("안내 실패!")
        else:
            self.statusBar().showMessage("서비스 요청 실패!")

    
    def send_order_station(self): #order 가 'nav_to_station'
        goal_pose = Pose()
        

        result = self.order_client.send_request('nav_to_station', goal_pose) 
        if result.accepted:
            self.statusBar().showMessage(f"카트 반납: 서비스 요청 성공!")
            
        else:
            self.statusBar().showMessage(f"카트 반납: 서비스 요청 실패!")


# def main():
#     app = QApplication(sys.argv)
#     window = ROS2UI()
#     window.show()
#     app.exec_()
#     rclpy.shutdown()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = ROS2UI()
    window.show()
    app.exec_()
    rclpy.shutdown()
    # main()
