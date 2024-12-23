// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from guiding_services:srv/SetGoalChoice.idl
// generated code does not contain a copyright notice

#ifndef GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__STRUCT_HPP_
#define GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__guiding_services__srv__SetGoalChoice_Request __attribute__((deprecated))
#else
# define DEPRECATED__guiding_services__srv__SetGoalChoice_Request __declspec(deprecated)
#endif

namespace guiding_services
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetGoalChoice_Request_
{
  using Type = SetGoalChoice_Request_<ContainerAllocator>;

  explicit SetGoalChoice_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->choice = 0l;
    }
  }

  explicit SetGoalChoice_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->choice = 0l;
    }
  }

  // field types and members
  using _choice_type =
    int32_t;
  _choice_type choice;

  // setters for named parameter idiom
  Type & set__choice(
    const int32_t & _arg)
  {
    this->choice = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__guiding_services__srv__SetGoalChoice_Request
    std::shared_ptr<guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__guiding_services__srv__SetGoalChoice_Request
    std::shared_ptr<guiding_services::srv::SetGoalChoice_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetGoalChoice_Request_ & other) const
  {
    if (this->choice != other.choice) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetGoalChoice_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetGoalChoice_Request_

// alias to use template instance with default allocator
using SetGoalChoice_Request =
  guiding_services::srv::SetGoalChoice_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace guiding_services


#ifndef _WIN32
# define DEPRECATED__guiding_services__srv__SetGoalChoice_Response __attribute__((deprecated))
#else
# define DEPRECATED__guiding_services__srv__SetGoalChoice_Response __declspec(deprecated)
#endif

namespace guiding_services
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetGoalChoice_Response_
{
  using Type = SetGoalChoice_Response_<ContainerAllocator>;

  explicit SetGoalChoice_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetGoalChoice_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__guiding_services__srv__SetGoalChoice_Response
    std::shared_ptr<guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__guiding_services__srv__SetGoalChoice_Response
    std::shared_ptr<guiding_services::srv::SetGoalChoice_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetGoalChoice_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetGoalChoice_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetGoalChoice_Response_

// alias to use template instance with default allocator
using SetGoalChoice_Response =
  guiding_services::srv::SetGoalChoice_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace guiding_services

namespace guiding_services
{

namespace srv
{

struct SetGoalChoice
{
  using Request = guiding_services::srv::SetGoalChoice_Request;
  using Response = guiding_services::srv::SetGoalChoice_Response;
};

}  // namespace srv

}  // namespace guiding_services

#endif  // GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__STRUCT_HPP_
