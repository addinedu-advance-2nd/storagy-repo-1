import rclpy
from rclpy.node import Node
from guiding_services.srv import SetGoalChoice  # SetGoalChoice 서비스 메시지 임포트


class SetGoalChoiceClient(Node):
    def __init__(self):
        super().__init__('set_goal_choice_client')
        self.client = self.create_client(SetGoalChoice, 'set_goal_choice')

        # 서비스가 준비될 때까지 대기
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting...')

    def send_request(self, choice):
        request = SetGoalChoice.Request()
        request.choice = choice

        self.get_logger().info(f'Sending request with choice: {choice}')
        future = self.client.call_async(request)
        future.add_done_callback(self.callback)

    def callback(self, future):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Success: {response.message}")
            else:
                self.get_logger().error(f"Failed: {response.message}")
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")


def main(args=None):
    rclpy.init(args=args)
    client_node = SetGoalChoiceClient()

    try:
        while rclpy.ok():
            user_input = input("Enter goal choice (1-5, or 0 to shutdown): ")
            try:
                choice = int(user_input)
                if choice < 0:
                    print("Please enter a positive number.")
                    continue
                client_node.send_request(choice)
            except ValueError:
                print("Invalid input. Please enter a number.")
            rclpy.spin_once(client_node)
    except KeyboardInterrupt:
        client_node.get_logger().info("Keyboard interrupt, shutting down...")
    finally:
        client_node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()