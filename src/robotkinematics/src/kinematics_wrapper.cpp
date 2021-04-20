// ROS includes
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "servo_control/MotorVector.h"
#include "geometry_msgs/PoseStamped.h"
#include "../include/Robot_Control.h"
#include "../include/CallTheDead.h"
#include "robotkinematics/goToInit.h"
#include "servo_driver/getUp.h"
#include <math.h>
#include <unistd.h>
// C++ includes
#include <sstream>
#include <iostream>
void rot2zyx(double rot[9], double eul[3]) {
  double alpha;
  double gam;
  double beta;
  if(rot[0]==0 && rot[3]==0) {
    beta=3.1415/2;
    alpha=0;
    gam=atan2(rot[3],rot[4]);
  } else {
    beta=atan2(-rot[2],sqrt(rot[0]*rot[0]+rot[1]*rot[1]));
    alpha=atan2(rot[1],rot[0]);
    gam=atan2(rot[5],rot[8]);
  }
  eul[0]=alpha;
  eul[1]=beta;
  eul[2]=gam;
}
void quat2eul(double q[4], double eul[3]) {
  eul[0]=atan2(2*(q[0]*q[1]+q[2]*q[3]),1-2*(q[2]*q[2]+q[1]*q[1]));
  eul[1]=asin(2*(q[0]*q[2]-q[3]*q[1]));
  eul[2]=atan2(2*(q[0]*q[3]+q[1]*q[2]),1-2*(q[2]*q[2]+q[3]*q[3]));
}
double norm_vec(double v[3]) {
  return(sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]));
}
double r_II_B_d[3];
double Euler_d[3];
double gamma_m[36];
bool init_toggle = 1;
double theta1_d_out[4];
double theta2_d_out[4];
double theta3_d_out[4];
double phi_d_temp;
double r_II_B_d_temp[3];
bool floor_toggle_out[4];
bool legs_valid_out[4];
bool target_set = 0;
bool legs_on_gnd[4];
double Theta[12];
double r_II_B_dead[3];
double T_I_B_dead[9];
bool prev_legs_valid[4];
bool legs_valid[4];
double r_II_C_dead[12];
double eulAng[3];
bool firstRun=1;
void setTargetPosCallback(const geometry_msgs::PoseStamped msg) {
  std::cout<<"Hello from a callback\n";
  target_set = 1;
  
  r_II_B_d[0]=msg.pose.position.x*10;
  r_II_B_d[1]=msg.pose.position.y*10;
  r_II_B_d[2]=.21;
  Euler_d[0]=0;
  Euler_d[1]=0;
  Euler_d[2]=0;
}
bool pos_rec = 0;
void getCurrentPos(const geometry_msgs::PoseStamped msg) {
  pos_rec=1;
  gamma_m[0]=msg.pose.position.x;
  gamma_m[1]=msg.pose.position.y;
  gamma_m[2]=msg.pose.position.z;
  double q[4];
  q[0]=msg.pose.orientation.w;
  q[1]=msg.pose.orientation.x;
  q[2]=msg.pose.orientation.y;
  q[3]=msg.pose.orientation.z;
  std::cout << "x: " << gamma_m[0] << ", y: " <<gamma_m[1] << ", z: " << gamma_m[2] << "\n";
  double eul[3];
  quat2eul(q,eul);
  gamma_m[3]=0; //eul[0];
  gamma_m[4]=0;//eul[1];
  gamma_m[5]=0;//eul[2];
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
  //ROS_INFO("Recieving Servo Feedback\n");
//  if(init_toggle==0) {
    for(int i=0; i<13;i++) {
      gamma_m[i+6]=msg.data[i];
 //   }
  }
  //std::cout << " is the recorded theta1\n";
  
}

