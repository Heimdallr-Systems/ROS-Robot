#include "ros/ros.h"
#include "servo_control/MotorVector.h"
#include <math.h>
#include <sstream>
#include <iostream>
#include "servo_adc.h"
#define PI 3.1415926535
// ADC stuff
ADC_SPI_T adcDevice;
ADC_GPIO_T adcGPIO;
uint16_t adcVals[15];
int main(int argc, char **argv) {
  ros::init(argc,argv,"servo_feedback_measured");
  ros::NodeHandle n;
  ros::Publisher target_pub = n.advertise<servo_control::MotorVector>("servo_feedback",1000);
  ros::Rate loop_rate(5);
  if(setupADC(&adcDevice,&adcGPIO)) {
    std::cout << "ADC init error. Closing Servo Feedback node.\n";
    return 0;
  }
  servo_control::MotorVector msg;

  while(ros::ok()) {
    if(readADC(&adcDevice, &adcGPIO,adcVals)) {
      std::cout << "ADC read error. Closing Servo Feedback node.\n";
      break;
    }
   bool cancel=0;
   int nonzerocnt=0;
   for(int i = 0; i <13;i++) {
//     if(adcVals[i]>4000.0) {
//       cancel=1;
//       break;
//     std::cout << "Large value detected: " << adcVals[i] <<"\n";
//     adcVals[0]=adcVals[i]%1023;
//     }
     if(adcVals[i]!=0) {
       nonzerocnt++;
     }
//     std::cout << i <<": " << adcVals[i] << ", ";
     msg.data[i]=adcVals[i];//*3*PI/2.0/1024.0-PI/2.0;
   }
   if(cancel==0 &&nonzerocnt!=0) {
   target_pub.publish(msg);
//   std::cout<<msg.data[0];
//   std::cout << "\n";
   }
   loop_rate.sleep();
  }

  if(closeADC(&adcDevice,&adcGPIO)) {
    std::cout << "ADC close error.\n";
   return -1;
  }
  return 0;
}
