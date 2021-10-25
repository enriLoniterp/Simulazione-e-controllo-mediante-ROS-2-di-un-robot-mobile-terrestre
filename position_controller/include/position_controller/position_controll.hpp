//  POSITION_CONTROLLER

// The position_controller receives the positions from the planner. It moves the robot and guarantee stability of the robot over the route.

#ifndef position_controll_HPP_

#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>
#include "position_controller_msgs/msg/position.hpp"
#include "position_controller_msgs/msg/response.hpp"
#include "std_msgs/msg/string.hpp"
#include "unistd.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>
#include <stdlib.h>   
#include <unistd.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>    

using std::endl;
using std::ofstream;

#define DEG2RAD (M_PI / 180.0)
#define RAD2DEG (180.0 / M_PI)
#define LINEAR_VELOCITY  0.1
#define MAX_LENGTH 10000
#define SIZE_UNWRAP_ANGLE 2


class Tb3BurgerPosCtrl : public rclcpp::Node
{
 public:
  Tb3BurgerPosCtrl();
  ~Tb3BurgerPosCtrl();

    float angular_velocity;
    float linear_velocity;
    float distance;
    float delta;
    float den;
    float den2;
    float delta_prev;
    float diff;
    double roll;
    double pitch;
    double yaw;
    int fine;
    int os;
    int ris=0;
    int ris1=0;
    int k2=3;
    int k1=1; 
    float phi_unwr_vec[SIZE_UNWRAP_ANGLE];
    float vel_max=0.1;
    int far;

    ofstream myfile;
    double path_theta;
    int step;
    bool get_key_state;
    bool init_odom_state; 
    bool value_new;


 private:
  geometry_msgs::msg::Twist twist;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
  rclcpp::Publisher<position_controller_msgs::msg::Response>::SharedPtr pianificatore_pub;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
  rclcpp::Subscription<position_controller_msgs::msg::Position>::SharedPtr pianificatore_sub;
  rclcpp::TimerBase::SharedPtr update_timer_;
  rclcpp::TimerBase::SharedPtr update_timers_;
  double last_pose_x;
  double last_pose_y;
  double last_pose_theta;
  double goal_pose_x;
  double goal_pose_y;
  double goal_pose_rad;
  double goal_pose_theta;


  void update_callback();
  void odom_callback( nav_msgs::msg::Odometry::SharedPtr msg);
  void get_position(position_controller_msgs::msg::Position::SharedPtr msg);
  void unwrap(float *p, int N);
  int check_angle(double last_pose_theta);
};
#endif 
