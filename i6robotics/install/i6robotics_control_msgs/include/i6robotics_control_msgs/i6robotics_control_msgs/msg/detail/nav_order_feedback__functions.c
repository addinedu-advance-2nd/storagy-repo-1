// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from i6robotics_control_msgs:msg/NavOrderFeedback.idl
// generated code does not contain a copyright notice
#include "i6robotics_control_msgs/msg/detail/nav_order_feedback__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `current_pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
i6robotics_control_msgs__msg__NavOrderFeedback__init(i6robotics_control_msgs__msg__NavOrderFeedback * msg)
{
  if (!msg) {
    return false;
  }
  // current_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->current_pose)) {
    i6robotics_control_msgs__msg__NavOrderFeedback__fini(msg);
    return false;
  }
  // distance_remaining
  return true;
}

void
i6robotics_control_msgs__msg__NavOrderFeedback__fini(i6robotics_control_msgs__msg__NavOrderFeedback * msg)
{
  if (!msg) {
    return;
  }
  // current_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->current_pose);
  // distance_remaining
}

bool
i6robotics_control_msgs__msg__NavOrderFeedback__are_equal(const i6robotics_control_msgs__msg__NavOrderFeedback * lhs, const i6robotics_control_msgs__msg__NavOrderFeedback * rhs)
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
i6robotics_control_msgs__msg__NavOrderFeedback__copy(
  const i6robotics_control_msgs__msg__NavOrderFeedback * input,
  i6robotics_control_msgs__msg__NavOrderFeedback * output)
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

i6robotics_control_msgs__msg__NavOrderFeedback *
i6robotics_control_msgs__msg__NavOrderFeedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__msg__NavOrderFeedback * msg = (i6robotics_control_msgs__msg__NavOrderFeedback *)allocator.allocate(sizeof(i6robotics_control_msgs__msg__NavOrderFeedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__msg__NavOrderFeedback));
  bool success = i6robotics_control_msgs__msg__NavOrderFeedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__msg__NavOrderFeedback__destroy(i6robotics_control_msgs__msg__NavOrderFeedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__msg__NavOrderFeedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__init(i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__msg__NavOrderFeedback * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__msg__NavOrderFeedback *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__msg__NavOrderFeedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__msg__NavOrderFeedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__msg__NavOrderFeedback__fini(&data[i - 1]);
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
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__fini(i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * array)
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
      i6robotics_control_msgs__msg__NavOrderFeedback__fini(&array->data[i]);
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

i6robotics_control_msgs__msg__NavOrderFeedback__Sequence *
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * array = (i6robotics_control_msgs__msg__NavOrderFeedback__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__msg__NavOrderFeedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__destroy(i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__are_equal(const i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * lhs, const i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__msg__NavOrderFeedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__msg__NavOrderFeedback__Sequence__copy(
  const i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * input,
  i6robotics_control_msgs__msg__NavOrderFeedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__msg__NavOrderFeedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__msg__NavOrderFeedback * data =
      (i6robotics_control_msgs__msg__NavOrderFeedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__msg__NavOrderFeedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__msg__NavOrderFeedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__msg__NavOrderFeedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
