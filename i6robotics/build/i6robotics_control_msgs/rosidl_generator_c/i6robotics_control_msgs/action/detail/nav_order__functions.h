// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from i6robotics_control_msgs:action/NavOrder.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__NAV_ORDER__FUNCTIONS_H_
#define I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__NAV_ORDER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "i6robotics_control_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "i6robotics_control_msgs/action/detail/nav_order__struct.h"

/// Initialize action/NavOrder message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * i6robotics_control_msgs__action__NavOrder_Goal
 * )) before or use
 * i6robotics_control_msgs__action__NavOrder_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Goal__init(i6robotics_control_msgs__action__NavOrder_Goal * msg);

/// Finalize action/NavOrder message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Goal__fini(i6robotics_control_msgs__action__NavOrder_Goal * msg);

/// Create action/NavOrder message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * i6robotics_control_msgs__action__NavOrder_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_Goal *
i6robotics_control_msgs__action__NavOrder_Goal__create();

/// Destroy action/NavOrder message.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Goal__destroy(i6robotics_control_msgs__action__NavOrder_Goal * msg);

/// Check for action/NavOrder message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Goal__are_equal(const i6robotics_control_msgs__action__NavOrder_Goal * lhs, const i6robotics_control_msgs__action__NavOrder_Goal * rhs);

/// Copy a action/NavOrder message.
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
i6robotics_control_msgs__action__NavOrder_Goal__copy(
  const i6robotics_control_msgs__action__NavOrder_Goal * input,
  i6robotics_control_msgs__action__NavOrder_Goal * output);

