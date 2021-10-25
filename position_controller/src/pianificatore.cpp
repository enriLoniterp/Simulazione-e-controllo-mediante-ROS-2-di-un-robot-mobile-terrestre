#include "pianificatore/pianificatore.hpp"


/*
Pianificatore: scegliere la traiettoria:

Pianificatore::Pianificatore()
    : Node("Pianificatore") --> Creazione nodo di ROS 2 e inizializzazione di publish e subscriber.

void Pianificatore::timer_callback() --> metodo che pubblica i messaggi sul topic position.

void Pianificatore::topic_callback(position_controller_msgs::msg::Response::SharedPtr msg) --> metodo che riceve il responso dell'operazione e richiama timer_callback per aggiungere una nuova posizione

*/
using namespace std;

    Pianificatore::Pianificatore()
    : Node("Pianificatore")
    {
      auto qos = rclcpp::QoS(rclcpp::KeepLast(10));
      times=0;
      publisher = this->create_publisher<position_controller_msgs::msg::Position>("position",qos);
      subscriber = this->create_subscription<position_controller_msgs::msg::Response>("response", 10, std::bind(&Pianificatore::topic_callback, this, std::placeholders::_1));
      sleep(3);
      timer_callback();
    }
  

    void Pianificatore::timer_callback()
    {
      auto message = position_controller_msgs::msg::Position();
      //message.data =  std::to_string(rand()%4) + virg + std::to_string(rand()%4) + virg + std::to_string(rand()%360) + puntvirg;
      
      message.posx = 3.0;
      message.posy = 2.0;
      message.postheta = 0.15;
      
      RCLCPP_INFO(this-> get_logger(), "Publishing position: %f %f %f", message.posx, message.posy, message.postheta);
      publisher->publish(message);
      publisher->publish(message); // Doppio invio necessario per garantire la massima sicurezza di invio.
    }
  
    void Pianificatore::topic_callback(position_controller_msgs::msg::Response::SharedPtr msg)
    {
        bool risultato=msg->resp;
        sleep(3);
        if(risultato == 1)
        {
          timer_callback();
        }else
        {
           RCLCPP_INFO(this->get_logger(), "Errore Controllore con errore");
           timer_callback();
        }
       
    }

    Pianificatore::~Pianificatore()
    {
      RCLCPP_INFO(this->get_logger(), "PIANIFICATORE E' TERMINATO\n");
    }

/*
    double Pianificatore::fRand(double fMin, double fMax)
    {
      double f = (double)rand() / RAND_MAX;
     return fMin + f * (fMax - fMin);
    }
*/

  int main(int argc, char * argv[])
  {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Pianificatore>());
    rclcpp::shutdown();
    return 0;
  }