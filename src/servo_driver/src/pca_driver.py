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
  pi=3.1415926535
  servo_poses=[pi/4.0,-pi/4.0, -pi/4.0, pi/4.0, pi/6.0,pi/6.0, pi/6.0,pi/6.0,pi/3.0, -pi/3.0,pi/3.0,-pi/3.0,0,0]
  ports=[0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13]
  for i in range(0,13):
    q=pca.drive_servos(pwm,0,i)

  while(True):
    a=str(input("Press 1 to initialize port zero, 2 to stand up: "))
    if(a=='1'):
      print("driving servo 1 to zero")
      q=pca.drive_servos(pwm,-pi/4,0)
      time.sleep(2)
      print("at initial pose")
    elif(a=='2'):
      print("driving robot to an initial position")
      for i in range(0,len(ports)):
        a=pca.drive_servos(pwm,servo_poses[i],ports[i])
      time.sleep(5)
      print("done")
#  servo_target_listener()
