from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # rear_camera_publisher3.py 실행 노드
        Node(
            package='i6robotics_guiding',  
            executable='rear_camera_publisher3',  
            name='rear_camera_publisher3',
            output='screen',
            emulate_tty=True
        ),

        # nav2pose_client_test7.py 실행 노드
        Node(
            package='i6robotics_guiding',  
            executable='nav2pose_client_test7',  
            name='nav2pose_client',
            output='screen',
            emulate_tty=True
        ),
    ])