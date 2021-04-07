#!/usr/bin/env python
import rospy
import pca9685_controller as pca
from std_msgs.msg import String
from servo_control.msg import MotorVector
import time
import math  
def callback(data):
  # Callback fcn
  print(data[0])
  for i in range(0,len(data)):
#    print("trying: \"" +str(data[i]) + "\"")
    pos=data[i]
    a=pca.drive_servos(pwm,pos,i-offset)
    print(a[1])
#    time.sleep(.1)
def servo_target_listener():
  pos=0
  mult=5
  while(1):
      pos+=1*mult
      a=pca.drive_servos(pwm,float(pos)*math.pi/180.0,0)
      if(pos>180):
        mult=-5
      elif(pos<=0):
        mult=5
      print(pos)
      time.sleep(.1)
#  rospy.init_node('servo_driver_target_listener',anonymous=True)
#  rospy.Subscriber("servo_goal_positions",MotorVector,callback)
#  rospy.spin()

if __name__ == '__main__':
  print("Note: Initializing PCA9685 servo driver...")
  pwm=pca.init_pca9685()
  while(True):
    a=pca.drive_servos(pwm,0,0)
    time.sleep(.1)
    print("Driving servo to zero")
#  servo_target_listener()
