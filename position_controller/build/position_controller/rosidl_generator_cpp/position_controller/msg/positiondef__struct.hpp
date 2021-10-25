// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from position_controller:msg/Positiondef.idl
// generated code does not contain a copyright notice

#ifndef POSITION_CONTROLLER__MSG__POSITIONDEF__STRUCT_HPP_
#define POSITION_CONTROLLER__MSG__POSITIONDEF__STRUCT_HPP_

#include <rosidl_generator_cpp/bounded_vector.hpp>
#include <rosidl_generator_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__position_controller__msg__Positiondef __attribute__((deprecated))
#else
# define DEPRECATED__position_controller__msg__Positiondef __declspec(deprecated)
#endif

namespace position_controller
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Positiondef_
{
  using Type = Positiondef_<ContainerAllocator>;

  explicit Positiondef_(rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  {
    if (rosidl_generator_cpp::MessageInitialization::ALL == _init ||
      rosidl_generator_cpp::MessageInitialization::ZERO == _init)
    {
      this->posx = 0.0;
      this->posy = 0.0;
      this->postheta = 0.0;
    }
  }

  explicit Positiondef_(const ContainerAllocator & _alloc, rosidl_generator_cpp::MessageInitialization _init = rosidl_generator_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_generator_cpp::MessageInitialization::ALL == _init ||
      rosidl_generator_cpp::MessageInitialization::ZERO == _init)
    {
      this->posx = 0.0;
      this->posy = 0.0;
      this->postheta = 0.0;
    }
  }

  // field types and members
  using _posx_type =
    double;
  _posx_type posx;
  using _posy_type =
    double;
  _posy_type posy;
  using _postheta_type =
    double;
  _postheta_type postheta;

  // setters for named parameter idiom
  Type & set__posx(
    const double & _arg)
  {
    this->posx = _arg;
    return *this;
  }
  Type & set__posy(
    const double & _arg)
  {
    this->posy = _arg;
    return *this;
  }
  Type & set__postheta(
    const double & _arg)
  {
    this->postheta = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    position_controller::msg::Positiondef_<ContainerAllocator> *;
  using ConstRawPtr =
    const position_controller::msg::Positiondef_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<position_controller::msg::Positiondef_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<position_controller::msg::Positiondef_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      position_controller::msg::Positiondef_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<position_controller::msg::Positiondef_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      position_controller::msg::Positiondef_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<position_controller::msg::Positiondef_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<position_controller::msg::Positiondef_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<position_controller::msg::Positiondef_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__position_controller__msg__Positiondef
    std::shared_ptr<position_controller::msg::Positiondef_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__position_controller__msg__Positiondef
    std::shared_ptr<position_controller::msg::Positiondef_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Positiondef_ & other) const
  {
    if (this->posx != other.posx) {
      return false;
    }
    if (this->posy != other.posy) {
      return false;
    }
    if (this->postheta != other.postheta) {
      return false;
    }
    return true;
  }
  bool operator!=(const Positiondef_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Positiondef_

// alias to use template instance with default allocator
using Positiondef =
  position_controller::msg::Positiondef_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace position_controller

#endif  // POSITION_CONTROLLER__MSG__POSITIONDEF__STRUCT_HPP_
