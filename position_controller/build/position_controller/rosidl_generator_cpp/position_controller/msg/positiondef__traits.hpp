// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from position_controller:msg/Positiondef.idl
// generated code does not contain a copyright notice

#ifndef POSITION_CONTROLLER__MSG__POSITIONDEF__TRAITS_HPP_
#define POSITION_CONTROLLER__MSG__POSITIONDEF__TRAITS_HPP_

#include "position_controller/msg/positiondef__struct.hpp"
#include <rosidl_generator_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<position_controller::msg::Positiondef>()
{
  return "position_controller::msg::Positiondef";
}

template<>
struct has_fixed_size<position_controller::msg::Positiondef>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<position_controller::msg::Positiondef>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<position_controller::msg::Positiondef>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // POSITION_CONTROLLER__MSG__POSITIONDEF__TRAITS_HPP_
