// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from guiding_services:srv/SetGoalChoice.idl
// generated code does not contain a copyright notice

#ifndef GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__TRAITS_HPP_
#define GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "guiding_services/srv/detail/set_goal_choice__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace guiding_services
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetGoalChoice_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: choice
  {
    out << "choice: ";
    rosidl_generator_traits::value_to_yaml(msg.choice, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetGoalChoice_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: choice
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "choice: ";
    rosidl_generator_traits::value_to_yaml(msg.choice, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetGoalChoice_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace guiding_services

namespace rosidl_generator_traits
{

[[deprecated("use guiding_services::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const guiding_services::srv::SetGoalChoice_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  guiding_services::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use guiding_services::srv::to_yaml() instead")]]
inline std::string to_yaml(const guiding_services::srv::SetGoalChoice_Request & msg)
{
  return guiding_services::srv::to_yaml(msg);
}

template<>
inline const char * data_type<guiding_services::srv::SetGoalChoice_Request>()
{
  return "guiding_services::srv::SetGoalChoice_Request";
}

template<>
inline const char * name<guiding_services::srv::SetGoalChoice_Request>()
{
  return "guiding_services/srv/SetGoalChoice_Request";
}

template<>
struct has_fixed_size<guiding_services::srv::SetGoalChoice_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<guiding_services::srv::SetGoalChoice_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<guiding_services::srv::SetGoalChoice_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace guiding_services
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetGoalChoice_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetGoalChoice_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetGoalChoice_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace guiding_services

namespace rosidl_generator_traits
{

[[deprecated("use guiding_services::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const guiding_services::srv::SetGoalChoice_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  guiding_services::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use guiding_services::srv::to_yaml() instead")]]
inline std::string to_yaml(const guiding_services::srv::SetGoalChoice_Response & msg)
{
  return guiding_services::srv::to_yaml(msg);
}

template<>
inline const char * data_type<guiding_services::srv::SetGoalChoice_Response>()
{
  return "guiding_services::srv::SetGoalChoice_Response";
}

template<>
inline const char * name<guiding_services::srv::SetGoalChoice_Response>()
{
  return "guiding_services/srv/SetGoalChoice_Response";
}

template<>
struct has_fixed_size<guiding_services::srv::SetGoalChoice_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<guiding_services::srv::SetGoalChoice_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<guiding_services::srv::SetGoalChoice_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<guiding_services::srv::SetGoalChoice>()
{
  return "guiding_services::srv::SetGoalChoice";
}

template<>
inline const char * name<guiding_services::srv::SetGoalChoice>()
{
  return "guiding_services/srv/SetGoalChoice";
}

template<>
struct has_fixed_size<guiding_services::srv::SetGoalChoice>
  : std::integral_constant<
    bool,
    has_fixed_size<guiding_services::srv::SetGoalChoice_Request>::value &&
    has_fixed_size<guiding_services::srv::SetGoalChoice_Response>::value
  >
{
};

template<>
struct has_bounded_size<guiding_services::srv::SetGoalChoice>
  : std::integral_constant<
    bool,
    has_bounded_size<guiding_services::srv::SetGoalChoice_Request>::value &&
    has_bounded_size<guiding_services::srv::SetGoalChoice_Response>::value
  >
{
};

template<>
struct is_service<guiding_services::srv::SetGoalChoice>
  : std::true_type
{
};

template<>
struct is_service_request<guiding_services::srv::SetGoalChoice_Request>
  : std::true_type
{
};

template<>
struct is_service_response<guiding_services::srv::SetGoalChoice_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GUIDING_SERVICES__SRV__DETAIL__SET_GOAL_CHOICE__TRAITS_HPP_
