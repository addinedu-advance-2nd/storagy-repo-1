from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'i6robotics_guiding'

setup(
    name=package_name,
    version='0.0.1',  # 버전 업데이트
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'srv'), glob('srv/*.srv')), 
    ],
    install_requires=[
        'setuptools',  # Required for installation
        'rclpy',       # ROS 2 Python client library
        'std_msgs',
        'action_msgs',  # Required for action messages
        'nav2_msgs',    # For navigation-specific messages
        'geometry_msgs',  # For geometry message types
        'unique_identifier_msgs', # Required for unique identifier messages
        'opencv-python',    # OpenCV for computer vision
        'mediapipe',        # MediaPipe for pose detection
        'numpy',            # NumPy for numerical computations  
    ],
    zip_safe=True,
    maintainer='zl',
    maintainer_email='zl@yourdomain.com',  # 실제 이메일로 수정
    description='A ROS2 package to pause and resume navigation goals',  # 패키지 설명
    license='Apache-2.0',  # 패키지 라이선스 (필요시 수정)
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            
            'nav2pose_client_test6 = i6robotics_guiding.nav2pose_client_test6:main',
            'nav2pose_client_test7 = i6robotics_guiding.nav2pose_client_test7:main',            
            'rear_camera_publisher3 = i6robotics_guiding.rear_camera_publisher3:main',
            'set_goal_choice_client = i6robotics_guiding.set_goal_choice_client:main',
        ],
    },
)
