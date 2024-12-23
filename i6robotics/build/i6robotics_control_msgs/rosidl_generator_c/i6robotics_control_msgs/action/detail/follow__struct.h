// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from i6robotics_control_msgs:action/Follow.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__FOLLOW__STRUCT_H_
#define I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__FOLLOW__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Follow in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__action__Follow_Goal
{
  uint8_t structure_needs_at_least_one_member;
} i6robotics_control_msgs__action__Follow_Goal;

// Struct for a sequence of i6robotics_control_msgs__action__Follow_Goal.
typedef struct i6robotics_control_msgs__action__Follow_Goal__Sequence
{
  i6robotics_control_msgs__action__Follow_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__action__Follow_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Follow in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__action__Follow_Result
{
  rosidl_runtime_c__String result;
} i6robotics_control_msgs__action__Follow_Result;

// Struct for a sequence of i6robotics_control_msgs__action__Follow_Result.
typedef struct i6robotics_control_msgs__action__Follow_Result__Sequence
{
  i6robotics_control_msgs__action__Follow_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__action__Follow_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'feedback'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Follow in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__action__Follow_Feedback
{
  rosidl_runtime_c__String feedback;
} i6robotics_control_msgs__action__Follow_Feedback;

// Struct for a sequence of i6robotics_control_msgs__action__Follow_Feedback.
typedef struct i6robotics_control_msgs__action__Follow_Feedback__Sequence
{
  i6robotics_control_msgs__action__Follow_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__action__Follow_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "i6robotics_control_msgs/action/detail/follow__struct.h"

/// Struct defined in action/Follow in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__action__Follow_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  i6robotics_control_msgs__action__Follow_Goal goal;
} i6robotics_control_msgs__action__Follow_SendGoal_Request;

// Struct for a sequence of i6robotics_control_msgs__action__Follow_SendGoal_Request.
typedef struct i6robotics_control_msgs__action__Follow_SendGoal_Request__Sequence
{
  i6robotics_control_msgs__action__Follow_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__action__Follow_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Follow in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__action__Follow_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} i6robotics_control_msgs__action__Follow_SendGoal_Response;

// Struct for a sequence of i6robotics_control_msgs__action__Follow_SendGoal_Response.
typedef struct i6robotics_control_msgs__action__Follow_SendGoal_Response__Sequence
{
  i6robotics_control_msgs__action__Follow_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__action__Follow_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Follow in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__action__Follow_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} i6robotics_control_msgs__action__Follow_GetResult_Request;

// Struct for a sequence of i6robotics_control_msgs__action__Follow_GetResult_Request.
typedef struct i6robotics_control_msgs__action__Follow_GetResult_Request__Sequence
{
  i6robotics_control_msgs__action__Follow_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__action__Follow_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__struct.h"

/// Struct defined in action/Follow in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__action__Follow_GetResult_Response
{
  int8_t status;
  i6robotics_control_msgs__action__Follow_Result result;
} i6robotics_control_msgs__action__Follow_GetResult_Response;

// Struct for a sequence of i6robotics_control_msgs__action__Follow_GetResult_Response.
typedef struct i6robotics_control_msgs__action__Follow_GetResult_Response__Sequence
{
  i6robotics_control_msgs__action__Follow_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__action__Follow_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__struct.h"

/// Struct defined in action/Follow in the package i6robotics_control_msgs.
typedef struct i6robotics_control_msgs__action__Follow_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  i6robotics_control_msgs__action__Follow_Feedback feedback;
} i6robotics_control_msgs__action__Follow_FeedbackMessage;

// Struct for a sequence of i6robotics_control_msgs__action__Follow_FeedbackMessage.
typedef struct i6robotics_control_msgs__action__Follow_FeedbackMessage__Sequence
{
  i6robotics_control_msgs__action__Follow_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} i6robotics_control_msgs__action__Follow_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__FOLLOW__STRUCT_H_
