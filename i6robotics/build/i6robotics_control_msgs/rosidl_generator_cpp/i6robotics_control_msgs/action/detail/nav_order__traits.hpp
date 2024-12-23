// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from i6robotics_control_msgs:action/NavOrder.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__NAV_ORDER__TRAITS_HPP_
#define I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__NAV_ORDER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "i6robotics_control_msgs/action/detail/nav_order__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace i6robotics_control_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavOrder_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_pose
  {
    out << "goal_pose: ";
    to_flow_style_yaml(msg.goal_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavOrder_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_pose:\n";
    to_block_style_yaml(msg.goal_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavOrder_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::action::NavOrder_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::action::NavOrder_Goal & msg)
{
  return i6robotics_control_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::action::NavOrder_Goal>()
{
  return "i6robotics_control_msgs::action::NavOrder_Goal";
}

template<>
inline const char * name<i6robotics_control_msgs::action::NavOrder_Goal>()
{
  return "i6robotics_control_msgs/action/NavOrder_Goal";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::action::NavOrder_Goal>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::action::NavOrder_Goal>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<i6robotics_control_msgs::action::NavOrder_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace i6robotics_control_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavOrder_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavOrder_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavOrder_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::action::NavOrder_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::action::NavOrder_Result & msg)
{
  return i6robotics_control_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::action::NavOrder_Result>()
{
  return "i6robotics_control_msgs::action::NavOrder_Result";
}

template<>
inline const char * name<i6robotics_control_msgs::action::NavOrder_Result>()
{
  return "i6robotics_control_msgs/action/NavOrder_Result";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::action::NavOrder_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::action::NavOrder_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<i6robotics_control_msgs::action::NavOrder_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace i6robotics_control_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavOrder_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_pose
  {
    out << "current_pose: ";
    to_flow_style_yaml(msg.current_pose, out);
    out << ", ";
  }

  // member: distance_remaining
  {
    out << "distance_remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_remaining, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavOrder_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_pose:\n";
    to_block_style_yaml(msg.current_pose, out, indentation + 2);
  }

  // member: distance_remaining
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_remaining, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavOrder_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::action::NavOrder_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::action::NavOrder_Feedback & msg)
{
  return i6robotics_control_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::action::NavOrder_Feedback>()
{
  return "i6robotics_control_msgs::action::NavOrder_Feedback";
}

template<>
inline const char * name<i6robotics_control_msgs::action::NavOrder_Feedback>()
{
  return "i6robotics_control_msgs/action/NavOrder_Feedback";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::action::NavOrder_Feedback>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::action::NavOrder_Feedback>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct is_message<i6robotics_control_msgs::action::NavOrder_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "i6robotics_control_msgs/action/detail/nav_order__traits.hpp"

namespace i6robotics_control_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavOrder_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavOrder_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavOrder_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::action::NavOrder_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::action::NavOrder_SendGoal_Request & msg)
{
  return i6robotics_control_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::action::NavOrder_SendGoal_Request>()
{
  return "i6robotics_control_msgs::action::NavOrder_SendGoal_Request";
}

template<>
inline const char * name<i6robotics_control_msgs::action::NavOrder_SendGoal_Request>()
{
  return "i6robotics_control_msgs/action/NavOrder_SendGoal_Request";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::action::NavOrder_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<i6robotics_control_msgs::action::NavOrder_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::action::NavOrder_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<i6robotics_control_msgs::action::NavOrder_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<i6robotics_control_msgs::action::NavOrder_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace i6robotics_control_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavOrder_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavOrder_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavOrder_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::action::NavOrder_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::action::NavOrder_SendGoal_Response & msg)
{
  return i6robotics_control_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::action::NavOrder_SendGoal_Response>()
{
  return "i6robotics_control_msgs::action::NavOrder_SendGoal_Response";
}

template<>
inline const char * name<i6robotics_control_msgs::action::NavOrder_SendGoal_Response>()
{
  return "i6robotics_control_msgs/action/NavOrder_SendGoal_Response";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::action::NavOrder_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::action::NavOrder_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<i6robotics_control_msgs::action::NavOrder_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<i6robotics_control_msgs::action::NavOrder_SendGoal>()
{
  return "i6robotics_control_msgs::action::NavOrder_SendGoal";
}

template<>
inline const char * name<i6robotics_control_msgs::action::NavOrder_SendGoal>()
{
  return "i6robotics_control_msgs/action/NavOrder_SendGoal";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::action::NavOrder_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<i6robotics_control_msgs::action::NavOrder_SendGoal_Request>::value &&
    has_fixed_size<i6robotics_control_msgs::action::NavOrder_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<i6robotics_control_msgs::action::NavOrder_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<i6robotics_control_msgs::action::NavOrder_SendGoal_Request>::value &&
    has_bounded_size<i6robotics_control_msgs::action::NavOrder_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<i6robotics_control_msgs::action::NavOrder_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<i6robotics_control_msgs::action::NavOrder_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<i6robotics_control_msgs::action::NavOrder_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace i6robotics_control_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavOrder_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavOrder_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavOrder_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::action::NavOrder_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::action::NavOrder_GetResult_Request & msg)
{
  return i6robotics_control_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::action::NavOrder_GetResult_Request>()
{
  return "i6robotics_control_msgs::action::NavOrder_GetResult_Request";
}

template<>
inline const char * name<i6robotics_control_msgs::action::NavOrder_GetResult_Request>()
{
  return "i6robotics_control_msgs/action/NavOrder_GetResult_Request";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::action::NavOrder_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::action::NavOrder_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<i6robotics_control_msgs::action::NavOrder_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "i6robotics_control_msgs/action/detail/nav_order__traits.hpp"

namespace i6robotics_control_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavOrder_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavOrder_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavOrder_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::action::NavOrder_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::action::NavOrder_GetResult_Response & msg)
{
  return i6robotics_control_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::action::NavOrder_GetResult_Response>()
{
  return "i6robotics_control_msgs::action::NavOrder_GetResult_Response";
}

template<>
inline const char * name<i6robotics_control_msgs::action::NavOrder_GetResult_Response>()
{
  return "i6robotics_control_msgs/action/NavOrder_GetResult_Response";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::action::NavOrder_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<i6robotics_control_msgs::action::NavOrder_Result>::value> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::action::NavOrder_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<i6robotics_control_msgs::action::NavOrder_Result>::value> {};

template<>
struct is_message<i6robotics_control_msgs::action::NavOrder_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<i6robotics_control_msgs::action::NavOrder_GetResult>()
{
  return "i6robotics_control_msgs::action::NavOrder_GetResult";
}

template<>
inline const char * name<i6robotics_control_msgs::action::NavOrder_GetResult>()
{
  return "i6robotics_control_msgs/action/NavOrder_GetResult";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::action::NavOrder_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<i6robotics_control_msgs::action::NavOrder_GetResult_Request>::value &&
    has_fixed_size<i6robotics_control_msgs::action::NavOrder_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<i6robotics_control_msgs::action::NavOrder_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<i6robotics_control_msgs::action::NavOrder_GetResult_Request>::value &&
    has_bounded_size<i6robotics_control_msgs::action::NavOrder_GetResult_Response>::value
  >
{
};

template<>
struct is_service<i6robotics_control_msgs::action::NavOrder_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<i6robotics_control_msgs::action::NavOrder_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<i6robotics_control_msgs::action::NavOrder_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "i6robotics_control_msgs/action/detail/nav_order__traits.hpp"

namespace i6robotics_control_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavOrder_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavOrder_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavOrder_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::action::NavOrder_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::action::NavOrder_FeedbackMessage & msg)
{
  return i6robotics_control_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::action::NavOrder_FeedbackMessage>()
{
  return "i6robotics_control_msgs::action::NavOrder_FeedbackMessage";
}

template<>
inline const char * name<i6robotics_control_msgs::action::NavOrder_FeedbackMessage>()
{
  return "i6robotics_control_msgs/action/NavOrder_FeedbackMessage";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::action::NavOrder_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<i6robotics_control_msgs::action::NavOrder_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::action::NavOrder_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<i6robotics_control_msgs::action::NavOrder_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<i6robotics_control_msgs::action::NavOrder_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<i6robotics_control_msgs::action::NavOrder>
  : std::true_type
{
};

template<>
struct is_action_goal<i6robotics_control_msgs::action::NavOrder_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<i6robotics_control_msgs::action::NavOrder_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<i6robotics_control_msgs::action::NavOrder_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__NAV_ORDER__TRAITS_HPP_
