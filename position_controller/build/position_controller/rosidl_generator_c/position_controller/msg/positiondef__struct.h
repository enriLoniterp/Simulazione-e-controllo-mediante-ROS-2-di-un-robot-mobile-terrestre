// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from position_controller:msg/Positiondef.idl
// generated code does not contain a copyright notice

#ifndef POSITION_CONTROLLER__MSG__POSITIONDEF__STRUCT_H_
#define POSITION_CONTROLLER__MSG__POSITIONDEF__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Positiondef in the package position_controller.
typedef struct position_controller__msg__Positiondef
{
  double posx;
  double posy;
  double postheta;
} position_controller__msg__Positiondef;

// Struct for a sequence of position_controller__msg__Positiondef.
typedef struct position_controller__msg__Positiondef__Sequence
{
  position_controller__msg__Positiondef * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} position_controller__msg__Positiondef__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // POSITION_CONTROLLER__MSG__POSITIONDEF__STRUCT_H_
