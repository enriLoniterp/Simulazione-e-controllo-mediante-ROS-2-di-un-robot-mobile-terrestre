#include "position_controller/position_controll.hpp"

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>
#include <stdlib.h>   
#include <unistd.h>


using namespace std::chrono_literals;
using namespace std;

Tb3BurgerPosCtrl::Tb3BurgerPosCtrl()
: Node("burger_position_control")
{
    last_pose_x = 0.0;
    last_pose_y = 0.0;
    last_pose_theta = 0.0;
    goal_pose_x = 0.0;
    goal_pose_y = 0.0;
    fine=0;
    step=0;
    get_key_state=false;
    init_odom_state=false;

    auto qos = rclcpp::QoS(rclcpp::KeepLast(10));

    public:
        using Pianificatore = action_interfaces::action::Pianificatore;
        using GoalHandlePianificatore = rclcpp_action::ServerGoalHandle<Pianificatore>;

  explicit MinimalActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("controller", options)
  {
    using namespace std::placeholders;

    this->action_server_ = rclcpp_action::create_server<Pianificatore>(
      this->get_node_base_interface(),
      this->get_node_clock_interface(),
      this->get_node_logging_interface(),
      this->get_node_waitables_interface(),
      "controller",
      std::bind(&MinimalActionServer::handle_goal, this, _1, _2),
      std::bind(&MinimalActionServer::handle_cancel, this, _1),
      std::bind(&MinimalActionServer::handle_accepted, this, _1));
  }
}


Tb3BurgerPosCtrl::~Tb3BurgerPosCtrl()
{
  RCLCPP_INFO(this->get_logger(), "Turtlebot3 simulation node has been terminated");
}



  rclcpp_action::GoalResponse Tb3BurgerPosCtrl::handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<Pianificatore::Goal> goal)
  {
    RCLCPP_INFO(this->get_logger(), "Received goal request with order");
    (void)uuid;
    
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }




  rclcpp_action::CancelResponse Tb3BurgerPosCtrl::handle_cancel(const std::shared_ptr<GoalHandlePianificatore> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }




  void Tb3BurgerPosCtrl::execute(const std::shared_ptr<GoalHandlePianificatore> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Executing goal");
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<Pianificatore::Feedback>();
    auto & partial_position = feedback->partial_position;

    auto result = std::make_shared<Pianificatore::Result>();

      if (goal_handle->is_canceling()) {
        result->partial_position = partial_position;
        goal_handle->canceled(result);
        RCLCPP_INFO(this->get_logger(), "Goal Canceled");
        return;
      }
      
      partial_position.push_back(last_pose_x);
      partial_position.push_back(last_pose_y);
      partial_position.push_back(last_pose_theta);

      
      goal_handle->publish_feedback(feedback);
      RCLCPP_INFO(this->get_logger(), "Publish Feedback");
    
      result->sequence = sequence;
      goal_handle->succeed(result);
      RCLCPP_INFO(this->get_logger(), "Goal Succeeded");
    
  }

  void Tb3BurgerPosCtrl::handle_accepted(const std::shared_ptr<GoalHandlePianificatore> goal_handle)
  {
    using namespace std::placeholders;
    
    std::thread{std::bind(&PianificatoreActionServer::execute, this, _1), goal_handle}.detach();
  }

void Tb3BurgerPosCtrl::get_position (std_msgs::msg::String::SharedPtr msg)
{
    char ris[255] = "";
    strcpy (ris, msg->data.c_str());
    printf("%s",ris);
    RCLCPP_INFO(this->get_logger(), "Controllo posizione è iniziato: %s\n", (msg->data.c_str()));
    char virgola = ',';
    double position[2];
    int i=0,j=0,z=0;
    int pos=0;
    char temp[255]="";

    while (ris[i]!=';') {
        if(ris[i]!= ',')
        {
            temp[j]=ris[i];
            j++;
            i++;
        }else
        {
            position[z]=atof(temp);
            printf("position:%f\n alla posizione:%d\n", position[z], z);
            z++;
            j=0;
            i++;
        }
    }
    
    j=0;
    i=0;
    position[z]=atof(temp);
    printf("position:%f alla posizione: %d", position[z],z);
    printf("SONO ARRIVATO FIN QUA\n");
    
    if(z!=2)
    {
        RCLCPP_INFO(this->get_logger(), "Errore durante ricezione posizione");
        auto ris = std_msgs::msg::String();
        ris.data="0";
        pianificatore_pub->publish(ris);

    }else
    {
        goal_pose_x = position[0];
        goal_pose_y = position[1];
        goal_pose_theta = position[2];
        get_key_state=true;
        step=1;
    }
}


