// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from i6robotics_control_msgs:srv/NavOrderSrv.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__BUILDER_HPP_
#define I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "i6robotics_control_msgs/srv/detail/nav_order_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace i6robotics_control_msgs
{

namespace srv
{

namespace builder
{

class Init_NavOrderSrv_Request_goal_pose
{
public:
  Init_NavOrderSrv_Request_goal_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i6robotics_control_msgs::srv::NavOrderSrv_Request goal_pose(::i6robotics_control_msgs::srv::NavOrderSrv_Request::_goal_pose_type arg)
  {
    msg_.goal_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::srv::NavOrderSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::srv::NavOrderSrv_Request>()
{
  return i6robotics_control_msgs::srv::builder::Init_NavOrderSrv_Request_goal_pose();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace srv
{

namespace builder
{

class Init_NavOrderSrv_Response_result
{
public:
  Init_NavOrderSrv_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i6robotics_control_msgs::srv::NavOrderSrv_Response result(::i6robotics_control_msgs::srv::NavOrderSrv_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::srv::NavOrderSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::srv::NavOrderSrv_Response>()
{
  return i6robotics_control_msgs::srv::builder::Init_NavOrderSrv_Response_result();
}

}  // namespace i6robotics_control_msgs

#endif  // I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__BUILDER_HPP_
