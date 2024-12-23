// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from i6robotics_control_msgs:srv/Order.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "i6robotics_control_msgs/srv/detail/order__rosidl_typesupport_introspection_c.h"
#include "i6robotics_control_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "i6robotics_control_msgs/srv/detail/order__functions.h"
#include "i6robotics_control_msgs/srv/detail/order__struct.h"


// Include directives for member types
// Member `order`
#include "rosidl_runtime_c/string_functions.h"
// Member `goal_pose`
#include "geometry_msgs/msg/pose.h"
// Member `goal_pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  i6robotics_control_msgs__srv__Order_Request__init(message_memory);
}

void i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_fini_function(void * message_memory)
{
  i6robotics_control_msgs__srv__Order_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_message_member_array[2] = {
  {
    "order",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i6robotics_control_msgs__srv__Order_Request, order),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i6robotics_control_msgs__srv__Order_Request, goal_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_message_members = {
  "i6robotics_control_msgs__srv",  // message namespace
  "Order_Request",  // message name
  2,  // number of fields
  sizeof(i6robotics_control_msgs__srv__Order_Request),
  i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_message_member_array,  // message members
  i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_message_type_support_handle = {
  0,
  &i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_i6robotics_control_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, srv, Order_Request)() {
  i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_message_type_support_handle.typesupport_identifier) {
    i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &i6robotics_control_msgs__srv__Order_Request__rosidl_typesupport_introspection_c__Order_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "i6robotics_control_msgs/srv/detail/order__rosidl_typesupport_introspection_c.h"
// already included above
// #include "i6robotics_control_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "i6robotics_control_msgs/srv/detail/order__functions.h"
// already included above
// #include "i6robotics_control_msgs/srv/detail/order__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  i6robotics_control_msgs__srv__Order_Response__init(message_memory);
}

void i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_fini_function(void * message_memory)
{
  i6robotics_control_msgs__srv__Order_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_message_member_array[1] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(i6robotics_control_msgs__srv__Order_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_message_members = {
  "i6robotics_control_msgs__srv",  // message namespace
  "Order_Response",  // message name
  1,  // number of fields
  sizeof(i6robotics_control_msgs__srv__Order_Response),
  i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_message_member_array,  // message members
  i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_message_type_support_handle = {
  0,
  &i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_i6robotics_control_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, srv, Order_Response)() {
  if (!i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_message_type_support_handle.typesupport_identifier) {
    i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &i6robotics_control_msgs__srv__Order_Response__rosidl_typesupport_introspection_c__Order_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "i6robotics_control_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "i6robotics_control_msgs/srv/detail/order__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers i6robotics_control_msgs__srv__detail__order__rosidl_typesupport_introspection_c__Order_service_members = {
  "i6robotics_control_msgs__srv",  // service namespace
  "Order",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // i6robotics_control_msgs__srv__detail__order__rosidl_typesupport_introspection_c__Order_Request_message_type_support_handle,
  NULL  // response message
  // i6robotics_control_msgs__srv__detail__order__rosidl_typesupport_introspection_c__Order_Response_message_type_support_handle
};

static rosidl_service_type_support_t i6robotics_control_msgs__srv__detail__order__rosidl_typesupport_introspection_c__Order_service_type_support_handle = {
  0,
  &i6robotics_control_msgs__srv__detail__order__rosidl_typesupport_introspection_c__Order_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, srv, Order_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, srv, Order_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_i6robotics_control_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, srv, Order)() {
  if (!i6robotics_control_msgs__srv__detail__order__rosidl_typesupport_introspection_c__Order_service_type_support_handle.typesupport_identifier) {
    i6robotics_control_msgs__srv__detail__order__rosidl_typesupport_introspection_c__Order_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)i6robotics_control_msgs__srv__detail__order__rosidl_typesupport_introspection_c__Order_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, srv, Order_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, srv, Order_Response)()->data;
  }

  return &i6robotics_control_msgs__srv__detail__order__rosidl_typesupport_introspection_c__Order_service_type_support_handle;
}
