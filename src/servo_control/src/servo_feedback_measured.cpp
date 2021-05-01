#include "ros/ros.h"
#include "servo_control/MotorVector.h"
#include <math.h>
#include <sstream>
#include <iostream>
#include <vector>
#include "servo_adc.h"
#define PI 3.1415926535
#define M 60
// ADC stuff
std::vector<double> h_conv;
void init_vector(void) {
  double fc=.01/5;
  double K=1./PI;
  for(int i =0;i<M;i++) {
    if(i==M/2) h_conv.push_back(2.*PI*fc*K);
    else h_conv.push_back(K*sin(2.*PI*fc*(i-M/2.))/(i-M/2.)*(.42-.5*cos(2.*PI*i/M)+.08*cos(4.*PI*i/M)));
  }
//  std::cout <<"there?\n";
}
int conv_iter=0;
std::vector<double> shift_in(std::vector<double> oldVec,double data) {
  std::vector<double> newVec(40);
  newVec.push_back(data);
  for(size_t i =0; i< oldVec.size()-1;i++) {
  //  std::cout << "In shift " << i << " dim: " << oldVec.size() <<"\n";
    newVec.at(i+1)=oldVec.at(i);
  }
  return newVec;
}
double conv(std::vector<double> h, std::vector<double> x) {
  double result=0;
  if(conv_iter>M) {
    for(int i=0;i<40;i++) {
      result+=h[M-i]*x[i];
    }
  }
  conv_iter++;
  return result;
}
int main(int argc, char **argv) {
uint16_t adcVals[15];
std::vector<std::vector<double>> servoPoses{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

  init_vector();
  ros::init(argc,argv,"servo_feedback_measured");
  ros::NodeHandle n;
  ros::Publisher target_pub = n.advertise<servo_control::MotorVector>("servo_feedback",1000);
  ros::Rate loop_rate(5);
//  if(setupADC(&adcDevice,&adcGPIO)) {
//    std::cout << "ADC init error. Closing Servo Feedback node.\n";
//    return 0;
//  }
  servo_control::MotorVector msg;

  while(ros::ok()) {
    if(readADC(adcVals)) {
      std::cout << "ADC read error. Closing Servo Feedback node.\n";
      break;
    }
   bool cancel=0;
   int nonzerocnt=0;
   for(int i = 0; i <13;i++) {
     if(adcVals[i]!=0) {
       nonzerocnt++;
     }
     msg.data[i]=(adcVals[i]-540)*3.0*PI/2.0/1024.0;
     if(i==4) msg.data[i]=-msg.data[i];
     if(i==6) msg.data[i]=-msg.data[i];
//     if(i==8) msg.data[i]=-msg.data[i];
     if(i==9) msg.data[i]=-msg.data[i];
     if(i==11) msg.data[i]=-msg.data[i];

     std::cout << i <<": " << msg.data[i]*180.0/3.1415 << ", ";
   //  std::cout << "how about here?\n";

     servoPoses[i]=shift_in(servoPoses[i],msg.data[i]);
     double result=conv(h_conv,servoPoses[i]);
     if(result != 0) {
       msg.data[i]=result;
     }
   }
   if(cancel==0 &&nonzerocnt!=0) {
   target_pub.publish(msg);
//   std::cout<<msg.data[0];
   std::cout << "\n";
   }
   loop_rate.sleep();
  }

//  if(closeADC(&adcDevice,&adcGPIO)) {
//    std::cout << "ADC close error.\n";
//   return -1;
//  }
  return 0;
}
