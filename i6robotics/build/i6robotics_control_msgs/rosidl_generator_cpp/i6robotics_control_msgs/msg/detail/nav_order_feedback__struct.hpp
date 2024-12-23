// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from i6robotics_control_msgs:msg/NavOrderFeedback.idl
// generated code does not contain a copyright notice

#ifndef I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__STRUCT_HPP_
#define I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__i6robotics_control_msgs__msg__NavOrderFeedback __attribute__((deprecated))
#else
# define DEPRECATED__i6robotics_control_msgs__msg__NavOrderFeedback __declspec(deprecated)
#endif

namespace i6robotics_control_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavOrderFeedback_
{
  using Type = NavOrderFeedback_<ContainerAllocator>;

  explicit NavOrderFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance_remaining = 0.0f;
    }
  }

  explicit NavOrderFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance_remaining = 0.0f;
    }
  }

  // field types and members
  using _current_pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _current_pose_type current_pose;
  using _distance_remaining_type =
    float;
  _distance_remaining_type distance_remaining;

  // setters for named parameter idiom
  Type & set__current_pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->current_pose = _arg;
    return *this;
  }
  Type & set__distance_remaining(
    const float & _arg)
  {
    this->distance_remaining = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__i6robotics_control_msgs__msg__NavOrderFeedback
    std::shared_ptr<i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__i6robotics_control_msgs__msg__NavOrderFeedback
    std::shared_ptr<i6robotics_control_msgs::msg::NavOrderFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavOrderFeedback_ & other) const
  {
    if (this->current_pose != other.current_pose) {
      return false;
    }
    if (this->distance_remaining != other.distance_remaining) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavOrderFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavOrderFeedback_

// alias to use template instance with default allocator
using NavOrderFeedback =
  i6robotics_control_msgs::msg::NavOrderFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace i6robotics_control_msgs

#endif  // I6ROBOTICS_CONTROL_MSGS__MSG__DETAIL__NAV_ORDER_FEEDBACK__STRUCT_HPP_
