// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from position_controller:msg/Positiondef.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_generator_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "position_controller/msg/positiondef__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace position_controller
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Positiondef_init_function(
  void * message_memory, rosidl_generator_cpp::MessageInitialization _init)
{
  new (message_memory) position_controller::msg::Positiondef(_init);
}

void Positiondef_fini_function(void * message_memory)
{
  auto typed_message = static_cast<position_controller::msg::Positiondef *>(message_memory);
  typed_message->~Positiondef();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Positiondef_message_member_array[3] = {
  {
    "posx",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(position_controller::msg::Positiondef, posx),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "posy",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(position_controller::msg::Positiondef, posy),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "postheta",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(position_controller::msg::Positiondef, postheta),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Positiondef_message_members = {
  "position_controller::msg",  // message namespace
  "Positiondef",  // message name
  3,  // number of fields
  sizeof(position_controller::msg::Positiondef),
  Positiondef_message_member_array,  // message members
  Positiondef_init_function,  // function to initialize message memory (memory has to be allocated)
  Positiondef_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Positiondef_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Positiondef_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace position_controller


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<position_controller::msg::Positiondef>()
{
  return &::position_controller::msg::rosidl_typesupport_introspection_cpp::Positiondef_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, position_controller, msg, Positiondef)() {
  return &::position_controller::msg::rosidl_typesupport_introspection_cpp::Positiondef_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
