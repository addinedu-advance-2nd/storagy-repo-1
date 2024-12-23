// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from i6robotics_control_msgs:msg/CmdAndPoseVel.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__CMD_AND_POSE_VEL__TRAITS_HPP_
#define I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__CMD_AND_POSE_VEL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "i6robotics_control_msgs/msg/detail/cmd_and_pose_vel__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace i6robotics_control_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CmdAndPoseVel & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd_vel_linear
  {
    out << "cmd_vel_linear: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_vel_linear, out);
    out << ", ";
  }

  // member: cmd_vel_angular
  {
    out << "cmd_vel_angular: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_vel_angular, out);
    out << ", ";
  }

  // member: pose_x
  {
    out << "pose_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_x, out);
    out << ", ";
  }

  // member: pose_y
  {
    out << "pose_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_y, out);
    out << ", ";
  }

  // member: linear_vel
  {
    out << "linear_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_vel, out);
    out << ", ";
  }

  // member: angular_vel
  {
    out << "angular_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_vel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CmdAndPoseVel & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd_vel_linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_vel_linear: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_vel_linear, out);
    out << "\n";
  }

  // member: cmd_vel_angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_vel_angular: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_vel_angular, out);
    out << "\n";
  }

  // member: pose_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_x, out);
    out << "\n";
  }

  // member: pose_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_y: ";
    rosidl_generator_traits::value_to_yaml(msg.pose_y, out);
    out << "\n";
  }

  // member: linear_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_vel, out);
    out << "\n";
  }

  // member: angular_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_vel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CmdAndPoseVel & msg, bool use_flow_style = false)
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
  const i6robotics_control_msgs::msg::CmdAndPoseVel & msg,
  std::ostream & out, size_t indentation = 0)
{
  i6robotics_control_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use i6robotics_control_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const i6robotics_control_msgs::msg::CmdAndPoseVel & msg)
{
  return i6robotics_control_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<i6robotics_control_msgs::msg::CmdAndPoseVel>()
{
  return "i6robotics_control_msgs::msg::CmdAndPoseVel";
}

template<>
inline const char * name<i6robotics_control_msgs::msg::CmdAndPoseVel>()
{
  return "i6robotics_control_msgs/msg/CmdAndPoseVel";
}

template<>
struct has_fixed_size<i6robotics_control_msgs::msg::CmdAndPoseVel>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<i6robotics_control_msgs::msg::CmdAndPoseVel>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<i6robotics_control_msgs::msg::CmdAndPoseVel>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__CMD_AND_POSE_VEL__TRAITS_HPP_
