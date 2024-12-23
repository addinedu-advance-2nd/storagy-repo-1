// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from i6robotics_control_msgs:msg/NavOrderFeedback.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__BUILDER_HPP_
#define I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "i6robotics_control_msgs/msg/detail/nav_order_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace i6robotics_control_msgs
{

namespace msg
{

namespace builder
{

class Init_NavOrderFeedback_distance_remaining
{
public:
  explicit Init_NavOrderFeedback_distance_remaining(::i6robotics_control_msgs::msg::NavOrderFeedback & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::msg::NavOrderFeedback distance_remaining(::i6robotics_control_msgs::msg::NavOrderFeedback::_distance_remaining_type arg)
  {
    msg_.distance_remaining = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::msg::NavOrderFeedback msg_;
};

class Init_NavOrderFeedback_current_pose
{
public:
  Init_NavOrderFeedback_current_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavOrderFeedback_distance_remaining current_pose(::i6robotics_control_msgs::msg::NavOrderFeedback::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return Init_NavOrderFeedback_distance_remaining(msg_);
  }

private:
  ::i6robotics_control_msgs::msg::NavOrderFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::msg::NavOrderFeedback>()
{
  return i6robotics_control_msgs::msg::builder::Init_NavOrderFeedback_current_pose();
}

}  // namespace i6robotics_control_msgs

#endif  // I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__BUILDER_HPP_
