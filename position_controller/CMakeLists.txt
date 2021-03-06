cmake_minimum_required(VERSION 3.5)
project(position_controller)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(gazebo_ros_pkgs REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(position_controller_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(tf2 REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(turtlebot3 REQUIRED)
find_package(rclcpp_components REQUIRED)



#####################################################################
#BUILD PART
####################################################################
include_directories(
  include 
)



set(dependencies
  "geometry_msgs"
  "nav_msgs"
  "rclcpp"
  "std_msgs"
  "sensor_msgs"
  "tf2"
  "rclcpp_components"
  "position_controller_msgs"
)

set(EXEC_NAME "position_controller")
set(PIANIFICATORE "pianificatore")



add_executable(${EXEC_NAME} src/position_controll.cpp)
add_executable(${PIANIFICATORE} src/pianificatore.cpp)

ament_target_dependencies(${EXEC_NAME} ${dependencies})
ament_target_dependencies(${PIANIFICATORE} ${dependencies})

####################################################################
#INSTALL
####################################################################

install(TARGETS 
  ${EXEC_NAME}
  ${PIANIFICATORE}
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch models worlds
  DESTINATION share/${PROJECT_NAME}/
)

install(DIRECTORY include/
  DESTINATION include/
)

 
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()



ament_export_include_directories(include)
ament_export_dependencies(gazebo_ros_pkgs)
ament_export_dependencies(geometry_msgs)
ament_export_dependencies(nav_msgs)
ament_export_dependencies(std_msgs)
ament_export_dependencies(rclcpp)
ament_export_dependencies(turtlebot3_msgs)
ament_export_dependencies(tf2)
ament_export_dependencies(sensor_msgs)
ament_export_dependencies(turtlebot3)
ament_export_dependencies(rosidl_default_runtime)
ament_package()
