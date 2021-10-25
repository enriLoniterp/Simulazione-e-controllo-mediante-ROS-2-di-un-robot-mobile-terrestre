#include "pianificatore/pianificatore.hpp"
#include "rclcpp_components/register_node_macro.hpp"


#include<unistd.h>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
#include <stdlib.h>   

    Pianificatore::Pianificatore()
    : Node("Pianificatore")
    {
       public:
        using Pianificatore = action_interfaces::action::Pianificatore;
        using GoalHandlePianificatore = rclcpp_action::ClientGoalHandle<Pianificatore>;
    goal_done_=false;
      explicit MinimalActionClient(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())::Node("pianificatore", node_options)
      {
           this->client_ptr_ = rclcpp_action::create_client<Pianificatore>(
            this->get_node_base_interface(),
            this->get_node_graph_interface(),
            this->get_node_logging_interface(),
            this->get_node_waitables_interface(),
            "pianificatore");
      }

      //starting sending actions
      send_goal();
      /*this->timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&MinimalActionClient::send_goal, this));*/
       void send_goal()
    {
        using namespace std::placeholders;

        this->timer_->cancel();

        this->goal_done_ = false;

        if(!this->client_ptr_)
        {
            RCLCPP_ERROR(this->get_logger(), "Action client not initialized");
        }

        if (!this->client_ptr_->wait_for_action_server(std::chrono::seconds(10))) 
        {
            RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
            this->goal_done_ = true;
            return;
        }

        auto goal_msg = Pianificatore::Goal();

        auto send_goal_options = rclcpp_action::Client<Pianificatore>::SendGoalOptions();

        send_goal_options.goal_response_callback = std::bind(&MinimalActionClient::goal_response_callback, this, _1);
        send_goal_options.feedback_callback = std::bind(&MinimalActionClient::feedback_callback, this, _1, _2);
        send_goal_options.result_callback = std::bind(&MinimalActionClient::result_callback, this, _1);

        this->client_ptr_->async_send_goal(goal_msg, send_goal_options);

    }


    /* 
      Action Server has responded to client requests
    */
     void goal_response_callback(std::shared_future<GoalHandlePianificatore::SharedPtr> future)
    {
        auto goal_handle = future.get();
        if (!goal_handle) {
            RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
        } else {
            RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
        }
    }


  /*feedback callback from Serv*/

  void feedback_callback(
    GoalHandlePianificatore::SharedPtr,
    const std::shared_ptr<const Pianificatore::Feedback> feedback)
  {
    RCLCPP_INFO( this->get_logger(), "Next number in sequence received: %f,",feedback->partial_position.back());  //chiedere ad andrea
  }
  
  /*getting final response*/

  void result_callback(const GoalHandlePianificatore::WrappedResult & result)
  {
    this->goal_done_ = true;
    switch (result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
        return;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
        return;
      default:
        RCLCPP_ERROR(this->get_logger(), "Unknown result code");
        return;
    }

    RCLCPP_INFO(this->get_logger(), "Result received");
    for (auto number : result.result->position) {
      RCLCPP_INFO(this->get_logger(), "Posizione sull'asse(in ordine x,y,z): %f", number);
    }
  }

    }
    Pianificatore::~Pianificatore()
    {
      
      RCLCPP_INFO(this->get_logger(), "PIANIFICATORE E' TERMINATO\n");
    }
 
    

    /*
      Sending goal and goal options to Action Server

    */
  int main(int argc, char * argv[])
  {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Pianificatore>());
    rclcpp::shutdown();
    return 0;
  }