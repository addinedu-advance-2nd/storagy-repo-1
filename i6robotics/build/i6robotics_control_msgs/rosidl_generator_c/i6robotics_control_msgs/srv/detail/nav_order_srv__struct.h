// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from i6robotics_control_msgs:srv/NavOrderSrv.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__STRUCT_H_
#define I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/NavOrderSrv in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__srv__NavOrderSrv_Request
{
  geometry_msgs__msg__Pose goal_pose;
} i6robotics_control_msgs__srv__NavOrderSrv_Request;

// Struct for a sequence of i6robotics_control_msgs__srv__NavOrderSrv_Request.
typedef struct i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence
{
  i6robotics_control_msgs__srv__NavOrderSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/NavOrderSrv in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__srv__NavOrderSrv_Response
{
  rosidl_runtime_c__String result;
} i6robotics_control_msgs__srv__NavOrderSrv_Response;

// Struct for a sequence of i6robotics_control_msgs__srv__NavOrderSrv_Response.
typedef struct i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence
{
  i6robotics_control_msgs__srv__NavOrderSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__STRUCT_H_
