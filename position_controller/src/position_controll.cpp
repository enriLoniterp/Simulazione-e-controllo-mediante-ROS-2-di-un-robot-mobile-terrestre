#include "position_controller/position_controll.hpp"

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
    diff=0.0;
    delta_prev=0.0;
    goal_pose_rad=0.0;
    get_key_state=false;
    init_odom_state=false;
    value_new=false;
    os=1;
    far=0;
  
    auto qos = rclcpp::QoS(rclcpp::KeepLast(10));
    
   // myfile.open("prova1.txt", ios::out);
    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", qos);
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>("odom", qos, std::bind(&Tb3BurgerPosCtrl::odom_callback, this, std::placeholders::_1));
    pianificatore_sub = this->create_subscription<position_controller_msgs::msg::Position>("position", qos, std::bind(&Tb3BurgerPosCtrl::get_position, this, std::placeholders::_1));
    pianificatore_pub = this->create_publisher<position_controller_msgs::msg::Response>("response", qos);
    update_timer_ = this->create_wall_timer(100ms, std::bind(&Tb3BurgerPosCtrl::update_callback, this));

    RCLCPP_INFO(this->get_logger(), "Controllo posizione è iniziato");
}


Tb3BurgerPosCtrl::~Tb3BurgerPosCtrl()
{
  RCLCPP_INFO(this->get_logger(), "Turtlebot3 simulation node has been terminated");
}


void Tb3BurgerPosCtrl::get_position (position_controller_msgs::msg::Position::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "get position\n");
    
    std::vector<double> vectors;
    vectors.push_back(msg->posx);
    vectors.push_back(msg->posy);
    vectors.push_back(msg->postheta);
    printf("vectorsize:%lu\n", vectors.size());
    if((vectors.size())!=3)
    {
         RCLCPP_INFO(this->get_logger(), "Errore durante ricezione posizione");
         auto ris = position_controller_msgs::msg::Response();
         ris.resp=0.0;
         pianificatore_pub->publish(ris);
    }else
    {
        os=0;
        goal_pose_x = msg->posx;
        goal_pose_y = msg->posy;
        goal_pose_rad = msg->postheta;
        if(goal_pose_rad < 0.30 && goal_pose_rad > -0.30)
        {
            far = 1;
        }
        get_key_state=true;
        value_new=true;
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
    last_pose_theta=yaw;
    init_odom_state = true;
    /*
    myfile << last_pose_theta << " ";
    myfile << last_pose_x << " ";
    myfile << " " << last_pose_y << "\n";
    */

}


void Tb3BurgerPosCtrl::update_callback()
{
    if(init_odom_state==true && get_key_state==true){

      path_theta = atan2(goal_pose_y-last_pose_y, goal_pose_x - last_pose_x);
      delta =  last_pose_theta - path_theta;

        if(os==0){
          diff = -delta - goal_pose_rad;
          printf("PRIMA SCRITTURA DI DELTA: %f!!\n", diff);
          os=1;
        }
      distance = sqrt(                                                               
                pow((goal_pose_x-last_pose_x),2)
                + (pow(goal_pose_y-last_pose_y,2)));

      printf("distance: %f\n", distance);
      printf("diff");
     
		phi_unwr_vec[0] = delta_prev;
		phi_unwr_vec[1] = delta;

		unwrap( phi_unwr_vec, SIZE_UNWRAP_ANGLE);

		delta = phi_unwr_vec[1];
	  delta_prev = delta;

    //calcolo dei parametri da inserire nella legge di controllo
    den = (k1*(goal_pose_rad));
    den2= pow(den, 2.0);
    den2 = den2 + 1.0;
               
    // printf("path_theta:%f e last_pose_theta:%f e goal_pose_rad: %f \n", path_theta, last_pose_theta,goal_pose_rad);
    ris = check_angle(last_pose_theta);

    if(far==1) {
        if(distance > 0.15 && far==1){
          float vel = min(vel_max,distance);
            
          twist.angular.z= -((vel/distance)*((k2*(delta-(atan(den))))+(sin(delta)*(1+(k1/den2)))));
          twist.linear.x = vel;
          cmd_vel_pub_->publish(twist);

        }else{
            far=-1;
        }
    }else if(far==0){
      if(distance > 0.27){
          float vel = min(vel_max,distance);
            
          twist.angular.z= -((vel/distance)*((k2*(delta-(atan(den))))+(sin(delta)*(1+(k1/den2)))));
          twist.linear.x = vel;
          cmd_vel_pub_->publish(twist);
      }else{
            far=-1;
      }
      
    }else if(far==-1){
        twist.linear.x=0.0;
        twist.angular.z=0.0;
        auto ris = position_controller_msgs::msg::Response();
        ris.resp=1.0;
        pianificatore_pub->publish(ris);
        os=0;
        cmd_vel_pub_->publish(twist); 
    }

}
}

