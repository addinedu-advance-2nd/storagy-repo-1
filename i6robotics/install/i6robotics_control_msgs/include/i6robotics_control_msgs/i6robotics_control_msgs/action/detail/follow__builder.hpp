// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from i6robotics_control_msgs:action/Follow.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__FOLLOW__BUILDER_HPP_
#define I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__FOLLOW__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "i6robotics_control_msgs/action/detail/follow__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace i6robotics_control_msgs
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::Follow_Goal>()
{
  return ::i6robotics_control_msgs::action::Follow_Goal(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_Follow_Result_result
{
public:
  Init_Follow_Result_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i6robotics_control_msgs::action::Follow_Result result(::i6robotics_control_msgs::action::Follow_Result::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::Follow_Result>()
{
  return i6robotics_control_msgs::action::builder::Init_Follow_Result_result();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_Follow_Feedback_feedback
{
public:
  Init_Follow_Feedback_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i6robotics_control_msgs::action::Follow_Feedback feedback(::i6robotics_control_msgs::action::Follow_Feedback::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::Follow_Feedback>()
{
  return i6robotics_control_msgs::action::builder::Init_Follow_Feedback_feedback();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_Follow_SendGoal_Request_goal
{
public:
  explicit Init_Follow_SendGoal_Request_goal(::i6robotics_control_msgs::action::Follow_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::action::Follow_SendGoal_Request goal(::i6robotics_control_msgs::action::Follow_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_SendGoal_Request msg_;
};

class Init_Follow_SendGoal_Request_goal_id
{
public:
  Init_Follow_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Follow_SendGoal_Request_goal goal_id(::i6robotics_control_msgs::action::Follow_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Follow_SendGoal_Request_goal(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::Follow_SendGoal_Request>()
{
  return i6robotics_control_msgs::action::builder::Init_Follow_SendGoal_Request_goal_id();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_Follow_SendGoal_Response_stamp
{
public:
  explicit Init_Follow_SendGoal_Response_stamp(::i6robotics_control_msgs::action::Follow_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::action::Follow_SendGoal_Response stamp(::i6robotics_control_msgs::action::Follow_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_SendGoal_Response msg_;
};

class Init_Follow_SendGoal_Response_accepted
{
public:
  Init_Follow_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Follow_SendGoal_Response_stamp accepted(::i6robotics_control_msgs::action::Follow_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Follow_SendGoal_Response_stamp(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::Follow_SendGoal_Response>()
{
  return i6robotics_control_msgs::action::builder::Init_Follow_SendGoal_Response_accepted();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_Follow_GetResult_Request_goal_id
{
public:
  Init_Follow_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i6robotics_control_msgs::action::Follow_GetResult_Request goal_id(::i6robotics_control_msgs::action::Follow_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::Follow_GetResult_Request>()
{
  return i6robotics_control_msgs::action::builder::Init_Follow_GetResult_Request_goal_id();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_Follow_GetResult_Response_result
{
public:
  explicit Init_Follow_GetResult_Response_result(::i6robotics_control_msgs::action::Follow_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::action::Follow_GetResult_Response result(::i6robotics_control_msgs::action::Follow_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_GetResult_Response msg_;
};

class Init_Follow_GetResult_Response_status
{
public:
  Init_Follow_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Follow_GetResult_Response_result status(::i6robotics_control_msgs::action::Follow_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Follow_GetResult_Response_result(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::Follow_GetResult_Response>()
{
  return i6robotics_control_msgs::action::builder::Init_Follow_GetResult_Response_status();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_Follow_FeedbackMessage_feedback
{
public:
  explicit Init_Follow_FeedbackMessage_feedback(::i6robotics_control_msgs::action::Follow_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::action::Follow_FeedbackMessage feedback(::i6robotics_control_msgs::action::Follow_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_FeedbackMessage msg_;
};

class Init_Follow_FeedbackMessage_goal_id
{
public:
  Init_Follow_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Follow_FeedbackMessage_feedback goal_id(::i6robotics_control_msgs::action::Follow_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Follow_FeedbackMessage_feedback(msg_);
  }

private:
  ::i6robotics_control_msgs::action::Follow_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::Follow_FeedbackMessage>()
{
  return i6robotics_control_msgs::action::builder::Init_Follow_FeedbackMessage_goal_id();
}

}  // namespace i6robotics_control_msgs

#endif  // I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__FOLLOW__BUILDER_HPP_
