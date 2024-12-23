// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from i6robotics_control_msgs:srv/NavOrderSrv.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__STRUCT_HPP_
#define I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__STRUCT_HPP_

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
# define DEPRECATED__i6robotics_control_msgs__srv__NavOrderSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__i6robotics_control_msgs__srv__NavOrderSrv_Request __declspec(deprecated)
#endif

namespace i6robotics_control_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct NavOrderSrv_Request_
{
  using Type = NavOrderSrv_Request_<ContainerAllocator>;

  explicit NavOrderSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_pose(_init)
  {
    (void)_init;
  }

  explicit NavOrderSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_pose(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _goal_pose_type goal_pose;

  // setters for named parameter idiom
  Type & set__goal_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->goal_pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i6robotics_control_msgs__srv__NavOrderSrv_Request
    std::shared_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i6robotics_control_msgs__srv__NavOrderSrv_Request
    std::shared_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavOrderSrv_Request_ & other) const
  {
    if (this->goal_pose != other.goal_pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavOrderSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavOrderSrv_Request_

// alias to use template instance with default allocator
using NavOrderSrv_Request =
  i6robotics_control_msgs::srv::NavOrderSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace i6robotics_control_msgs


#ifndef _WIN32
# define DEPRECATED__i6robotics_control_msgs__srv__NavOrderSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__i6robotics_control_msgs__srv__NavOrderSrv_Response __declspec(deprecated)
#endif

namespace i6robotics_control_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct NavOrderSrv_Response_
{
  using Type = NavOrderSrv_Response_<ContainerAllocator>;

  explicit NavOrderSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  explicit NavOrderSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  // field types and members
  using _result_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i6robotics_control_msgs__srv__NavOrderSrv_Response
    std::shared_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i6robotics_control_msgs__srv__NavOrderSrv_Response
    std::shared_ptr<i6robotics_control_msgs::srv::NavOrderSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavOrderSrv_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavOrderSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavOrderSrv_Response_

// alias to use template instance with default allocator
using NavOrderSrv_Response =
  i6robotics_control_msgs::srv::NavOrderSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace i6robotics_control_msgs

namespace i6robotics_control_msgs
{

namespace srv
{

struct NavOrderSrv
{
  using Request = i6robotics_control_msgs::srv::NavOrderSrv_Request;
  using Response = i6robotics_control_msgs::srv::NavOrderSrv_Response;
};

}  // namespace srv

}  // namespace i6robotics_control_msgs

#endif  // I6ROBOTICS_CONTROL_MSGS__SRV__DETAIL__NAV_ORDER_SRV__STRUCT_HPP_