//Funzione che calcola correttamente e senza errori il passaggio di yaw tra valori > 0 e < 0 o il passaggio tra PI e -PI.

void Tb3BurgerPosCtrl::unwrap(float *p, int N)  
{
    float dp[MAX_LENGTH];     
    float dps[MAX_LENGTH];    
    float dp_corr[MAX_LENGTH];
    float cumsum[MAX_LENGTH];

    float cutoff = M_PI;               /* default value in matlab */
    int j;

    assert(N <= MAX_LENGTH);
    
   // incremental phase variation 
   // MATLAB: dp = diff(p, 1, 1);
    for (j = 0; j < N-1; j++)
      dp[j] = p[j+1] - p[j];
      
   // equivalent phase variation in [-pi, pi]
   // MATLAB: dps = mod(dp+pi,2*pi) - pi;
    for (j = 0; j < N-1; j++)
      dps[j] = (dp[j]+M_PI) - floor((dp[j]+M_PI) / (2*M_PI))*(2*M_PI) - M_PI;

   // preserve variation sign for +pi vs. -pi
   // MATLAB: dps(dps==pi & dp>0,:) = pi;
    for (j = 0; j < N-1; j++)
      if ((dps[j] == -M_PI) && (dp[j] > 0))
        dps[j] = M_PI;

   // incremental phase correction
   // MATLAB: dp_corr = dps - dp;
    for (j = 0; j < N-1; j++)
      dp_corr[j] = dps[j] - dp[j];
      
   // Ignore correction when incremental variation is smaller than cutoff
   // MATLAB: dp_corr(abs(dp)<cutoff,:) = 0;
    for (j = 0; j < N-1; j++)
      if (fabs(dp[j]) < cutoff)
        dp_corr[j] = 0;

   // Find cumulative sum of deltas
   // MATLAB: cumsum = cumsum(dp_corr, 1);
    cumsum[0] = dp_corr[0];
    for (j = 1; j < N-1; j++)
      cumsum[j] = cumsum[j-1] + dp_corr[j];


   // Integrate corrections and add to P to produce smoothed phase values
   // MATLAB: p(2:m,:) = p(2:m,:) + cumsum(dp_corr,1);
    for (j = 1; j < N; j++)
      p[j] += cumsum[j-1];

  return;
  }



int Tb3BurgerPosCtrl::check_angle(double last_pose_theta){

  if((last_pose_theta < (diff+0.1)) && (last_pose_theta >(diff-0.1))){
    printf("VALOREEEEEEE FINALE LAST_POSE_THETA: %f\n", last_pose_theta);
    ris1=1;
  }
  return ris1;
}


int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Tb3BurgerPosCtrl>());
  rclcpp::shutdown();
  return 0;
}
       
        /*if(delta> M_PI ){                
            rest=delta-M_PI;
            delta= -M_PI + rest;
        }else if(delta < -M_PI){
            rest=delta+M_PI;
            delta=M_PI + rest;
        }*/