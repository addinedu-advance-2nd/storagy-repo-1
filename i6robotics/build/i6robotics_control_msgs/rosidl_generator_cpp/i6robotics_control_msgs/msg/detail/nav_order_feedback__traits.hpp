// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from i6robotics_control_msgs:msg/NavOrderFeedback.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__TRAITS_HPP_
#define I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "i6robotics_control_msgs/msg/detail/nav_order_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace i6robotics_control_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavOrderFeedback & msg,
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
  const NavOrderFeedback & msg,
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

inline std::string to_yaml(const NavOrderFeedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace i6robotics_control_msgs

namespace rosidl_generator_traits
{

[[deprecated("use i6robotics_control_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const i6robotics_control_msgs::msg::NavOrderFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::msg::NavOrderFeedback & msg)
{
  return i6robotics_control_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::msg::NavOrderFeedback>()
{
  return "i6robotics_control_msgs::msg::NavOrderFeedback";
}

template<>
inline const char * name<i6robotics_control_msgs::msg::NavOrderFeedback>()
{
  return "i6robotics_control_msgs/msg/NavOrderFeedback";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::msg::NavOrderFeedback>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::msg::NavOrderFeedback>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct is_message<i6robotics_control_msgs::msg::NavOrderFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__TRAITS_HPP_
