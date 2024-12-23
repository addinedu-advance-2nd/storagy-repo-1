from setuptools import find_packages
from setuptools import setup

setup(
    name='i6robotics_control_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('i6robotics_control_msgs', 'i6robotics_control_msgs.*')),
)
