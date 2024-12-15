from setuptools import find_packages, setup

package_name = 'i6robotics_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hjpark',
    maintainer_email='hyunji7674@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'i6robotics_control_node = i6robotics_control.i6robotics_control_node:main',
            'i6robotics_control_simplecmd_node= i6robotics_control.i6robotics_control_nav2simplecmd_action_node:main',
            'i6robotics_control_nav_action_node= i6robotics_control.i6robotics_control_navigation:main',
            'nav_to_pose_action_client=i6robotics_control.i6robotics_control_navigation:main',
            'i6robotics_control_nav_service_node=i6robotics_control.i6robotics_control_navigation_service:main',
            'i6robotics_control_nav_feedback_node=i6robotics_control.i6robotics_control_navigation_service:main' 
        ],
    },
)
