import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/hjpark/dev_hjp/ROS2/storagy-repo-1/i6robotics/install/i6robotics_data_processing'
