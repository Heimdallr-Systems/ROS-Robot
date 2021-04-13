#!/usr/bin/env python
import rospy
import pca9685_controller as pca
from std_msgs.msg import String
from servo_control.msg import MotorVector
from std_msgs.msg import Float32
import time
import math  
def callback(data):
  # Callback fcn
#  print(data[0])
  for i in range(0,len(data)-2):
    print("Driving servo "+str(i) + " to \"" +str(data[i]) + "\" radians.")
    pos=data[i]
    a=pca.drive_servos(pwm,pos,i)
#    print(a[1])
#    time.sleep(.1)
def pan_callback(data):
  pca.drive_servos(pwm,data.data,12)

def tilt_callback(data):
  pca.drive_servos(pwm,data.data,13)

def servo_target_listener():
  pos=0
  mult=5
  rospy.init_node('servo_driver_target_listener',anonymous=True)
  #rospy.Subscriber("servo_goal_positions",MotorVector,callback)
  rospy.Subscriber("pan_target",Float32,pan_callback)
  rospy.Subscriber("tilt_target",Float32,tilt_callback)
   
#  while(1):
#     rospy.spin()
def poseTest():
  servo_poses=[pi/4.0,-pi/4.0, -pi/4.0, pi/4.0, 0,0,0,0,pi/2.0, pi/2.0,pi/2.0,pi/2.0,pi/4.0,0]
  servo_poses_1=[pi/4.0,-pi/4.0-pi/3.0, -pi/4.0+pi/4.0, pi/4.0,0,0,0,0,pi/2.0, pi/2.0,pi/2.0, pi/2.0,pi/2.0,0]

  a=str(input("Press 1 to initialize port zero, 2 to stand up: "))
  if(a=='1'):
    print("driving servo 1 to zero")
    for i in range(0,14):
      q=pca.drive_servos(pwm,servo_poses[i],i)
    print("at initial pose")
  elif(a=='2'):
    print("driving robot to an initial position")
    for i in range(0,14):
      pca.drive_servos(pwm,servo_poses_1[i],i)
    time.sleep(2)
    a=pca.drive_servos(pwm,pi/4,4)
    time.sleep(3)
    '''for i in range(0,3):
        if(servo_poses[i]>0):
          multi=1
        else:
          multi=-1
        pca.drive_servos(pwm,servo_poses[i]+pi/6,i)
      time.sleep(3)
      for i in range(0,3):
        pca.drive_servos(pwm,servo_poses[i],i)
      time.sleep(3)'''
    print("done")
#  

if __name__ == '__main__':
  print("Note: Initializing PCA9685 servo driver...")
  pwm=pca.init_pca9685()
  pi=3.1415926535
  servo_target_listener()
  servo_poses=[pi/4.0,-pi/4.0, -pi/4.0, pi/4.0, 0,0,0,0,pi/2.0, pi/2.0,pi/2.0,pi/2.0,pi/4.0,0]
  servo_poses_1=[pi/4.0,-pi/4.0-pi/3.0, -pi/4.0+pi/4.0, pi/6.0, pi/6.0,pi/6.0,pi/6.0,pi/6.0,pi/2.0, pi/2.0+pi/4.0,pi/2.0+pi/4.0,pi/2.0+pi/3.0,pi/4.0,0]
  ports=[0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13]
  for i in range(0,14):
    q=pca.drive_servos(pwm,0,i)
#    input("press something")
  while(not rospy.is_shutdown()):
     poseTest()
#     rospy.spin()
#    servo_target_listener()

