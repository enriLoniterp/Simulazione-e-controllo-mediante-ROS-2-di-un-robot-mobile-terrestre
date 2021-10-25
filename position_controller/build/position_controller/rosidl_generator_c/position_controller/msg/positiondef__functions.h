// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from position_controller:msg/Positiondef.idl
// generated code does not contain a copyright notice

#ifndef POSITION_CONTROLLER__MSG__POSITIONDEF__FUNCTIONS_H_
#define POSITION_CONTROLLER__MSG__POSITIONDEF__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_generator_c/visibility_control.h"
#include "position_controller/msg/rosidl_generator_c__visibility_control.h"

#include "position_controller/msg/positiondef__struct.h"

/// Initialize msg/Positiondef message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * position_controller__msg__Positiondef
 * )) before or use
 * position_controller__msg__Positiondef__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_position_controller
bool
position_controller__msg__Positiondef__init(position_controller__msg__Positiondef * msg);

/// Finalize msg/Positiondef message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_position_controller
void
position_controller__msg__Positiondef__fini(position_controller__msg__Positiondef * msg);

/// Create msg/Positiondef message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * position_controller__msg__Positiondef__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_position_controller
position_controller__msg__Positiondef *
position_controller__msg__Positiondef__create();

/// Destroy msg/Positiondef message.
/**
 * It calls
 * position_controller__msg__Positiondef__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_position_controller
void
position_controller__msg__Positiondef__destroy(position_controller__msg__Positiondef * msg);


/// Initialize array of msg/Positiondef messages.
/**
 * It allocates the memory for the number of elements and calls
 * position_controller__msg__Positiondef__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_position_controller
bool
position_controller__msg__Positiondef__Sequence__init(position_controller__msg__Positiondef__Sequence * array, size_t size);

/// Finalize array of msg/Positiondef messages.
/**
 * It calls
 * position_controller__msg__Positiondef__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_position_controller
void
position_controller__msg__Positiondef__Sequence__fini(position_controller__msg__Positiondef__Sequence * array);

/// Create array of msg/Positiondef messages.
/**
 * It allocates the memory for the array and calls
 * position_controller__msg__Positiondef__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_position_controller
position_controller__msg__Positiondef__Sequence *
position_controller__msg__Positiondef__Sequence__create(size_t size);

/// Destroy array of msg/Positiondef messages.
/**
 * It calls
 * position_controller__msg__Positiondef__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_position_controller
void
position_controller__msg__Positiondef__Sequence__destroy(position_controller__msg__Positiondef__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // POSITION_CONTROLLER__MSG__POSITIONDEF__FUNCTIONS_H_