void Tb3BurgerPosCtrl::odom_callback (nav_msgs::msg::Odometry::SharedPtr msg)
{  
    tf2::Quaternion q(
        msg->pose.pose.orientation.x,
        msg->pose.pose.orientation.y,
        msg->pose.pose.orientation.z,
        msg->pose.pose.orientation.w);
    tf2::Matrix3x3 m(q); 
    m.getRPY(roll, pitch, yaw);
    last_pose_x = msg->pose.pose.position.x;
    last_pose_y = msg->pose.pose.position.y;
    //printf("last_pose_x:%f\n", last_pose_x);
    robot_angle = yaw;
    last_pose_theta=yaw;
    //printf("yaw:%f\n", yaw);
    init_odom_state = true;
}


void Tb3BurgerPosCtrl::update_callback()
{
    geometry_msgs::msg::Twist twist;
    printf("robot_angle:%f\n", robot_angle);

    if(init_odom_state==true && get_key_state==true){

        float angular_velocity;
        float linear_velocity;
        float distance;
        float angle;

        if (step == 1){
                path_theta = atan2(goal_pose_y-last_pose_y, goal_pose_x - last_pose_x);
                angle = path_theta - last_pose_theta;
                printf("path_theta:%f e last_pose_theta:%f\n", path_theta, last_pose_theta);
                printf("angle:%f\n", angle);
                angular_velocity = 0.1 ; 
                
                /*twist =*/ //turn(&twist, angle, angular_velocity, this->step);
        
            if (fabs(angle) > 0.05)
             {    
            if (angle >= M_PI)
                {
                    twist.angular.z = -angular_velocity;
                }
                else if (M_PI > angle && angle >= 0)
                {
                    twist.angular.z = angular_velocity;
                }
                else if(angle < 0 && angle >= -M_PI)
                {
                    twist.angular.z = -angular_velocity;
                }else if(angle > -M_PI){
                    
                    twist.angular.z = angular_velocity;
                }else if(angle < -M_PI)
                {
                    twist.angular.z = -angular_velocity;
                }

        }else{
            step++;
        }
        }
         
        if( step == 2)
        {
            distance = sqrt(
                pow((goal_pose_x-last_pose_x),2)
                + (pow(goal_pose_y-last_pose_y,2)));
            linear_velocity = 0.1;
            printf("distance: %f\n", distance);
            
            // go_straight(&twist, distance, linear_velocity, this->step);
            if (distance > 0.1)
            {
              twist.linear.x = linear_velocity;
            }else
            {
                printf("step da 2-->3");
                 step ++;
            }
        }  

        if( step == 3)
        {
            
           angular_velocity = 0.1;
           double duepi = M_PI*2;
           double rest=0;
           double goal_pose_rad = ((goal_pose_theta*M_PI)/(180));
           double angle_comp =0;
           if(goal_pose_theta > 180){
               rest=goal_pose_rad-M_PI;
               angle_comp= -M_PI + rest;
               angle = angle_comp - last_pose_theta;
               printf("CASO 1\n");
           }else{
               printf("CASO 2\n");
            angle= goal_pose_rad - last_pose_theta;
           }
           printf("last_pose_theta:%f, goal_pose_rad:%f angle rimasto:%f\n", last_pose_theta, goal_pose_rad, angle);
          
           if (fabs(angle) > 0.05)
            {    
            if (angle >= M_PI)
                {
                    twist.angular.z = -angular_velocity;
                }
                else if (angle < M_PI && angle >= 0)
                {
                    twist.angular.z = angular_velocity;
                }
                else if(angle < 0 && angle >= -M_PI)
                {
                    twist.angular.z = -angular_velocity;
                }else if(angle > -M_PI){
                    
                    twist.angular.z = angular_velocity;
                } else if(angle < -M_PI){
                    twist.angular.z = angular_velocity;
                }
                
            }else{
                printf("STEP 3-->4\n");
                step++;
            }
            
        }
        /*twist=*/ //turn(twist, angle, angular_velocity, this->step);       
        if( step == 4)
        {
            step = 0;
            get_key_state = false;
            auto ris = std_msgs::msg::String();
            if(distance <0.1)
            {
                ris.data= "1";
                printf("valore di ritorno al pianificatore:%s\n", ris.data.c_str());
                pianificatore_pub->publish(ris);
            }
            else{
                auto ris = std_msgs::msg::String();
                ris.data= "0";
                pianificatore_pub->publish(ris);
            }
        }

        cmd_vel_pub_->publish(twist);
            
    }
}

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Tb3BurgerPosCtrl>());
  rclcpp::shutdown();
  return 0;
}