/// Initialize array of action/NavOrder messages.
/**
 * It allocates the memory for the number of elements and calls
 * i6robotics_control_msgs__action__NavOrder_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__init(i6robotics_control_msgs__action__NavOrder_Goal__Sequence * array, size_t size);

/// Finalize array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__fini(i6robotics_control_msgs__action__NavOrder_Goal__Sequence * array);

/// Create array of action/NavOrder messages.
/**
 * It allocates the memory for the array and calls
 * i6robotics_control_msgs__action__NavOrder_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_Goal__Sequence *
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__create(size_t size);

/// Destroy array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_Goal__Sequence * array);

/// Check for action/NavOrder message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_Goal__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_Goal__Sequence * rhs);

/// Copy an array of action/NavOrder messages.
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
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_Goal__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_Goal__Sequence * output);

/// Initialize action/NavOrder message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * i6robotics_control_msgs__action__NavOrder_Result
 * )) before or use
 * i6robotics_control_msgs__action__NavOrder_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Result__init(i6robotics_control_msgs__action__NavOrder_Result * msg);

/// Finalize action/NavOrder message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Result__fini(i6robotics_control_msgs__action__NavOrder_Result * msg);

/// Create action/NavOrder message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * i6robotics_control_msgs__action__NavOrder_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_Result *
i6robotics_control_msgs__action__NavOrder_Result__create();

/// Destroy action/NavOrder message.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Result__destroy(i6robotics_control_msgs__action__NavOrder_Result * msg);

/// Check for action/NavOrder message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Result__are_equal(const i6robotics_control_msgs__action__NavOrder_Result * lhs, const i6robotics_control_msgs__action__NavOrder_Result * rhs);

/// Copy a action/NavOrder message.
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
i6robotics_control_msgs__action__NavOrder_Result__copy(
  const i6robotics_control_msgs__action__NavOrder_Result * input,
  i6robotics_control_msgs__action__NavOrder_Result * output);

/// Initialize array of action/NavOrder messages.
/**
 * It allocates the memory for the number of elements and calls
 * i6robotics_control_msgs__action__NavOrder_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Result__Sequence__init(i6robotics_control_msgs__action__NavOrder_Result__Sequence * array, size_t size);

/// Finalize array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Result__Sequence__fini(i6robotics_control_msgs__action__NavOrder_Result__Sequence * array);

/// Create array of action/NavOrder messages.
/**
 * It allocates the memory for the array and calls
 * i6robotics_control_msgs__action__NavOrder_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_Result__Sequence *
i6robotics_control_msgs__action__NavOrder_Result__Sequence__create(size_t size);

/// Destroy array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Result__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_Result__Sequence * array);

/// Check for action/NavOrder message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Result__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_Result__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_Result__Sequence * rhs);

/// Copy an array of action/NavOrder messages.
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
i6robotics_control_msgs__action__NavOrder_Result__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_Result__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_Result__Sequence * output);

/// Initialize action/NavOrder message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * i6robotics_control_msgs__action__NavOrder_Feedback
 * )) before or use
 * i6robotics_control_msgs__action__NavOrder_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Feedback__init(i6robotics_control_msgs__action__NavOrder_Feedback * msg);

/// Finalize action/NavOrder message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Feedback__fini(i6robotics_control_msgs__action__NavOrder_Feedback * msg);

/// Create action/NavOrder message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * i6robotics_control_msgs__action__NavOrder_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_Feedback *
i6robotics_control_msgs__action__NavOrder_Feedback__create();

/// Destroy action/NavOrder message.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Feedback__destroy(i6robotics_control_msgs__action__NavOrder_Feedback * msg);

/// Check for action/NavOrder message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Feedback__are_equal(const i6robotics_control_msgs__action__NavOrder_Feedback * lhs, const i6robotics_control_msgs__action__NavOrder_Feedback * rhs);

/// Copy a action/NavOrder message.
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
i6robotics_control_msgs__action__NavOrder_Feedback__copy(
  const i6robotics_control_msgs__action__NavOrder_Feedback * input,
  i6robotics_control_msgs__action__NavOrder_Feedback * output);

/// Initialize array of action/NavOrder messages.
/**
 * It allocates the memory for the number of elements and calls
 * i6robotics_control_msgs__action__NavOrder_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__init(i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * array, size_t size);

/// Finalize array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__fini(i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * array);

/// Create array of action/NavOrder messages.
/**
 * It allocates the memory for the array and calls
 * i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence *
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__create(size_t size);

/// Destroy array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * array);

/// Check for action/NavOrder message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * rhs);

/// Copy an array of action/NavOrder messages.
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
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * output);

/// Initialize action/NavOrder message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Request
 * )) before or use
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__init(i6robotics_control_msgs__action__NavOrder_SendGoal_Request * msg);

/// Finalize action/NavOrder message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__fini(i6robotics_control_msgs__action__NavOrder_SendGoal_Request * msg);

/// Create action/NavOrder message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_SendGoal_Request *
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__create();

/// Destroy action/NavOrder message.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__destroy(i6robotics_control_msgs__action__NavOrder_SendGoal_Request * msg);

/// Check for action/NavOrder message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__are_equal(const i6robotics_control_msgs__action__NavOrder_SendGoal_Request * lhs, const i6robotics_control_msgs__action__NavOrder_SendGoal_Request * rhs);

/// Copy a action/NavOrder message.
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
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__copy(
  const i6robotics_control_msgs__action__NavOrder_SendGoal_Request * input,
  i6robotics_control_msgs__action__NavOrder_SendGoal_Request * output);

/// Initialize array of action/NavOrder messages.
/**
 * It allocates the memory for the number of elements and calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__init(i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__fini(i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * array);

/// Create array of action/NavOrder messages.
/**
 * It allocates the memory for the array and calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence *
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * array);

/// Check for action/NavOrder message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/NavOrder messages.
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
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * output);

/// Initialize action/NavOrder message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Response
 * )) before or use
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__init(i6robotics_control_msgs__action__NavOrder_SendGoal_Response * msg);

/// Finalize action/NavOrder message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__fini(i6robotics_control_msgs__action__NavOrder_SendGoal_Response * msg);

/// Create action/NavOrder message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_SendGoal_Response *
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__create();

/// Destroy action/NavOrder message.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__destroy(i6robotics_control_msgs__action__NavOrder_SendGoal_Response * msg);

/// Check for action/NavOrder message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__are_equal(const i6robotics_control_msgs__action__NavOrder_SendGoal_Response * lhs, const i6robotics_control_msgs__action__NavOrder_SendGoal_Response * rhs);

/// Copy a action/NavOrder message.
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
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__copy(
  const i6robotics_control_msgs__action__NavOrder_SendGoal_Response * input,
  i6robotics_control_msgs__action__NavOrder_SendGoal_Response * output);

/// Initialize array of action/NavOrder messages.
/**
 * It allocates the memory for the number of elements and calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__init(i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__fini(i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * array);

/// Create array of action/NavOrder messages.
/**
 * It allocates the memory for the array and calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence *
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * array);

/// Check for action/NavOrder message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/NavOrder messages.
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
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * output);

/// Initialize action/NavOrder message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * i6robotics_control_msgs__action__NavOrder_GetResult_Request
 * )) before or use
 * i6robotics_control_msgs__action__NavOrder_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_GetResult_Request__init(i6robotics_control_msgs__action__NavOrder_GetResult_Request * msg);

/// Finalize action/NavOrder message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_GetResult_Request__fini(i6robotics_control_msgs__action__NavOrder_GetResult_Request * msg);

/// Create action/NavOrder message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_GetResult_Request *
i6robotics_control_msgs__action__NavOrder_GetResult_Request__create();

/// Destroy action/NavOrder message.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_GetResult_Request__destroy(i6robotics_control_msgs__action__NavOrder_GetResult_Request * msg);

/// Check for action/NavOrder message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_GetResult_Request__are_equal(const i6robotics_control_msgs__action__NavOrder_GetResult_Request * lhs, const i6robotics_control_msgs__action__NavOrder_GetResult_Request * rhs);

/// Copy a action/NavOrder message.
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
i6robotics_control_msgs__action__NavOrder_GetResult_Request__copy(
  const i6robotics_control_msgs__action__NavOrder_GetResult_Request * input,
  i6robotics_control_msgs__action__NavOrder_GetResult_Request * output);

/// Initialize array of action/NavOrder messages.
/**
 * It allocates the memory for the number of elements and calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__init(i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__fini(i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * array);

/// Create array of action/NavOrder messages.
/**
 * It allocates the memory for the array and calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence *
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * array);

/// Check for action/NavOrder message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * rhs);

/// Copy an array of action/NavOrder messages.
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
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * output);

/// Initialize action/NavOrder message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * i6robotics_control_msgs__action__NavOrder_GetResult_Response
 * )) before or use
 * i6robotics_control_msgs__action__NavOrder_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_GetResult_Response__init(i6robotics_control_msgs__action__NavOrder_GetResult_Response * msg);

/// Finalize action/NavOrder message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_GetResult_Response__fini(i6robotics_control_msgs__action__NavOrder_GetResult_Response * msg);

/// Create action/NavOrder message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_GetResult_Response *
i6robotics_control_msgs__action__NavOrder_GetResult_Response__create();

/// Destroy action/NavOrder message.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_GetResult_Response__destroy(i6robotics_control_msgs__action__NavOrder_GetResult_Response * msg);

/// Check for action/NavOrder message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_GetResult_Response__are_equal(const i6robotics_control_msgs__action__NavOrder_GetResult_Response * lhs, const i6robotics_control_msgs__action__NavOrder_GetResult_Response * rhs);

/// Copy a action/NavOrder message.
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
i6robotics_control_msgs__action__NavOrder_GetResult_Response__copy(
  const i6robotics_control_msgs__action__NavOrder_GetResult_Response * input,
  i6robotics_control_msgs__action__NavOrder_GetResult_Response * output);

/// Initialize array of action/NavOrder messages.
/**
 * It allocates the memory for the number of elements and calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__init(i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__fini(i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * array);

/// Create array of action/NavOrder messages.
/**
 * It allocates the memory for the array and calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence *
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * array);

/// Check for action/NavOrder message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * rhs);

/// Copy an array of action/NavOrder messages.
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
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * output);

/// Initialize action/NavOrder message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * i6robotics_control_msgs__action__NavOrder_FeedbackMessage
 * )) before or use
 * i6robotics_control_msgs__action__NavOrder_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__init(i6robotics_control_msgs__action__NavOrder_FeedbackMessage * msg);

/// Finalize action/NavOrder message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__fini(i6robotics_control_msgs__action__NavOrder_FeedbackMessage * msg);

/// Create action/NavOrder message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * i6robotics_control_msgs__action__NavOrder_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_FeedbackMessage *
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__create();

/// Destroy action/NavOrder message.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__destroy(i6robotics_control_msgs__action__NavOrder_FeedbackMessage * msg);

/// Check for action/NavOrder message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__are_equal(const i6robotics_control_msgs__action__NavOrder_FeedbackMessage * lhs, const i6robotics_control_msgs__action__NavOrder_FeedbackMessage * rhs);

/// Copy a action/NavOrder message.
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
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__copy(
  const i6robotics_control_msgs__action__NavOrder_FeedbackMessage * input,
  i6robotics_control_msgs__action__NavOrder_FeedbackMessage * output);

/// Initialize array of action/NavOrder messages.
/**
 * It allocates the memory for the number of elements and calls
 * i6robotics_control_msgs__action__NavOrder_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__init(i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__fini(i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * array);

/// Create array of action/NavOrder messages.
/**
 * It allocates the memory for the array and calls
 * i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence *
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/NavOrder messages.
/**
 * It calls
 * i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
void
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * array);

/// Check for action/NavOrder message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_i6robotics_control_msgs
bool
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/NavOrder messages.
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
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__NAV_ORDER__FUNCTIONS_H_
