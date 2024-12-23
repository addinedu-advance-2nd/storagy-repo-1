// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from i6robotics_control_msgs:action/NavOrder.idl
// generated code does not contain a copyright notice
#include "i6robotics_control_msgs/action/detail/nav_order__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `goal_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
i6robotics_control_msgs__action__NavOrder_Goal__init(i6robotics_control_msgs__action__NavOrder_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // goal_pose
  if (!geometry_msgs__msg__Pose__init(&msg->goal_pose)) {
    i6robotics_control_msgs__action__NavOrder_Goal__fini(msg);
    return false;
  }
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_Goal__fini(i6robotics_control_msgs__action__NavOrder_Goal * msg)
{
  if (!msg) {
    return;
  }
  // goal_pose
  geometry_msgs__msg__Pose__fini(&msg->goal_pose);
}

bool
i6robotics_control_msgs__action__NavOrder_Goal__are_equal(const i6robotics_control_msgs__action__NavOrder_Goal * lhs, const i6robotics_control_msgs__action__NavOrder_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->goal_pose), &(rhs->goal_pose)))
  {
    return false;
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_Goal__copy(
  const i6robotics_control_msgs__action__NavOrder_Goal * input,
  i6robotics_control_msgs__action__NavOrder_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->goal_pose), &(output->goal_pose)))
  {
    return false;
  }
  return true;
}

