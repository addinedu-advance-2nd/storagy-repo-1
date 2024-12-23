// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from i6robotics_control_msgs:action/Follow.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "i6robotics_control_msgs/action/detail/follow__struct.h"
#include "i6robotics_control_msgs/action/detail/follow__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace i6robotics_control_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Follow_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Follow_Goal_type_support_ids_t;

static const _Follow_Goal_type_support_ids_t _Follow_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Follow_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Follow_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Follow_Goal_type_support_symbol_names_t _Follow_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i6robotics_control_msgs, action, Follow_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, action, Follow_Goal)),
  }
};

typedef struct _Follow_Goal_type_support_data_t
{
  void * data[2];
} _Follow_Goal_type_support_data_t;

static _Follow_Goal_type_support_data_t _Follow_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Follow_Goal_message_typesupport_map = {
  2,
  "i6robotics_control_msgs",
  &_Follow_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Follow_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Follow_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Follow_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Follow_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace i6robotics_control_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_Goal)() {
  return &::i6robotics_control_msgs::action::rosidl_typesupport_c::Follow_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i6robotics_control_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Follow_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Follow_Result_type_support_ids_t;

static const _Follow_Result_type_support_ids_t _Follow_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Follow_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Follow_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Follow_Result_type_support_symbol_names_t _Follow_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i6robotics_control_msgs, action, Follow_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, action, Follow_Result)),
  }
};

typedef struct _Follow_Result_type_support_data_t
{
  void * data[2];
} _Follow_Result_type_support_data_t;

static _Follow_Result_type_support_data_t _Follow_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Follow_Result_message_typesupport_map = {
  2,
  "i6robotics_control_msgs",
  &_Follow_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Follow_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Follow_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Follow_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Follow_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace i6robotics_control_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_Result)() {
  return &::i6robotics_control_msgs::action::rosidl_typesupport_c::Follow_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i6robotics_control_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Follow_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Follow_Feedback_type_support_ids_t;

static const _Follow_Feedback_type_support_ids_t _Follow_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Follow_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Follow_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Follow_Feedback_type_support_symbol_names_t _Follow_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i6robotics_control_msgs, action, Follow_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, action, Follow_Feedback)),
  }
};

typedef struct _Follow_Feedback_type_support_data_t
{
  void * data[2];
} _Follow_Feedback_type_support_data_t;

static _Follow_Feedback_type_support_data_t _Follow_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Follow_Feedback_message_typesupport_map = {
  2,
  "i6robotics_control_msgs",
  &_Follow_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Follow_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Follow_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Follow_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Follow_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace i6robotics_control_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_Feedback)() {
  return &::i6robotics_control_msgs::action::rosidl_typesupport_c::Follow_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i6robotics_control_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Follow_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Follow_SendGoal_Request_type_support_ids_t;

static const _Follow_SendGoal_Request_type_support_ids_t _Follow_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Follow_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Follow_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Follow_SendGoal_Request_type_support_symbol_names_t _Follow_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i6robotics_control_msgs, action, Follow_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, action, Follow_SendGoal_Request)),
  }
};

typedef struct _Follow_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Follow_SendGoal_Request_type_support_data_t;

static _Follow_SendGoal_Request_type_support_data_t _Follow_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Follow_SendGoal_Request_message_typesupport_map = {
  2,
  "i6robotics_control_msgs",
  &_Follow_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Follow_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Follow_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Follow_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Follow_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace i6robotics_control_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_SendGoal_Request)() {
  return &::i6robotics_control_msgs::action::rosidl_typesupport_c::Follow_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i6robotics_control_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Follow_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Follow_SendGoal_Response_type_support_ids_t;

static const _Follow_SendGoal_Response_type_support_ids_t _Follow_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Follow_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Follow_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Follow_SendGoal_Response_type_support_symbol_names_t _Follow_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i6robotics_control_msgs, action, Follow_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, action, Follow_SendGoal_Response)),
  }
};

typedef struct _Follow_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Follow_SendGoal_Response_type_support_data_t;

static _Follow_SendGoal_Response_type_support_data_t _Follow_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Follow_SendGoal_Response_message_typesupport_map = {
  2,
  "i6robotics_control_msgs",
  &_Follow_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Follow_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Follow_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Follow_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Follow_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace i6robotics_control_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_SendGoal_Response)() {
  return &::i6robotics_control_msgs::action::rosidl_typesupport_c::Follow_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i6robotics_control_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Follow_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Follow_SendGoal_type_support_ids_t;

static const _Follow_SendGoal_type_support_ids_t _Follow_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Follow_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Follow_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Follow_SendGoal_type_support_symbol_names_t _Follow_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i6robotics_control_msgs, action, Follow_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, action, Follow_SendGoal)),
  }
};

