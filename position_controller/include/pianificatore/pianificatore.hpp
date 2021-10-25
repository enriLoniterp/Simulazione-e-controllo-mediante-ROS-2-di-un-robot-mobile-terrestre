/*
Pianificatore: l'obiettivo è scegliere la traiettoria
Sono presenti gli include fondamentali e la dichiarazione delle variabili
*/

#ifndef pianificatore_HPP_

#include <geometry_msgs/msg/twist.hpp>
#include "position_controller_msgs/msg/position.hpp"
#include "position_controller_msgs/msg/response.hpp"
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>                                                   
#include <unistd.h>
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

class Pianificatore : public rclcpp::Node
{
 public:
  Pianificatore();
  ~Pianificatore();

   
 private:
    int times=0;
    rclcpp::Publisher<position_controller_msgs::msg::Position>::SharedPtr publisher;
    rclcpp::Subscription<position_controller_msgs::msg::Response>::SharedPtr subscriber;
    

    void timer_callback();
    void topic_callback(position_controller_msgs::msg::Response::SharedPtr msg);
    double fRand(double fMin, double fMax);
};

#endif 