i6robotics_control_msgs__action__NavOrder_Goal *
i6robotics_control_msgs__action__NavOrder_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_Goal * msg = (i6robotics_control_msgs__action__NavOrder_Goal *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__action__NavOrder_Goal));
  bool success = i6robotics_control_msgs__action__NavOrder_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__action__NavOrder_Goal__destroy(i6robotics_control_msgs__action__NavOrder_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__action__NavOrder_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__init(i6robotics_control_msgs__action__NavOrder_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_Goal * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__action__NavOrder_Goal *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__action__NavOrder_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__action__NavOrder_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__action__NavOrder_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__fini(i6robotics_control_msgs__action__NavOrder_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      i6robotics_control_msgs__action__NavOrder_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

i6robotics_control_msgs__action__NavOrder_Goal__Sequence *
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_Goal__Sequence * array = (i6robotics_control_msgs__action__NavOrder_Goal__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__action__NavOrder_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__action__NavOrder_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_Goal__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_Goal__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_Goal__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__action__NavOrder_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__action__NavOrder_Goal * data =
      (i6robotics_control_msgs__action__NavOrder_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__action__NavOrder_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__action__NavOrder_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
#include "rosidl_runtime_c/string_functions.h"

bool
i6robotics_control_msgs__action__NavOrder_Result__init(i6robotics_control_msgs__action__NavOrder_Result * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__init(&msg->result)) {
    i6robotics_control_msgs__action__NavOrder_Result__fini(msg);
    return false;
  }
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_Result__fini(i6robotics_control_msgs__action__NavOrder_Result * msg)
{
  if (!msg) {
    return;
  }
  // result
  rosidl_runtime_c__String__fini(&msg->result);
}

bool
i6robotics_control_msgs__action__NavOrder_Result__are_equal(const i6robotics_control_msgs__action__NavOrder_Result * lhs, const i6robotics_control_msgs__action__NavOrder_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_Result__copy(
  const i6robotics_control_msgs__action__NavOrder_Result * input,
  i6robotics_control_msgs__action__NavOrder_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

i6robotics_control_msgs__action__NavOrder_Result *
i6robotics_control_msgs__action__NavOrder_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_Result * msg = (i6robotics_control_msgs__action__NavOrder_Result *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__action__NavOrder_Result));
  bool success = i6robotics_control_msgs__action__NavOrder_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__action__NavOrder_Result__destroy(i6robotics_control_msgs__action__NavOrder_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__action__NavOrder_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__action__NavOrder_Result__Sequence__init(i6robotics_control_msgs__action__NavOrder_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_Result * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__action__NavOrder_Result *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__action__NavOrder_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__action__NavOrder_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__action__NavOrder_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_Result__Sequence__fini(i6robotics_control_msgs__action__NavOrder_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      i6robotics_control_msgs__action__NavOrder_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

i6robotics_control_msgs__action__NavOrder_Result__Sequence *
i6robotics_control_msgs__action__NavOrder_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_Result__Sequence * array = (i6robotics_control_msgs__action__NavOrder_Result__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__action__NavOrder_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__action__NavOrder_Result__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__action__NavOrder_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__action__NavOrder_Result__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_Result__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_Result__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_Result__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__action__NavOrder_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__action__NavOrder_Result * data =
      (i6robotics_control_msgs__action__NavOrder_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__action__NavOrder_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__action__NavOrder_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `current_pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
i6robotics_control_msgs__action__NavOrder_Feedback__init(i6robotics_control_msgs__action__NavOrder_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // current_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->current_pose)) {
    i6robotics_control_msgs__action__NavOrder_Feedback__fini(msg);
    return false;
  }
  // distance_remaining
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_Feedback__fini(i6robotics_control_msgs__action__NavOrder_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // current_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->current_pose);
  // distance_remaining
}

bool
i6robotics_control_msgs__action__NavOrder_Feedback__are_equal(const i6robotics_control_msgs__action__NavOrder_Feedback * lhs, const i6robotics_control_msgs__action__NavOrder_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->current_pose), &(rhs->current_pose)))
  {
    return false;
  }
  // distance_remaining
  if (lhs->distance_remaining != rhs->distance_remaining) {
    return false;
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_Feedback__copy(
  const i6robotics_control_msgs__action__NavOrder_Feedback * input,
  i6robotics_control_msgs__action__NavOrder_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // current_pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->current_pose), &(output->current_pose)))
  {
    return false;
  }
  // distance_remaining
  output->distance_remaining = input->distance_remaining;
  return true;
}

i6robotics_control_msgs__action__NavOrder_Feedback *
i6robotics_control_msgs__action__NavOrder_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_Feedback * msg = (i6robotics_control_msgs__action__NavOrder_Feedback *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__action__NavOrder_Feedback));
  bool success = i6robotics_control_msgs__action__NavOrder_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__action__NavOrder_Feedback__destroy(i6robotics_control_msgs__action__NavOrder_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__action__NavOrder_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__init(i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_Feedback * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__action__NavOrder_Feedback *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__action__NavOrder_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__action__NavOrder_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__action__NavOrder_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__fini(i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      i6robotics_control_msgs__action__NavOrder_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

i6robotics_control_msgs__action__NavOrder_Feedback__Sequence *
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * array = (i6robotics_control_msgs__action__NavOrder_Feedback__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_Feedback__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__action__NavOrder_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__action__NavOrder_Feedback * data =
      (i6robotics_control_msgs__action__NavOrder_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__action__NavOrder_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__action__NavOrder_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "i6robotics_control_msgs/action/detail/nav_order__functions.h"

bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__init(i6robotics_control_msgs__action__NavOrder_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    i6robotics_control_msgs__action__NavOrder_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!i6robotics_control_msgs__action__NavOrder_Goal__init(&msg->goal)) {
    i6robotics_control_msgs__action__NavOrder_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__fini(i6robotics_control_msgs__action__NavOrder_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  i6robotics_control_msgs__action__NavOrder_Goal__fini(&msg->goal);
}

bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__are_equal(const i6robotics_control_msgs__action__NavOrder_SendGoal_Request * lhs, const i6robotics_control_msgs__action__NavOrder_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!i6robotics_control_msgs__action__NavOrder_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__copy(
  const i6robotics_control_msgs__action__NavOrder_SendGoal_Request * input,
  i6robotics_control_msgs__action__NavOrder_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!i6robotics_control_msgs__action__NavOrder_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

i6robotics_control_msgs__action__NavOrder_SendGoal_Request *
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_SendGoal_Request * msg = (i6robotics_control_msgs__action__NavOrder_SendGoal_Request *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__action__NavOrder_SendGoal_Request));
  bool success = i6robotics_control_msgs__action__NavOrder_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__destroy(i6robotics_control_msgs__action__NavOrder_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__action__NavOrder_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__init(i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_SendGoal_Request * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__action__NavOrder_SendGoal_Request *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__action__NavOrder_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__action__NavOrder_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__action__NavOrder_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__fini(i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      i6robotics_control_msgs__action__NavOrder_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence *
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * array = (i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__action__NavOrder_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__action__NavOrder_SendGoal_Request * data =
      (i6robotics_control_msgs__action__NavOrder_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__action__NavOrder_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__action__NavOrder_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__init(i6robotics_control_msgs__action__NavOrder_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    i6robotics_control_msgs__action__NavOrder_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__fini(i6robotics_control_msgs__action__NavOrder_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__are_equal(const i6robotics_control_msgs__action__NavOrder_SendGoal_Response * lhs, const i6robotics_control_msgs__action__NavOrder_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__copy(
  const i6robotics_control_msgs__action__NavOrder_SendGoal_Response * input,
  i6robotics_control_msgs__action__NavOrder_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

i6robotics_control_msgs__action__NavOrder_SendGoal_Response *
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_SendGoal_Response * msg = (i6robotics_control_msgs__action__NavOrder_SendGoal_Response *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__action__NavOrder_SendGoal_Response));
  bool success = i6robotics_control_msgs__action__NavOrder_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__destroy(i6robotics_control_msgs__action__NavOrder_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__action__NavOrder_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__init(i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_SendGoal_Response * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__action__NavOrder_SendGoal_Response *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__action__NavOrder_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__action__NavOrder_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__action__NavOrder_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__fini(i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      i6robotics_control_msgs__action__NavOrder_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence *
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * array = (i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__action__NavOrder_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__action__NavOrder_SendGoal_Response * data =
      (i6robotics_control_msgs__action__NavOrder_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__action__NavOrder_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__action__NavOrder_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
i6robotics_control_msgs__action__NavOrder_GetResult_Request__init(i6robotics_control_msgs__action__NavOrder_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    i6robotics_control_msgs__action__NavOrder_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_GetResult_Request__fini(i6robotics_control_msgs__action__NavOrder_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
i6robotics_control_msgs__action__NavOrder_GetResult_Request__are_equal(const i6robotics_control_msgs__action__NavOrder_GetResult_Request * lhs, const i6robotics_control_msgs__action__NavOrder_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_GetResult_Request__copy(
  const i6robotics_control_msgs__action__NavOrder_GetResult_Request * input,
  i6robotics_control_msgs__action__NavOrder_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

i6robotics_control_msgs__action__NavOrder_GetResult_Request *
i6robotics_control_msgs__action__NavOrder_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_GetResult_Request * msg = (i6robotics_control_msgs__action__NavOrder_GetResult_Request *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__action__NavOrder_GetResult_Request));
  bool success = i6robotics_control_msgs__action__NavOrder_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__action__NavOrder_GetResult_Request__destroy(i6robotics_control_msgs__action__NavOrder_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__action__NavOrder_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__init(i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_GetResult_Request * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__action__NavOrder_GetResult_Request *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__action__NavOrder_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__action__NavOrder_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__action__NavOrder_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__fini(i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      i6robotics_control_msgs__action__NavOrder_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence *
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * array = (i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__action__NavOrder_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__action__NavOrder_GetResult_Request * data =
      (i6robotics_control_msgs__action__NavOrder_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__action__NavOrder_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__action__NavOrder_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "i6robotics_control_msgs/action/detail/nav_order__functions.h"

bool
i6robotics_control_msgs__action__NavOrder_GetResult_Response__init(i6robotics_control_msgs__action__NavOrder_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!i6robotics_control_msgs__action__NavOrder_Result__init(&msg->result)) {
    i6robotics_control_msgs__action__NavOrder_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_GetResult_Response__fini(i6robotics_control_msgs__action__NavOrder_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  i6robotics_control_msgs__action__NavOrder_Result__fini(&msg->result);
}

bool
i6robotics_control_msgs__action__NavOrder_GetResult_Response__are_equal(const i6robotics_control_msgs__action__NavOrder_GetResult_Response * lhs, const i6robotics_control_msgs__action__NavOrder_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!i6robotics_control_msgs__action__NavOrder_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_GetResult_Response__copy(
  const i6robotics_control_msgs__action__NavOrder_GetResult_Response * input,
  i6robotics_control_msgs__action__NavOrder_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!i6robotics_control_msgs__action__NavOrder_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

i6robotics_control_msgs__action__NavOrder_GetResult_Response *
i6robotics_control_msgs__action__NavOrder_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_GetResult_Response * msg = (i6robotics_control_msgs__action__NavOrder_GetResult_Response *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__action__NavOrder_GetResult_Response));
  bool success = i6robotics_control_msgs__action__NavOrder_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__action__NavOrder_GetResult_Response__destroy(i6robotics_control_msgs__action__NavOrder_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__action__NavOrder_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__init(i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_GetResult_Response * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__action__NavOrder_GetResult_Response *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__action__NavOrder_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__action__NavOrder_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__action__NavOrder_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__fini(i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      i6robotics_control_msgs__action__NavOrder_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence *
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * array = (i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__action__NavOrder_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__action__NavOrder_GetResult_Response * data =
      (i6robotics_control_msgs__action__NavOrder_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__action__NavOrder_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__action__NavOrder_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "i6robotics_control_msgs/action/detail/nav_order__functions.h"

bool
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__init(i6robotics_control_msgs__action__NavOrder_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    i6robotics_control_msgs__action__NavOrder_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!i6robotics_control_msgs__action__NavOrder_Feedback__init(&msg->feedback)) {
    i6robotics_control_msgs__action__NavOrder_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__fini(i6robotics_control_msgs__action__NavOrder_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  i6robotics_control_msgs__action__NavOrder_Feedback__fini(&msg->feedback);
}

bool
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__are_equal(const i6robotics_control_msgs__action__NavOrder_FeedbackMessage * lhs, const i6robotics_control_msgs__action__NavOrder_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!i6robotics_control_msgs__action__NavOrder_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__copy(
  const i6robotics_control_msgs__action__NavOrder_FeedbackMessage * input,
  i6robotics_control_msgs__action__NavOrder_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!i6robotics_control_msgs__action__NavOrder_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

i6robotics_control_msgs__action__NavOrder_FeedbackMessage *
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_FeedbackMessage * msg = (i6robotics_control_msgs__action__NavOrder_FeedbackMessage *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__action__NavOrder_FeedbackMessage));
  bool success = i6robotics_control_msgs__action__NavOrder_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__destroy(i6robotics_control_msgs__action__NavOrder_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__action__NavOrder_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__init(i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_FeedbackMessage * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__action__NavOrder_FeedbackMessage *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__action__NavOrder_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__action__NavOrder_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__action__NavOrder_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__fini(i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      i6robotics_control_msgs__action__NavOrder_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence *
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * array = (i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__destroy(i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__are_equal(const i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * lhs, const i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence__copy(
  const i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * input,
  i6robotics_control_msgs__action__NavOrder_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__action__NavOrder_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__action__NavOrder_FeedbackMessage * data =
      (i6robotics_control_msgs__action__NavOrder_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__action__NavOrder_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__action__NavOrder_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__action__NavOrder_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
