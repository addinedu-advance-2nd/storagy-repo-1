# generated from rosidl_generator_py/resource/_idl.py.em
# with input from i6robotics_control_msgs:srv/Order.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Order_Request(type):
    """Metaclass of message 'Order_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('i6robotics_control_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'i6robotics_control_msgs.srv.Order_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__order__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__order__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__order__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__order__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__order__request

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Order_Request(metaclass=Metaclass_Order_Request):
    """Message class 'Order_Request'."""

    __slots__ = [
        '_order',
        '_goal_pose',
    ]

    _fields_and_field_types = {
        'order': 'string',
        'goal_pose': 'geometry_msgs/Pose',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.order = kwargs.get('order', str())
        from geometry_msgs.msg import Pose
        self.goal_pose = kwargs.get('goal_pose', Pose())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.order != other.order:
            return False
        if self.goal_pose != other.goal_pose:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def order(self):
        """Message field 'order'."""
        return self._order

    @order.setter
    def order(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'order' field must be of type 'str'"
        self._order = value

    @builtins.property
    def goal_pose(self):
        """Message field 'goal_pose'."""
        return self._goal_pose

    @goal_pose.setter
    def goal_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'goal_pose' field must be a sub message of type 'Pose'"
        self._goal_pose = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Order_Response(type):
    """Metaclass of message 'Order_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('i6robotics_control_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'i6robotics_control_msgs.srv.Order_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__order__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__order__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__order__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__order__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__order__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Order_Response(metaclass=Metaclass_Order_Response):
    """Message class 'Order_Response'."""

    __slots__ = [
        '_accepted',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.accepted != other.accepted:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value


class Metaclass_Order(type):
    """Metaclass of service 'Order'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('i6robotics_control_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'i6robotics_control_msgs.srv.Order')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__order

            from i6robotics_control_msgs.srv import _order
            if _order.Metaclass_Order_Request._TYPE_SUPPORT is None:
                _order.Metaclass_Order_Request.__import_type_support__()
            if _order.Metaclass_Order_Response._TYPE_SUPPORT is None:
                _order.Metaclass_Order_Response.__import_type_support__()


class Order(metaclass=Metaclass_Order):
    from i6robotics_control_msgs.srv._order import Order_Request as Request
    from i6robotics_control_msgs.srv._order import Order_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
