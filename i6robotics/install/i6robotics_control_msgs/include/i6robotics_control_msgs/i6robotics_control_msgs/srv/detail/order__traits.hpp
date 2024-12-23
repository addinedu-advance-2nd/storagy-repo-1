// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from i6robotics_control_msgs:srv/Order.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__TRAITS_HPP_
#define I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "i6robotics_control_msgs/srv/detail/order__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace i6robotics_control_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Order_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: order
  {
    out << "order: ";
    rosidl_generator_traits::value_to_yaml(msg.order, out);
    out << ", ";
  }

  // member: goal_pose
  {
    out << "goal_pose: ";
    to_flow_style_yaml(msg.goal_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Order_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: order
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order: ";
    rosidl_generator_traits::value_to_yaml(msg.order, out);
    out << "\n";
  }

  // member: goal_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_pose:\n";
    to_block_style_yaml(msg.goal_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Order_Request & msg, bool use_flow_style = false)
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
  const i6robotics_control_msgs::srv::Order_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::srv::Order_Request & msg)
{
  return i6robotics_control_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::srv::Order_Request>()
{
  return "i6robotics_control_msgs::srv::Order_Request";
}

template<>
inline const char * name<i6robotics_control_msgs::srv::Order_Request>()
{
  return "i6robotics_control_msgs/srv/Order_Request";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::srv::Order_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::srv::Order_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<i6robotics_control_msgs::srv::Order_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace i6robotics_control_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Order_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Order_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Order_Response & msg, bool use_flow_style = false)
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
  const i6robotics_control_msgs::srv::Order_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::srv::Order_Response & msg)
{
  return i6robotics_control_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::srv::Order_Response>()
{
  return "i6robotics_control_msgs::srv::Order_Response";
}

template<>
inline const char * name<i6robotics_control_msgs::srv::Order_Response>()
{
  return "i6robotics_control_msgs/srv/Order_Response";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::srv::Order_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::srv::Order_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<i6robotics_control_msgs::srv::Order_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<i6robotics_control_msgs::srv::Order>()
{
  return "i6robotics_control_msgs::srv::Order";
}

template<>
inline const char * name<i6robotics_control_msgs::srv::Order>()
{
  return "i6robotics_control_msgs/srv/Order";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::srv::Order>
  : std::integral_constant<
    bool,
    has_fixed_size<i6robotics_control_msgs::srv::Order_Request>::value &&
    has_fixed_size<i6robotics_control_msgs::srv::Order_Response>::value
  >
{
};

template<>
struct has_bounded_size<i6robotics_control_msgs::srv::Order>
  : std::integral_constant<
    bool,
    has_bounded_size<i6robotics_control_msgs::srv::Order_Request>::value &&
    has_bounded_size<i6robotics_control_msgs::srv::Order_Response>::value
  >
{
};

template<>
struct is_service<i6robotics_control_msgs::srv::Order>
  : std::true_type
{
};

template<>
struct is_service_request<i6robotics_control_msgs::srv::Order_Request>
  : std::true_type
{
};

template<>
struct is_service_response<i6robotics_control_msgs::srv::Order_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__TRAITS_HPP_
