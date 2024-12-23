// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from i6robotics_control_msgs:msg/NavOrderFeedback.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "i6robotics_control_msgs/msg/detail/nav_order_feedback__rosidl_typesupport_introspection_c.h"
#include "i6robotics_control_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "i6robotics_control_msgs/msg/detail/nav_order_feedback__functions.h"
#include "i6robotics_control_msgs/msg/detail/nav_order_feedback__struct.h"


// Include directives for member types
// Member `current_pose`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `current_pose`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  i6robotics_control_msgs__msg__NavOrderFeedback__init(message_memory);
}

void i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_fini_function(void * message_memory)
{
  i6robotics_control_msgs__msg__NavOrderFeedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_message_member_array[2] = {
  {
    "current_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i6robotics_control_msgs__msg__NavOrderFeedback, current_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_remaining",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i6robotics_control_msgs__msg__NavOrderFeedback, distance_remaining),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_message_members = {
  "i6robotics_control_msgs__msg",  // message namespace
  "NavOrderFeedback",  // message name
  2,  // number of fields
  sizeof(i6robotics_control_msgs__msg__NavOrderFeedback),
  i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_message_member_array,  // message members
  i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_init_function,  // function to initialize message memory (memory has to be allocated)
  i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_message_type_support_handle = {
  0,
  &i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_i6robotics_control_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, msg, NavOrderFeedback)() {
  i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  if (!i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_message_type_support_handle.typesupport_identifier) {
    i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &i6robotics_control_msgs__msg__NavOrderFeedback__rosidl_typesupport_introspection_c__NavOrderFeedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
