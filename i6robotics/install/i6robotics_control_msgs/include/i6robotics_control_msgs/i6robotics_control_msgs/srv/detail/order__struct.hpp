// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from i6robotics_control_msgs:srv/Order.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__STRUCT_HPP_
#define I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'goal_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__i6robotics_control_msgs__srv__Order_Request __attribute__((deprecated))
#else
# define DEPRECATED__i6robotics_control_msgs__srv__Order_Request __declspec(deprecated)
#endif

namespace i6robotics_control_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Order_Request_
{
  using Type = Order_Request_<ContainerAllocator>;

  explicit Order_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order = "";
    }
  }

  explicit Order_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : order(_alloc),
    goal_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order = "";
    }
  }

  // field types and members
  using _order_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _order_type order;
  using _goal_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _goal_pose_type goal_pose;

  // setters for named parameter idiom
  Type & set__order(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->order = _arg;
    return *this;
  }
  Type & set__goal_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->goal_pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i6robotics_control_msgs__srv__Order_Request
    std::shared_ptr<i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i6robotics_control_msgs__srv__Order_Request
    std::shared_ptr<i6robotics_control_msgs::srv::Order_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Order_Request_ & other) const
  {
    if (this->order != other.order) {
      return false;
    }
    if (this->goal_pose != other.goal_pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const Order_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Order_Request_

// alias to use template instance with default allocator
using Order_Request =
  i6robotics_control_msgs::srv::Order_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace i6robotics_control_msgs


#ifndef _WIN32
# define DEPRECATED__i6robotics_control_msgs__srv__Order_Response __attribute__((deprecated))
#else
# define DEPRECATED__i6robotics_control_msgs__srv__Order_Response __declspec(deprecated)
#endif

namespace i6robotics_control_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Order_Response_
{
  using Type = Order_Response_<ContainerAllocator>;

  explicit Order_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit Order_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i6robotics_control_msgs__srv__Order_Response
    std::shared_ptr<i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i6robotics_control_msgs__srv__Order_Response
    std::shared_ptr<i6robotics_control_msgs::srv::Order_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Order_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    return true;
  }
  bool operator!=(const Order_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Order_Response_

// alias to use template instance with default allocator
using Order_Response =
  i6robotics_control_msgs::srv::Order_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace i6robotics_control_msgs

namespace i6robotics_control_msgs
{

namespace srv
{

struct Order
{
  using Request = i6robotics_control_msgs::srv::Order_Request;
  using Response = i6robotics_control_msgs::srv::Order_Response;
};

}  // namespace srv

}  // namespace i6robotics_control_msgs

#endif  // I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__ORDER__STRUCT_HPP_
