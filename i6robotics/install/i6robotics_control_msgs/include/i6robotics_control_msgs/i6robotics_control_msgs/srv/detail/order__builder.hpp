// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from i6robotics_control_msgs:srv/Order.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__BUILDER_HPP_
#define I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "i6robotics_control_msgs/srv/detail/order__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace i6robotics_control_msgs
{

namespace srv
{

namespace builder
{

class Init_Order_Request_goal_pose
{
public:
  explicit Init_Order_Request_goal_pose(::i6robotics_control_msgs::srv::Order_Request & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::srv::Order_Request goal_pose(::i6robotics_control_msgs::srv::Order_Request::_goal_pose_type arg)
  {
    msg_.goal_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::srv::Order_Request msg_;
};

class Init_Order_Request_order
{
public:
  Init_Order_Request_order()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Order_Request_goal_pose order(::i6robotics_control_msgs::srv::Order_Request::_order_type arg)
  {
    msg_.order = std::move(arg);
    return Init_Order_Request_goal_pose(msg_);
  }

private:
  ::i6robotics_control_msgs::srv::Order_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::srv::Order_Request>()
{
  return i6robotics_control_msgs::srv::builder::Init_Order_Request_order();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace srv
{

namespace builder
{

class Init_Order_Response_accepted
{
public:
  Init_Order_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i6robotics_control_msgs::srv::Order_Response accepted(::i6robotics_control_msgs::srv::Order_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::srv::Order_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::srv::Order_Response>()
{
  return i6robotics_control_msgs::srv::builder::Init_Order_Response_accepted();
}

}  // namespace i6robotics_control_msgs

#endif  // I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__BUILDER_HPP_
