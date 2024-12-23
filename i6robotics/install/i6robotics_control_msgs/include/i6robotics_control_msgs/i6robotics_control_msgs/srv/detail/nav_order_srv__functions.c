// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from i6robotics_control_msgs:srv/NavOrderSrv.idl
// generated code does not contain a copyright notice
#include "i6robotics_control_msgs/srv/detail/nav_order_srv__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `goal_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
i6robotics_control_msgs__srv__NavOrderSrv_Request__init(i6robotics_control_msgs__srv__NavOrderSrv_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_pose
  if (!geometry_msgs__msg__Pose__init(&msg->goal_pose)) {
    i6robotics_control_msgs__srv__NavOrderSrv_Request__fini(msg);
    return false;
  }
  return true;
}

void
i6robotics_control_msgs__srv__NavOrderSrv_Request__fini(i6robotics_control_msgs__srv__NavOrderSrv_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_pose
  geometry_msgs__msg__Pose__fini(&msg->goal_pose);
}

bool
i6robotics_control_msgs__srv__NavOrderSrv_Request__are_equal(const i6robotics_control_msgs__srv__NavOrderSrv_Request * lhs, const i6robotics_control_msgs__srv__NavOrderSrv_Request * rhs)
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
i6robotics_control_msgs__srv__NavOrderSrv_Request__copy(
  const i6robotics_control_msgs__srv__NavOrderSrv_Request * input,
  i6robotics_control_msgs__srv__NavOrderSrv_Request * output)
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

i6robotics_control_msgs__srv__NavOrderSrv_Request *
i6robotics_control_msgs__srv__NavOrderSrv_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__srv__NavOrderSrv_Request * msg = (i6robotics_control_msgs__srv__NavOrderSrv_Request *)allocator.allocate(sizeof(i6robotics_control_msgs__srv__NavOrderSrv_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__srv__NavOrderSrv_Request));
  bool success = i6robotics_control_msgs__srv__NavOrderSrv_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__srv__NavOrderSrv_Request__destroy(i6robotics_control_msgs__srv__NavOrderSrv_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__srv__NavOrderSrv_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence__init(i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__srv__NavOrderSrv_Request * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__srv__NavOrderSrv_Request *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__srv__NavOrderSrv_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__srv__NavOrderSrv_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__srv__NavOrderSrv_Request__fini(&data[i - 1]);
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
i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence__fini(i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence * array)
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
      i6robotics_control_msgs__srv__NavOrderSrv_Request__fini(&array->data[i]);
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

i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence *
i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence * array = (i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence__destroy(i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence__are_equal(const i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence * lhs, const i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__srv__NavOrderSrv_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence__copy(
  const i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence * input,
  i6robotics_control_msgs__srv__NavOrderSrv_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__srv__NavOrderSrv_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__srv__NavOrderSrv_Request * data =
      (i6robotics_control_msgs__srv__NavOrderSrv_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__srv__NavOrderSrv_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__srv__NavOrderSrv_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__srv__NavOrderSrv_Request__copy(
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
i6robotics_control_msgs__srv__NavOrderSrv_Response__init(i6robotics_control_msgs__srv__NavOrderSrv_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__init(&msg->result)) {
    i6robotics_control_msgs__srv__NavOrderSrv_Response__fini(msg);
    return false;
  }
  return true;
}

void
i6robotics_control_msgs__srv__NavOrderSrv_Response__fini(i6robotics_control_msgs__srv__NavOrderSrv_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  rosidl_runtime_c__String__fini(&msg->result);
}

bool
i6robotics_control_msgs__srv__NavOrderSrv_Response__are_equal(const i6robotics_control_msgs__srv__NavOrderSrv_Response * lhs, const i6robotics_control_msgs__srv__NavOrderSrv_Response * rhs)
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
i6robotics_control_msgs__srv__NavOrderSrv_Response__copy(
  const i6robotics_control_msgs__srv__NavOrderSrv_Response * input,
  i6robotics_control_msgs__srv__NavOrderSrv_Response * output)
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

i6robotics_control_msgs__srv__NavOrderSrv_Response *
i6robotics_control_msgs__srv__NavOrderSrv_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__srv__NavOrderSrv_Response * msg = (i6robotics_control_msgs__srv__NavOrderSrv_Response *)allocator.allocate(sizeof(i6robotics_control_msgs__srv__NavOrderSrv_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(i6robotics_control_msgs__srv__NavOrderSrv_Response));
  bool success = i6robotics_control_msgs__srv__NavOrderSrv_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
i6robotics_control_msgs__srv__NavOrderSrv_Response__destroy(i6robotics_control_msgs__srv__NavOrderSrv_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    i6robotics_control_msgs__srv__NavOrderSrv_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence__init(i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__srv__NavOrderSrv_Response * data = NULL;

  if (size) {
    data = (i6robotics_control_msgs__srv__NavOrderSrv_Response *)allocator.zero_allocate(size, sizeof(i6robotics_control_msgs__srv__NavOrderSrv_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = i6robotics_control_msgs__srv__NavOrderSrv_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        i6robotics_control_msgs__srv__NavOrderSrv_Response__fini(&data[i - 1]);
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
i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence__fini(i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence * array)
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
      i6robotics_control_msgs__srv__NavOrderSrv_Response__fini(&array->data[i]);
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

i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence *
i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence * array = (i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence *)allocator.allocate(sizeof(i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence__destroy(i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence__are_equal(const i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence * lhs, const i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!i6robotics_control_msgs__srv__NavOrderSrv_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence__copy(
  const i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence * input,
  i6robotics_control_msgs__srv__NavOrderSrv_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(i6robotics_control_msgs__srv__NavOrderSrv_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    i6robotics_control_msgs__srv__NavOrderSrv_Response * data =
      (i6robotics_control_msgs__srv__NavOrderSrv_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!i6robotics_control_msgs__srv__NavOrderSrv_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          i6robotics_control_msgs__srv__NavOrderSrv_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!i6robotics_control_msgs__srv__NavOrderSrv_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