int main(int argc, char **argv) {
  for(int i = 0; i<36; i++) {
   gamma_m[i]=0;
  }
/*  gamma_m[5]=.2;
  gamma_m[6]=3.1415/4.0;
  gamma_m[7]=-3.1415/4.0;
  gamma_m[8]=-3.1415/4.0;
  gamma_m[9]=3.1415/4.0;

  gamma_m[10]=0;
  gamma_m[11]=0;
  gamma_m[12]=0;
  gamma_m[13]=0;
  gamma_m[14]=3.1415/2;
  gamma_m[15]=-3.1415/2;
  gamma_m[16]=3.1415/2;
  gamma_m[17]=-3.1415/2;*/
  gamma_m[0]=0;
  gamma_m[1]=0;
  gamma_m[2]=0;
  gamma_m[3]=0;
  gamma_m[4]=0;
  gamma_m[5]=.24;
  gamma_m[6]=3.1415/4.0;
  gamma_m[7]=-3.1415/4.0;
  gamma_m[8]=-3.1415/4.0;
  gamma_m[9]=3.1415/4.0;
  gamma_m[10]=3.1415/6;
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
  ros::Publisher target_pub = n.advertise<servo_control::MotorVector>("servo_goal_positions",1000);
  ros::Rate loop_rate(20);
  ros::Subscriber sub=n.subscribe("servo_feedback",1000,servoCallback);
  ros::Subscriber targetPos_sub=n.subscribe("rtabmap/goal",1000,setTargetPosCallback);
  //ros::Subscriber currentPos_sub=n.subscribe("pose_combined",1000,getCurrentPos);
  ros::ServiceServer initSrv= n.advertiseService("robot_state",robotStateHandler);
  ros::ServiceClient resetSrv=n.serviceClient<servo_driver::getUp>("get_up");
  servo_driver::getUp getUpClient;

  r_II_B_d[0]=0;//msg.pose.position.x;
  r_II_B_d[1]=0;//msg.pose.position.y;
  r_II_B_d[2]=.21;
  Euler_d[0]=0;
  Euler_d[1]=0;
  Euler_d[2]=0;  int cnt=0;
  for(int i =0;i<3;i++) legs_on_gnd[i]=1;
//  Codegen::Robot_Control_init();
  while(ros::ok()) {
    if(moveToInit==1) {
    /* servo_control::MotorVector msg;
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
     target_pub.publish(msg);*/
    } else {
//    std::cout <<"in a while loop\n";
      if(1==1) {
        servo_control::MotorVector msg;

      for(int i = 0; i<17; i++) {
          std::cout << "gamma_m[" << i << "]: " << gamma_m[i] << "\n";
      }
      for(int i = 0; i<4;i++) legs_on_gnd[i]=0;
      try {
      Codegen::Robot_Control(r_II_B_d, Euler_d,gamma_m,init_toggle,legs_on_gnd,theta1_d_out,theta2_d_out,theta3_d_out,
                    &phi_d_temp, r_II_B_d_temp, floor_toggle_out,legs_valid);
      double err[3];
      err[0]=r_II_B_d_temp[0]-gamma_m[3];
      err[1]=r_II_B_d_temp[1]-gamma_m[4];
      err[2]=r_II_B_d_temp[2]-gamma_m[5];
      std::cout<<"Body pose error: " <<norm_vec(err)<<"\n";
      err[0]=theta1_d_out[0]-gamma_m[6];
      err[1]=theta2_d_out[0]-gamma_m[10];
      err[2]=theta3_d_out[0]-gamma_m[14];
      std::cout<<"Step pose error: " <<norm_vec(err)<<"\n";
      for(int i = 0; i<6; i++) {
      //    std::cout << "gamma_m[" << i << "]: " << gamma_m[i] << "\n";
      }      
      for(int i = 0; i<3; i++) {
          std::cout << "r_II_B_d[" << i << "]: " << r_II_B_d[i] << "\n";
      }      
      for(int i = 0; i<4; i++) {
          std::cout << "legs_valid[" << i << "]: " << legs_valid[i] << "\n";
      }
      for(int i = 0; i<4; i++) {
          std::cout << "prev_legs_valid[" << i << "]: " << prev_legs_valid[i] << "\n";
      }
      for(int i = 0; i<12; i++) {
          std::cout << "r_II_C_dead[" << i << "]: " << r_II_C_dead[i] << "\n";
      }      
      init_toggle=0;

        for(int i = 0;i<12;i++) Theta[i]=gamma_m[i+6];
        if(firstRun==1) {
          for(int i =0; i<12;i++) r_II_C_dead[i]=0;
          for(int i =0; i<4;i++) prev_legs_valid[i]=1;
          for(int i =0; i<9;i++) T_I_B_dead[i]=0;
          std::cout <<"first\n";
          T_I_B_dead[0]=1;
          T_I_B_dead[4]=1;
          T_I_B_dead[8]=1;
          r_II_B_dead[0]=0;
          r_II_B_dead[1]=0;
          r_II_B_dead[2]=.21;
        Codegen::CallTheDead(Theta,r_II_B_dead,T_I_B_dead,firstRun,legs_valid,prev_legs_valid,r_II_C_dead);
        firstRun=0;
        } else {
          for(int i =0; i<9;i++) T_I_B_dead[i]=0;
          T_I_B_dead[0]=1;
          T_I_B_dead[4]=1;
          T_I_B_dead[8]=1;

          Codegen::CallTheDead(Theta,r_II_B_dead,T_I_B_dead,firstRun,legs_valid,prev_legs_valid,r_II_C_dead);
        }
         for(int i =0; i<9;i++) T_I_B_dead[i]=0;
          T_I_B_dead[0]=1;
          T_I_B_dead[4]=1;
          T_I_B_dead[8]=1;

      rot2zyx(T_I_B_dead, eulAng);
//      if(r_II_B_dead[2]>.25) r_II_B_dead[2]=.25;
      r_II_B_dead[2]=.21;
      gamma_m[0]=eulAng[0];
      gamma_m[1]=eulAng[1];
      gamma_m[2]=eulAng[2];
      gamma_m[3]=r_II_B_dead[0];
      gamma_m[4]=r_II_B_dead[1];
      gamma_m[5]=r_II_B_dead[2];

      std::cout << "theta1[1]: " << theta1_d_out[0] << "\n";
      for(int i =0; i<4;i++){ 
        msg.data[i]=theta1_d_out[i];
        std::cout << "Error in joint " << i << ": " << (theta1_d_out[i]-gamma_m[i+6])*180.0/3.1415 << "\n";
      }
      for(int i =4; i<8;i++){
         msg.data[i]=theta2_d_out[i-4];
         std::cout << "Error in joint " << i << ": " << (theta2_d_out[i-4]-gamma_m[i+6])*180.0/3.1415 << "\n";
      }
      for(int i =8; i<12;i++) {
        msg.data[i]=theta3_d_out[i-8];
        std::cout << "Error in joint " << i << ": " << (theta3_d_out[i-8]-gamma_m[i+6])*180.0/3.1415 << "\n";
      }
      target_pub.publish(msg);
    } catch(...) {
      std::cout << "Caught an error\n";
      getUpClient.request.begin=1;
      if(resetSrv.call(getUpClient)) {
        std::cout << "server Response : " << getUpClient.response.end << "\n";
        ros::Duration(8).sleep();
        gamma_m[6]=3.1415/4.0;
        gamma_m[7]=-3.1415/4.0;
        gamma_m[8]=-3.1415/4.0;
        gamma_m[9]=3.1415/4.0;
        gamma_m[10]=3.1415/6;
        gamma_m[11]=-3.1415/6;
        gamma_m[12]=3.1415/6;
        gamma_m[13]=-3.1415/6;
        gamma_m[14]=3.1415/3;
        gamma_m[15]=-3.1415/3;
        gamma_m[16]=3.1415/3;
        gamma_m[17]=-3.1415/3;

      } else {
        ROS_ERROR("service done bricked itself");
        return 1;
      }
    }

    }

    }
      
      ros::spinOnce();
      loop_rate.sleep();
      ++cnt;

  }
  return 0;
}
