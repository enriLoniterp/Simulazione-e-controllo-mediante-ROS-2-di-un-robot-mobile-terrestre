// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from position_controller:msg/Positiondef.idl
// generated code does not contain a copyright notice
#include "position_controller/msg/positiondef__rosidl_typesupport_fastrtps_cpp.hpp"
#include "position_controller/msg/positiondef__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: posx
  cdr << ros_message.posx;
  // Member: posy
  cdr << ros_message.posy;
  // Member: postheta
  cdr << ros_message.postheta;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_position_controller
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  position_controller::msg::Positiondef & ros_message)
{
  // Member: posx
  cdr >> ros_message.posx;

  // Member: posy
  cdr >> ros_message.posy;

  // Member: postheta
  cdr >> ros_message.postheta;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_position_controller
get_serialized_size(
  const position_controller::msg::Positiondef & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: posx
  {
    size_t item_size = sizeof(ros_message.posx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: posy
  {
    size_t item_size = sizeof(ros_message.posy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: postheta
  {
    size_t item_size = sizeof(ros_message.postheta);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_position_controller
max_serialized_size_Positiondef(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: posx
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: posy
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: postheta
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Positiondef__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const position_controller::msg::Positiondef *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Positiondef__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<position_controller::msg::Positiondef *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Positiondef__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const position_controller::msg::Positiondef *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Positiondef__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Positiondef(full_bounded, 0);
}

static message_type_support_callbacks_t _Positiondef__callbacks = {
  "position_controller::msg",
  "Positiondef",
  _Positiondef__cdr_serialize,
  _Positiondef__cdr_deserialize,
  _Positiondef__get_serialized_size,
  _Positiondef__max_serialized_size
};

static rosidl_message_type_support_t _Positiondef__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Positiondef__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace position_controller

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_position_controller
const rosidl_message_type_support_t *
get_message_type_support_handle<position_controller::msg::Positiondef>()
{
  return &position_controller::msg::typesupport_fastrtps_cpp::_Positiondef__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, position_controller, msg, Positiondef)() {
  return &position_controller::msg::typesupport_fastrtps_cpp::_Positiondef__handle;
}

#ifdef __cplusplus
}
#endif