typedef struct _Follow_SendGoal_type_support_data_t
{
  void * data[2];
} _Follow_SendGoal_type_support_data_t;

static _Follow_SendGoal_type_support_data_t _Follow_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Follow_SendGoal_service_typesupport_map = {
  2,
  "i6robotics_control_msgs",
  &_Follow_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Follow_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Follow_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Follow_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Follow_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace i6robotics_control_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_SendGoal)() {
  return &::i6robotics_control_msgs::action::rosidl_typesupport_c::Follow_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i6robotics_control_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Follow_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Follow_GetResult_Request_type_support_ids_t;

static const _Follow_GetResult_Request_type_support_ids_t _Follow_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Follow_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Follow_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Follow_GetResult_Request_type_support_symbol_names_t _Follow_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i6robotics_control_msgs, action, Follow_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, action, Follow_GetResult_Request)),
  }
};

typedef struct _Follow_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Follow_GetResult_Request_type_support_data_t;

static _Follow_GetResult_Request_type_support_data_t _Follow_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Follow_GetResult_Request_message_typesupport_map = {
  2,
  "i6robotics_control_msgs",
  &_Follow_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Follow_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Follow_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Follow_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Follow_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace i6robotics_control_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_GetResult_Request)() {
  return &::i6robotics_control_msgs::action::rosidl_typesupport_c::Follow_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i6robotics_control_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Follow_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Follow_GetResult_Response_type_support_ids_t;

static const _Follow_GetResult_Response_type_support_ids_t _Follow_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Follow_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Follow_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Follow_GetResult_Response_type_support_symbol_names_t _Follow_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i6robotics_control_msgs, action, Follow_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, action, Follow_GetResult_Response)),
  }
};

typedef struct _Follow_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Follow_GetResult_Response_type_support_data_t;

static _Follow_GetResult_Response_type_support_data_t _Follow_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Follow_GetResult_Response_message_typesupport_map = {
  2,
  "i6robotics_control_msgs",
  &_Follow_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Follow_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Follow_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Follow_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Follow_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace i6robotics_control_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_GetResult_Response)() {
  return &::i6robotics_control_msgs::action::rosidl_typesupport_c::Follow_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i6robotics_control_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Follow_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Follow_GetResult_type_support_ids_t;

static const _Follow_GetResult_type_support_ids_t _Follow_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Follow_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Follow_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Follow_GetResult_type_support_symbol_names_t _Follow_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i6robotics_control_msgs, action, Follow_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, action, Follow_GetResult)),
  }
};

typedef struct _Follow_GetResult_type_support_data_t
{
  void * data[2];
} _Follow_GetResult_type_support_data_t;

static _Follow_GetResult_type_support_data_t _Follow_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Follow_GetResult_service_typesupport_map = {
  2,
  "i6robotics_control_msgs",
  &_Follow_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Follow_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Follow_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Follow_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Follow_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace i6robotics_control_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_GetResult)() {
  return &::i6robotics_control_msgs::action::rosidl_typesupport_c::Follow_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__struct.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace i6robotics_control_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Follow_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Follow_FeedbackMessage_type_support_ids_t;

static const _Follow_FeedbackMessage_type_support_ids_t _Follow_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Follow_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Follow_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Follow_FeedbackMessage_type_support_symbol_names_t _Follow_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, i6robotics_control_msgs, action, Follow_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, i6robotics_control_msgs, action, Follow_FeedbackMessage)),
  }
};

typedef struct _Follow_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Follow_FeedbackMessage_type_support_data_t;

static _Follow_FeedbackMessage_type_support_data_t _Follow_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Follow_FeedbackMessage_message_typesupport_map = {
  2,
  "i6robotics_control_msgs",
  &_Follow_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Follow_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Follow_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Follow_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Follow_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace i6robotics_control_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_FeedbackMessage)() {
  return &::i6robotics_control_msgs::action::rosidl_typesupport_c::Follow_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "i6robotics_control_msgs/action/follow.h"
// already included above
// #include "i6robotics_control_msgs/action/detail/follow__type_support.h"

static rosidl_action_type_support_t _i6robotics_control_msgs__action__Follow__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, i6robotics_control_msgs, action, Follow)()
{
  // Thread-safe by always writing the same values to the static struct
  _i6robotics_control_msgs__action__Follow__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_SendGoal)();
  _i6robotics_control_msgs__action__Follow__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_GetResult)();
  _i6robotics_control_msgs__action__Follow__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _i6robotics_control_msgs__action__Follow__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, i6robotics_control_msgs, action, Follow_FeedbackMessage)();
  _i6robotics_control_msgs__action__Follow__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_i6robotics_control_msgs__action__Follow__typesupport_c;
}

#ifdef __cplusplus
}
#endif
