// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from position_controller:msg/Positiondef.idl
// generated code does not contain a copyright notice

#ifndef POSITION_CONTROLLER__MSG__POSITIONDEF__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define POSITION_CONTROLLER__MSG__POSITIONDEF__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_generator_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "position_controller/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "position_controller/msg/positiondef__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace position_controller
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_position_controller
cdr_serialize(
  const position_controller::msg::Positiondef & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_position_controller
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  position_controller::msg::Positiondef & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_position_controller
get_serialized_size(
  const position_controller::msg::Positiondef & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_position_controller
max_serialized_size_Positiondef(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace position_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_position_controller
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, position_controller, msg, Positiondef)();

#ifdef __cplusplus
}
#endif

#endif  // POSITION_CONTROLLER__MSG__POSITIONDEF__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
