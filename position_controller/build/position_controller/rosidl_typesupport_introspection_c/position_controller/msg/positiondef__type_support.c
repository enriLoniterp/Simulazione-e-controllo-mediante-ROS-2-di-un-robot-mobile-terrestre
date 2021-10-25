// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from position_controller:msg/Positiondef.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "position_controller/msg/positiondef__rosidl_typesupport_introspection_c.h"
#include "position_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "position_controller/msg/positiondef__functions.h"
#include "position_controller/msg/positiondef__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Positiondef__rosidl_typesupport_introspection_c__Positiondef_init_function(
  void * message_memory, enum rosidl_runtime_c_message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  position_controller__msg__Positiondef__init(message_memory);
}

void Positiondef__rosidl_typesupport_introspection_c__Positiondef_fini_function(void * message_memory)
{
  position_controller__msg__Positiondef__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Positiondef__rosidl_typesupport_introspection_c__Positiondef_message_member_array[3] = {
  {
    "posx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(position_controller__msg__Positiondef, posx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "posy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(position_controller__msg__Positiondef, posy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "postheta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(position_controller__msg__Positiondef, postheta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Positiondef__rosidl_typesupport_introspection_c__Positiondef_message_members = {
  "position_controller__msg",  // message namespace
  "Positiondef",  // message name
  3,  // number of fields
  sizeof(position_controller__msg__Positiondef),
  Positiondef__rosidl_typesupport_introspection_c__Positiondef_message_member_array,  // message members
  Positiondef__rosidl_typesupport_introspection_c__Positiondef_init_function,  // function to initialize message memory (memory has to be allocated)
  Positiondef__rosidl_typesupport_introspection_c__Positiondef_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Positiondef__rosidl_typesupport_introspection_c__Positiondef_message_type_support_handle = {
  0,
  &Positiondef__rosidl_typesupport_introspection_c__Positiondef_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_position_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, position_controller, msg, Positiondef)() {
  if (!Positiondef__rosidl_typesupport_introspection_c__Positiondef_message_type_support_handle.typesupport_identifier) {
    Positiondef__rosidl_typesupport_introspection_c__Positiondef_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Positiondef__rosidl_typesupport_introspection_c__Positiondef_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
