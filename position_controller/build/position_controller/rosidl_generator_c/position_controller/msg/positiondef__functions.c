// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from position_controller:msg/Positiondef.idl
// generated code does not contain a copyright notice
#include "position_controller/msg/positiondef__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
position_controller__msg__Positiondef__init(position_controller__msg__Positiondef * msg)
{
  if (!msg) {
    return false;
  }
  // posx
  // posy
  // postheta
  return true;
}

void
position_controller__msg__Positiondef__fini(position_controller__msg__Positiondef * msg)
{
  if (!msg) {
    return;
  }
  // posx
  // posy
  // postheta
}

position_controller__msg__Positiondef *
position_controller__msg__Positiondef__create()
{
  position_controller__msg__Positiondef * msg = (position_controller__msg__Positiondef *)malloc(sizeof(position_controller__msg__Positiondef));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(position_controller__msg__Positiondef));
  bool success = position_controller__msg__Positiondef__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
position_controller__msg__Positiondef__destroy(position_controller__msg__Positiondef * msg)
{
  if (msg) {
    position_controller__msg__Positiondef__fini(msg);
  }
  free(msg);
}


bool
position_controller__msg__Positiondef__Sequence__init(position_controller__msg__Positiondef__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  position_controller__msg__Positiondef * data = NULL;
  if (size) {
    data = (position_controller__msg__Positiondef *)calloc(size, sizeof(position_controller__msg__Positiondef));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = position_controller__msg__Positiondef__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        position_controller__msg__Positiondef__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
position_controller__msg__Positiondef__Sequence__fini(position_controller__msg__Positiondef__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      position_controller__msg__Positiondef__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

position_controller__msg__Positiondef__Sequence *
position_controller__msg__Positiondef__Sequence__create(size_t size)
{
  position_controller__msg__Positiondef__Sequence * array = (position_controller__msg__Positiondef__Sequence *)malloc(sizeof(position_controller__msg__Positiondef__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = position_controller__msg__Positiondef__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
position_controller__msg__Positiondef__Sequence__destroy(position_controller__msg__Positiondef__Sequence * array)
{
  if (array) {
    position_controller__msg__Positiondef__Sequence__fini(array);
  }
  free(array);
}
