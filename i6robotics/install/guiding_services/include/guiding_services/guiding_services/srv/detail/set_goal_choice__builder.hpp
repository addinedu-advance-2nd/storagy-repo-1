// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from guiding_services:srv/SetGoalChoice.idl
// generated code does not contain a copyright notice

#ifndef GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__BUILDER_HPP_
#define GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "guiding_services/srv/detail/set_goal_choice__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace guiding_services
{

namespace srv
{

namespace builder
{

class Init_SetGoalChoice_Request_choice
{
public:
  Init_SetGoalChoice_Request_choice()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::guiding_services::srv::SetGoalChoice_Request choice(::guiding_services::srv::SetGoalChoice_Request::_choice_type arg)
  {
    msg_.choice = std::move(arg);
    return std::move(msg_);
  }

private:
  ::guiding_services::srv::SetGoalChoice_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::guiding_services::srv::SetGoalChoice_Request>()
{
  return guiding_services::srv::builder::Init_SetGoalChoice_Request_choice();
}

}  // namespace guiding_services


namespace guiding_services
{

namespace srv
{

namespace builder
{

class Init_SetGoalChoice_Response_message
{
public:
  explicit Init_SetGoalChoice_Response_message(::guiding_services::srv::SetGoalChoice_Response & msg)
  : msg_(msg)
  {}
  ::guiding_services::srv::SetGoalChoice_Response message(::guiding_services::srv::SetGoalChoice_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::guiding_services::srv::SetGoalChoice_Response msg_;
};

class Init_SetGoalChoice_Response_success
{
public:
  Init_SetGoalChoice_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetGoalChoice_Response_message success(::guiding_services::srv::SetGoalChoice_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetGoalChoice_Response_message(msg_);
  }

private:
  ::guiding_services::srv::SetGoalChoice_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::guiding_services::srv::SetGoalChoice_Response>()
{
  return guiding_services::srv::builder::Init_SetGoalChoice_Response_success();
}

}  // namespace guiding_services

#endif  // GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__BUILDER_HPP_
