// ROS includes
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "servo_control/MotorVector.h"
#include "geometry_msgs/PoseStamped.h"
#include "../include/Robot_Control.h"
#include "robotkinematics/goToInit.h"
#include <math.h>
// C++ includes
#include <sstream>
#include <iostream>
void quat2eul(double q[4], double eul[3]) {
  eul[0]=atan2(2*(q[0]*q[1]+q[2]*q[3]),1-2*(q[2]*q[2]+q[1]*q[1]));
  eul[1]=asin(2*(q[0]*q[2]-q[3]*q[1]));
  eul[2]=atan2(2*(q[0]*q[3]+q[1]*q[2]),1-2*(q[2]*q[2]+q[3]*q[3]));
}

double r_II_B_d[3];
double Euler_d[3];
double gamma_m[36];
bool init_toggle = 1;
double theta1_d_out[4];
double theta2_d_out[4];
double theta3_d_out[4];
double phi_d_temp_out;
double r_II_B_d_temp_out[3];
unsigned char floor_toggle_out[4];
unsigned char legs_valid_out[4];
bool target_set = 0;
void setTargetPosCallback(const geometry_msgs::PoseStamped msg) {
//  std::cout<<"Hello from a callback\n";
  target_set = 1;
  r_II_B_d[0]=1;//msg.pose.position.x;
  r_II_B_d[1]=0;//msg.pose.position.y;
  r_II_B_d[2]=.2;
  Euler_d[0]=0;
  Euler_d[1]=0;
  Euler_d[2]=0;
  
}
void getCurrentPos(const geometry_msgs::PoseStamped msg) {
  gamma_m[0]=msg.pose.position.x;
  gamma_m[1]=msg.pose.position.y;
  gamma_m[2]=msg.pose.position.z;
  double q[4];
  q[0]=msg.pose.orientation.w;
  q[1]=msg.pose.orientation.x;
  q[2]=msg.pose.orientation.y;
  q[3]=msg.pose.orientation.z;
  double eul[3];
  quat2eul(q,eul);
  gamma_m[3]=eul[0];
  gamma_m[4]=eul[1];
  gamma_m[5]=eul[2];
}
bool moveToInit =0;
bool robotStateHandler(robotkinematics::goToInit::Request &req, robotkinematics::goToInit::Response &res) {
  moveToInit=0;
  if(req.start==0) {
   // init
    moveToInit=1;
  } else if(req.start==1) {
    moveToInit=0;
  } else {
    moveToInit=0;
  }
  return(1);
}
void servoCallback(const servo_control::MotorVector& msg) {
  ROS_INFO("I heard: a thingy");
  for(int i=0; i<12;i++) {
    gamma_m[i+6]=msg.data[i];
  }
  //std::cout <<  << " is the recorded theta1\n";
  
}

int main(int argc, char **argv) {
  for(int i = 0; i<36; i++) {
   gamma_m[i]=0;
   if(i==14) gamma_m[i]=0.75;
   if(i==15) gamma_m[i]=0.75;
   if(i==16) gamma_m[i]=0.75;
   if(i==17) gamma_m[i]=0.75;
  }
  gamma_m[5]=.25;
  gamma_m[6]=3.1415/4.0;
  gamma_m[7]=-3.1415/4.0;
  gamma_m[8]=-3.1415/4.0;
  gamma_m[9]=3.1415/4.0;
  gamma_m[10]=3.1415/6+.1;
  gamma_m[11]=-3.1415/6;
  gamma_m[12]=3.1415/6;
  gamma_m[13]=-3.1415/6;
  gamma_m[14]=3.1415/3;
  gamma_m[15]=-3.1415/3;
  gamma_m[16]=3.1415/3;
  gamma_m[17]=-3.1415/3;

  std::cout<<"Hello wqretjh\n";	
  ros::init(argc, argv, "robot_kinematics");
  for(int i =0; i<4; i++) theta1_d_out[i] = 0; 
  ros::NodeHandle n;
  ros::Publisher target_pub = n.advertise<servo_control::MotorVector>("kinematics_target",1000);
  ros::Rate loop_rate(10);
  ros::Subscriber sub=n.subscribe("kinematics_feedback",1000,servoCallback);
  ros::Subscriber targetPos_sub=n.subscribe("rtabmap/goal",1000,setTargetPosCallback);
  ros::Subscriber currentPos_sub=n.subscribe("rtabmap/odom",1000,getCurrentPos);
  ros::ServiceServer initSrv= n.advertiseService("robot_state",robotStateHandler);

  int cnt=0;
  while(ros::ok()) {
    if(moveToInit==1) {
      servo_control::MotorVector msg;
      for(int i = 0; i<36; i++) {
      gamma_m[i]=0;
      if(i==14) gamma_m[i]=0.75;
      if(i==15) gamma_m[i]=0.75;
      if(i==16) gamma_m[i]=0.75;
      if(i==17) gamma_m[i]=0.75;
     }
     gamma_m[5]=.25;
     gamma_m[6]=3.1415/4.0;
     gamma_m[7]=-3.1415/4.0;
     gamma_m[8]=-3.1415/4.0;
     gamma_m[9]=3.1415/4.0;
     gamma_m[10]=3.1415/6+.1;
     gamma_m[11]=-3.1415/6;
     gamma_m[12]=3.1415/6;
     gamma_m[13]=-3.1415/6;
     gamma_m[14]=3.1415/3;
     gamma_m[15]=-3.1415/3;
     gamma_m[16]=3.1415/3;
     gamma_m[17]=-3.1415/3;
     for(int i = 0; i<12; i++) {
       msg.data[i]=gamma_m[i+6];
     }
     target_pub.publish(msg);
    } else {
//    std::cout <<"in a while loop\n";
    if(target_set==1) {
      servo_control::MotorVector msg;
      for(int i = 0; i<3; i++) {
        std::cout << "r_II_B_d[" << i << "]: " << r_II_B_d[i] << "\n";
      }
      Codegen::Robot_Control(r_II_B_d, Euler_d,gamma_m,init_toggle,theta1_d_out,theta2_d_out,theta3_d_out,
                    &phi_d_temp_out, r_II_B_d_temp_out, floor_toggle_out,legs_valid_out);
      init_toggle=0;
      std::cout << "theta1[1]: " << theta1_d_out[0] << "\n";
      for(int i =0; i<4;i++) msg.data[i]=theta1_d_out[i];
      for(int i =4; i<8;i++) msg.data[i]=theta2_d_out[i];
      for(int i =8; i<12;i++) msg.data[i]=theta3_d_out[i];
      target_pub.publish(msg);
    }
    }
      ros::spinOnce();
      loop_rate.sleep();
      ++cnt;

  }
  return 0;
}
