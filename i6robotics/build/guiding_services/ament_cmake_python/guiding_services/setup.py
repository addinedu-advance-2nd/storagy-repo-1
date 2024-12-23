from setuptools import find_packages
from setuptools import setup

setup(
    name='guiding_services',
    version='0.0.0',
    packages=find_packages(
        include=('guiding_services', 'guiding_services.*')),
)
