// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from i6robotics_control_msgs:srv/Order.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__STRUCT_H_
#define I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'order'
#include "rosidl_runtime_c/string.h"
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/Order in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__srv__Order_Request
{
  rosidl_runtime_c__String order;
  /// 주행 요청
  /// follow_on (팔로우 활성화)
  /// follow_off(팔로우 비활성화)
  /// nav_to_pose (특정 위치로 이동)
  /// nav_to_pose_with_client (특정 위치로 안내)
  /// nav_to_station (충전 스테이션으로 복귀)
  /// nav_to_pose, nav_to_pose_with_client, 두 경우에만 도착 지점의 좌표를 입력. 이 외에는 None 입력
  geometry_msgs__msg__Pose goal_pose;
} i6robotics_control_msgs__srv__Order_Request;

// Struct for a sequence of i6robotics_control_msgs__srv__Order_Request.
typedef struct i6robotics_control_msgs__srv__Order_Request__Sequence
{
  i6robotics_control_msgs__srv__Order_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__srv__Order_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Order in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__srv__Order_Response
{
  /// 주행 명령이 잘 적용되었는지. 잘 적용되었다면 True, 그렇지 않다면 False
  bool accepted;
} i6robotics_control_msgs__srv__Order_Response;

// Struct for a sequence of i6robotics_control_msgs__srv__Order_Response.
typedef struct i6robotics_control_msgs__srv__Order_Response__Sequence
{
  i6robotics_control_msgs__srv__Order_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__srv__Order_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__STRUCT_H_
