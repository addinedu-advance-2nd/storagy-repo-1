// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from i6robotics_control_msgs:msg/NavOrderFeedback.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__STRUCT_H_
#define I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in msg/NavOrderFeedback in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__msg__NavOrderFeedback
{
  geometry_msgs__msg__PoseStamped current_pose;
  float distance_remaining;
} i6robotics_control_msgs__msg__NavOrderFeedback;

// Struct for a sequence of i6robotics_control_msgs__msg__NavOrderFeedback.
typedef struct i6robotics_control_msgs__msg__NavOrderFeedback__Sequence
{
  i6robotics_control_msgs__msg__NavOrderFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__msg__NavOrderFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__STRUCT_H_
