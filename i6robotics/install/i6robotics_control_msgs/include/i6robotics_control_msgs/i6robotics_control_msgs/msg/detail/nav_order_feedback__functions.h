// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from i6robotics_control_msgs:msg/NavOrderFeedback.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__FUNCTIONS_H_
#define I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "i6robotics_control_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "i6robotics_control_msgs/msg/detail/nav_order_feedback__struct.h"

/// Initialize msg/NavOrderFeedback message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * i6robotics_control_msgs__msg__NavOrderFeedback
 * )) before or use
 * i6robotics_control_msgs__msg__NavOrderFeedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__msg__NavOrderFeedback__init(i6robotics_control_msgs__msg__NavOrderFeedback * msg);

/// Finalize msg/NavOrderFeedback message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__msg__NavOrderFeedback__fini(i6robotics_control_msgs__msg__NavOrderFeedback * msg);

/// Create msg/NavOrderFeedback message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * i6robotics_control_msgs__msg__NavOrderFeedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__msg__NavOrderFeedback *
i6robotics_control_msgs__msg__NavOrderFeedback__create();

/// Destroy msg/NavOrderFeedback message.
/**
 * It calls
 * i6robotics_control_msgs__msg__NavOrderFeedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__msg__NavOrderFeedback__destroy(i6robotics_control_msgs__msg__NavOrderFeedback * msg);

/// Check for msg/NavOrderFeedback message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__msg__NavOrderFeedback__are_equal(const i6robotics_control_msgs__msg__NavOrderFeedback * lhs, const i6robotics_control_msgs__msg__NavOrderFeedback * rhs);

/// Copy a msg/NavOrderFeedback message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__msg__NavOrderFeedback__copy(
  const i6robotics_control_msgs__msg__NavOrderFeedback * input,
  i6robotics_control_msgs__msg__NavOrderFeedback * output);

/// Initialize array of msg/NavOrderFeedback messages.
/**
 * It allocates the memory for the number of elements and calls
 * i6robotics_control_msgs__msg__NavOrderFeedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__init(i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * array, size_t size);

/// Finalize array of msg/NavOrderFeedback messages.
/**
 * It calls
 * i6robotics_control_msgs__msg__NavOrderFeedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__fini(i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * array);

/// Create array of msg/NavOrderFeedback messages.
/**
 * It allocates the memory for the array and calls
 * i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence *
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__create(size_t size);

/// Destroy array of msg/NavOrderFeedback messages.
/**
 * It calls
 * i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__destroy(i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * array);

/// Check for msg/NavOrderFeedback message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__are_equal(const i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * lhs, const i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * rhs);

/// Copy an array of msg/NavOrderFeedback messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__copy(
  const i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * input,
  i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__FUNCTIONS_H_
