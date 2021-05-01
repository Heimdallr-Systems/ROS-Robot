#!/usr/bin/env python
import rospy
import pca9685_controller as pca
from std_msgs.msg import String
from servo_control.msg import MotorVector
from std_msgs.msg import Float32
from servo_driver.srv import getUp,getUpResponse
import time
import math  
prevpose= [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
def lpf(x,y_prev):
  dt=.05;
  fc=.1;
  al=2.0*math.pi*dt/(2.0*pi*dt*fc+1)
  return al*x+(1-al)*y_prev
def callback(data):
  global prevpose
  currpose=[]
  pi=math.pi
  pose=0
  # Callback fcn
#  print(data[0])
  inv= [4,6,9,11]
  for i in range(0,13):
    pos=data.data[i];
    ovf=0
    if(i in inv):
      pos=-pos
      #print("Inverting servo " + str(i) + ". Was " + str(data.data[i]) + ", is now " + str(pos))
    else:
        pos=pos
    if(abs(pos*180.0/pi)>110):
      print("Overflow on port " + str(i))
      if(pos>0):
        pos=100.0*pi/180.0
      else:
        pos=-100.0*pi/180.0
        print("set negative: "+str(pos*180.0/pi))
#    print("Driving servo "+str(i) + " to \"" +str(data.data[i]*180.0/math.pi) + "\" degrees.")
    currpose.append(pos)
#    print(prevpose)
    dest=lpf(pos,prevpose[i])
    prevpose[i]=dest
    a=pca.drive_servos(pwm,dest,i)
    #a=pca.drive_servos(pwm,0,4)
#    print(a[1])
#    time.sleep(.1)
    #rospy.sleep(1)
def servoMoveLpf(data):
  global prevpose
  currpose=[]
  pi=math.pi
  pose=0
  # Callback fcn
#  print(data[0])
  inv= [4,6,9,11]
  for i in range(0,13):
    pos=data[i];
    ovf=0
    if(i in inv):
      pos=-pos
      #print("Inverting servo " + str(i) + ". Was " + str(data.data[i]) + ", is now " + str(pos))
    else:
      pos=pos
    if(abs(pos*180.0/pi)>110):
      print("Overflow on port " + str(i))
      if(pos>0):
        pos=100.0*pi/180.0
      else:
        pos=-100.0*pi/180.0
        print("set negative: "+str(pos*180.0/pi))
 #   print("Driving servo "+str(i) + " to \"" +str(data[i]*180.0/math.pi) + "\" degrees.")
#    print prevpose;
#    print("Slowing")
    currpose.append(pos)
    dest=lpf(pos,prevpose[i])
    prevpose[i]=dest
    a=pca.drive_servos(pwm,dest,i)
    #a=pca.drive_servos(pwm,0,4)
#    print(a[1])
#    time.sleep(.1)
    #rospy.sleep(1)
def pan_callback(data):
  pca.drive_servos(pwm,data.data,12)
  print("pan")
def tilt_callback(data):
  pca.drive_servos(pwm,data.data,13)
  print("tilt")
lastSrvResp=0;
def getup_handle(req):
  step1=[pi/4.0,-pi/4.0,-pi/4.0,pi/4.0, -pi/4.0-.3,pi/4.0+.3,-pi/4.0-.3,pi/4.0+.3,3.0*pi/4.0,-3.0*pi/4.0,3.0*pi/4.0,-3.0*pi/4.0,0,0]
  step2=[pi/4.0,-pi/4.0,-pi/4.0,pi/4.0,pi/6.0,-pi/6.0,pi/6.0,-pi/6.0,pi/3.0,-pi/3.0,pi/3.0,-pi/3,0,0]
  global pwm
  global lastSrvResp
  for i in range(0,20):
    servoMoveLpf(step1);
    time.sleep(.1)

  time.sleep(3);

#  for i in range(0,20):
#    servoMoveLpf(step2);
#    time.sleep(.1)
  for i in range(0,14):
    pca.drive_servos(pwm,0,i)
    #inv= [4,6,9,11]
    #if(i in inv):
    #  q=pca.drive_servos(pwm,-step2[i],i)
    #else:
    #  q=pca.drive_servos(pwm,step2[i],i)
  time.sleep(3)
  if(lastSrvResp):
    lastSrvResp=0
  else:
    lastSrvResp=1
  return getUpResponse(lastSrvResp)
def servo_target_listener():
  pos=0
  mult=5
  rospy.init_node('servo_driver_target_listener',anonymous=True)
  rospy.Subscriber("servo_goal_positions",MotorVector,callback)
  rospy.Subscriber("servo",MotorVector,callback)
  rospy.Subscriber("pan_target",Float32,pan_callback)
  rospy.Subscriber("tilt_target",Float32,tilt_callback)
  s=rospy.Service('get_up',getUp,getup_handle)
#  while(1):
#     rospy.spin()

if __name__ == '__main__':
  print("Note: Initializing PCA9685 servo driver...")
  pwm=pca.init_pca9685()
  pi=3.1415926535
  servo_poses=[pi/4.0,-pi/4.0, -pi/4.0, pi/4.0, -.1,-.1,-.1,-.1,pi/2.0, pi/2.0,-pi/2.0,-pi/2.0,-pi/4.0,0]
  th1=0.7416
  th2=1.2748
  servo_poses=[pi/4,-pi/4.0,-pi/4.0,pi/4.0,th1,-th1,th1,-th1,th2,-th2,th2,-th2,0,0]
  servo_poses_1=[pi/4.0,-pi/4.0-pi/3.0, -pi/4.0+pi/4.0, pi/6.0, pi/6.0,pi/6.0,pi/6.0,pi/6.0,pi/2.0, pi/2.0+pi/4.0,pi/2.0+pi/4.0,pi/2.0+pi/3.0,pi/4.0,0]
  step1=[pi/4.0,-pi/4.0,-pi/4.0,pi/4.0, -pi/4.0-.3,pi/4.0+.3,-pi/4.0-.3,pi/4.0+.3,3.0*pi/4.0,-3.0*pi/4.0,3.0*pi/4.0,-3.0*pi/4.0,0,0]
  step2=[0.7854,-0.7854,-0.7854,0.7854,0.2542,-0.2542,0.2542,-0.2542, 1.5095,-1.5095,1.5095,-1.5095,0,-pi/4.0-pi/12.0]
  ports=[0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13]
  for i in range(0,14):
#    pca.drive_servos(pwm,0,i)
    inv= [4,6,9,11]
    
    if(i in inv):
      q=pca.drive_servos(pwm,-servo_poses[i],i)
      prevpose[i] = -servo_poses[i]
    else:
      q=pca.drive_servos(pwm,servo_poses[i],i)
      prevpose = servo_poses

 # input("press something to begin servo stuff")
 # pca.drive_servos(pwm,-3.0*pi/4.0,10) 
  time.sleep(3)
  #pca.drive_servos(pwm,pi/2.0,9)
  #input("hui")
  ''' inv=[4,7,9,10]
  for i in range(0,13):
    if(i==8):
      time.sleep(.5)
    if(i in inv):
      q=pca.drive_servos(pwm,-step1[i],i)
    else:
      q=pca.drive_servos(pwm,step1[i],i)
    if(i>8):
      input("press somethin")'''
  '''  time.sleep(5)
  for i in range(0,14):
    if(i in inv):
      q=pca.drive_servos(pwm,-step2[i],i)
    else:
      q=pca.drive_servos(pwm,step2[i],i)'''
  time.sleep(5)
  # Tilt around to make RTAB work
  '''offset=pi/2.0+pi/12.0
  for i in range(0,9):
    pca.drive_servos(pwm,float(i)*5.0*pi/180.0+offset,14)
    time.sleep(0.1) <
  for i in range(0,18):
    pca.drive_servos(pwm,float(9-i)*5.0*pi/180.0+offset,14)
    time.sleep(0.1)
  for i in range(0,9):
    pca.drive_servos(pwm,float(i-9)*5.0*pi/180.0+offset,14)
    time.sleep(0.1)
'''
#  for i in range(0,14):
#    pca.drive_servos(pwm,pi/4.0,i)
#    asd=input("make servo go:")
  servo_target_listener()
  while(not rospy.is_shutdown()):
#     poseTest()
     rospy.spin()
#    servo_target_listener()

