// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from i6robotics_control_msgs:srv/NavOrderSrv.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__TRAITS_HPP_
#define I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "i6robotics_control_msgs/srv/detail/nav_order_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace i6robotics_control_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const NavOrderSrv_Request & msg,
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
  const NavOrderSrv_Request & msg,
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

inline std::string to_yaml(const NavOrderSrv_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::srv::NavOrderSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::srv::NavOrderSrv_Request & msg)
{
  return i6robotics_control_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::srv::NavOrderSrv_Request>()
{
  return "i6robotics_control_msgs::srv::NavOrderSrv_Request";
}

template<>
inline const char * name<i6robotics_control_msgs::srv::NavOrderSrv_Request>()
{
  return "i6robotics_control_msgs/srv/NavOrderSrv_Request";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::srv::NavOrderSrv_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::srv::NavOrderSrv_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<i6robotics_control_msgs::srv::NavOrderSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace i6robotics_control_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const NavOrderSrv_Response & msg,
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
  const NavOrderSrv_Response & msg,
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

inline std::string to_yaml(const NavOrderSrv_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::srv::NavOrderSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::srv::NavOrderSrv_Response & msg)
{
  return i6robotics_control_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::srv::NavOrderSrv_Response>()
{
  return "i6robotics_control_msgs::srv::NavOrderSrv_Response";
}

template<>
inline const char * name<i6robotics_control_msgs::srv::NavOrderSrv_Response>()
{
  return "i6robotics_control_msgs/srv/NavOrderSrv_Response";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::srv::NavOrderSrv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::srv::NavOrderSrv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<i6robotics_control_msgs::srv::NavOrderSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<i6robotics_control_msgs::srv::NavOrderSrv>()
{
  return "i6robotics_control_msgs::srv::NavOrderSrv";
}

template<>
inline const char * name<i6robotics_control_msgs::srv::NavOrderSrv>()
{
  return "i6robotics_control_msgs/srv/NavOrderSrv";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::srv::NavOrderSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<i6robotics_control_msgs::srv::NavOrderSrv_Request>::value &&
    has_fixed_size<i6robotics_control_msgs::srv::NavOrderSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<i6robotics_control_msgs::srv::NavOrderSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<i6robotics_control_msgs::srv::NavOrderSrv_Request>::value &&
    has_bounded_size<i6robotics_control_msgs::srv::NavOrderSrv_Response>::value
  >
{
};

template<>
struct is_service<i6robotics_control_msgs::srv::NavOrderSrv>
  : std::true_type
{
};

template<>
struct is_service_request<i6robotics_control_msgs::srv::NavOrderSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<i6robotics_control_msgs::srv::NavOrderSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__TRAITS_HPP_
