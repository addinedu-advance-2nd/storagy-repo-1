// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from i6robotics_control_msgs:action/NavOrder.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__NAV_ORDER__BUILDER_HPP_
#define I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__NAV_ORDER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "i6robotics_control_msgs/action/detail/nav_order__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_NavOrder_Goal_goal_pose
{
public:
  Init_NavOrder_Goal_goal_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i6robotics_control_msgs::action::NavOrder_Goal goal_pose(::i6robotics_control_msgs::action::NavOrder_Goal::_goal_pose_type arg)
  {
    msg_.goal_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::NavOrder_Goal>()
{
  return i6robotics_control_msgs::action::builder::Init_NavOrder_Goal_goal_pose();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_NavOrder_Result_result
{
public:
  Init_NavOrder_Result_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i6robotics_control_msgs::action::NavOrder_Result result(::i6robotics_control_msgs::action::NavOrder_Result::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::NavOrder_Result>()
{
  return i6robotics_control_msgs::action::builder::Init_NavOrder_Result_result();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_NavOrder_Feedback_distance_remaining
{
public:
  explicit Init_NavOrder_Feedback_distance_remaining(::i6robotics_control_msgs::action::NavOrder_Feedback & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::action::NavOrder_Feedback distance_remaining(::i6robotics_control_msgs::action::NavOrder_Feedback::_distance_remaining_type arg)
  {
    msg_.distance_remaining = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_Feedback msg_;
};

class Init_NavOrder_Feedback_current_pose
{
public:
  Init_NavOrder_Feedback_current_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavOrder_Feedback_distance_remaining current_pose(::i6robotics_control_msgs::action::NavOrder_Feedback::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return Init_NavOrder_Feedback_distance_remaining(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::NavOrder_Feedback>()
{
  return i6robotics_control_msgs::action::builder::Init_NavOrder_Feedback_current_pose();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_NavOrder_SendGoal_Request_goal
{
public:
  explicit Init_NavOrder_SendGoal_Request_goal(::i6robotics_control_msgs::action::NavOrder_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::action::NavOrder_SendGoal_Request goal(::i6robotics_control_msgs::action::NavOrder_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_SendGoal_Request msg_;
};

class Init_NavOrder_SendGoal_Request_goal_id
{
public:
  Init_NavOrder_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavOrder_SendGoal_Request_goal goal_id(::i6robotics_control_msgs::action::NavOrder_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavOrder_SendGoal_Request_goal(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::NavOrder_SendGoal_Request>()
{
  return i6robotics_control_msgs::action::builder::Init_NavOrder_SendGoal_Request_goal_id();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_NavOrder_SendGoal_Response_stamp
{
public:
  explicit Init_NavOrder_SendGoal_Response_stamp(::i6robotics_control_msgs::action::NavOrder_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::action::NavOrder_SendGoal_Response stamp(::i6robotics_control_msgs::action::NavOrder_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_SendGoal_Response msg_;
};

class Init_NavOrder_SendGoal_Response_accepted
{
public:
  Init_NavOrder_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavOrder_SendGoal_Response_stamp accepted(::i6robotics_control_msgs::action::NavOrder_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_NavOrder_SendGoal_Response_stamp(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::NavOrder_SendGoal_Response>()
{
  return i6robotics_control_msgs::action::builder::Init_NavOrder_SendGoal_Response_accepted();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_NavOrder_GetResult_Request_goal_id
{
public:
  Init_NavOrder_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::i6robotics_control_msgs::action::NavOrder_GetResult_Request goal_id(::i6robotics_control_msgs::action::NavOrder_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::NavOrder_GetResult_Request>()
{
  return i6robotics_control_msgs::action::builder::Init_NavOrder_GetResult_Request_goal_id();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_NavOrder_GetResult_Response_result
{
public:
  explicit Init_NavOrder_GetResult_Response_result(::i6robotics_control_msgs::action::NavOrder_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::action::NavOrder_GetResult_Response result(::i6robotics_control_msgs::action::NavOrder_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_GetResult_Response msg_;
};

class Init_NavOrder_GetResult_Response_status
{
public:
  Init_NavOrder_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavOrder_GetResult_Response_result status(::i6robotics_control_msgs::action::NavOrder_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavOrder_GetResult_Response_result(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::NavOrder_GetResult_Response>()
{
  return i6robotics_control_msgs::action::builder::Init_NavOrder_GetResult_Response_status();
}

}  // namespace i6robotics_control_msgs


namespace i6robotics_control_msgs
{

namespace action
{

namespace builder
{

class Init_NavOrder_FeedbackMessage_feedback
{
public:
  explicit Init_NavOrder_FeedbackMessage_feedback(::i6robotics_control_msgs::action::NavOrder_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::i6robotics_control_msgs::action::NavOrder_FeedbackMessage feedback(::i6robotics_control_msgs::action::NavOrder_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_FeedbackMessage msg_;
};

class Init_NavOrder_FeedbackMessage_goal_id
{
public:
  Init_NavOrder_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavOrder_FeedbackMessage_feedback goal_id(::i6robotics_control_msgs::action::NavOrder_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavOrder_FeedbackMessage_feedback(msg_);
  }

private:
  ::i6robotics_control_msgs::action::NavOrder_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::i6robotics_control_msgs::action::NavOrder_FeedbackMessage>()
{
  return i6robotics_control_msgs::action::builder::Init_NavOrder_FeedbackMessage_goal_id();
}

}  // namespace i6robotics_control_msgs

#endif  // I6ROBOTICS_CONTROL_MSGS__ACTION__DETAIL__NAV_ORDER__BUILDER_HPP_
