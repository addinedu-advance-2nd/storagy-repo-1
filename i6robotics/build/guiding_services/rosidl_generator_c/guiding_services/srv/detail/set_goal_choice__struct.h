// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from guiding_services:srv/SetGoalChoice.idl
// generated code does not contain a copyright notice

#ifndef GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__STRUCT_H_
#define GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetGoalChoice in the package guiding_services.
typedef struct guiding_services__srv__SetGoalChoice_Request
{
  /// 요청: 선택한 goal (1~5 또는 0으로 종료)
  int32_t choice;
} guiding_services__srv__SetGoalChoice_Request;

// Struct for a sequence of guiding_services__srv__SetGoalChoice_Request.
typedef struct guiding_services__srv__SetGoalChoice_Request__Sequence
{
  guiding_services__srv__SetGoalChoice_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} guiding_services__srv__SetGoalChoice_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetGoalChoice in the package guiding_services.
typedef struct guiding_services__srv__SetGoalChoice_Response
{
  /// 응답: 요청 성공 여부
  bool success;
  /// 응답: 결과 메시지
  rosidl_runtime_c__String message;
} guiding_services__srv__SetGoalChoice_Response;

// Struct for a sequence of guiding_services__srv__SetGoalChoice_Response.
typedef struct guiding_services__srv__SetGoalChoice_Response__Sequence
{
  guiding_services__srv__SetGoalChoice_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} guiding_services__srv__SetGoalChoice_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__STRUCT_H_
