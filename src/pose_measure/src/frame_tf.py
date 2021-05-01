#!/usr/bin/env python
import rospy
import math
from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Quaternion
from geometry_msgs.msg import Vector3
from nav_msgs.msg import Odometry
from servo_control.msg import MotorVector
from scipy.spatial.transform import Rotation as R
import numpy as np
have_imu_data=0
have_RTAB_data=0
imu_position = [0,0,0]
imu_orien=R.from_quat([0,0,0,1])
RTAB_orien=[0,0,0,1]
RTAB_position=[0,0,0]
alpha=0
beta=0
#r_bb_1=[0;0;.1]
 #r_11_2=[.1;.1;.1]
#r_22_cam=[.1;0;.1]
def RTAB_callback(data):
  global RTAB_orien
  global have_RTAB_data
  global RTAB_position
  data=data.pose
  quat=[data.pose.orientation.w,data.pose.orientation.x,data.pose.orientation.y,data.pose.orientation.z]
  RTAB_position[0]=data.pose.position.x
  RTAB_position[1]=data.pose.position.y
  RTAB_position[2]=data.pose.position.z+.26
  RTAB_orien=quat
  have_RTAB_data =1
  print("In RTAB callback")
def quat2R(q):
  w=q[0]
  x=q[1]
  y=q[2]
  z=q[3]
  r=np.asarray([[w**2.+x**2.-y**2.-z**2.,2.*x*y+2.*w*z, 2.*x*z-2*w*y],
                [2.*x*y-2.*w*z, w**2.-x**2.+y**2.-z**2., 2.*y*z+2.*w*x],
                [2.*x*z+2*w*y, 2.*y*z-2.*w*x, w**2.-x**2.-y**2.+z**2.]])
  return r
def R2quat(R):
  q=[0.0,0.0,0.0,0.0]
  q[0]=math.sqrt(1+R[0,0]+R[1,1]+R[2,2])/2.0
  w4=4.0*q[0]

def IMU_callback(data):
  global have_imu_data
  global imu_position
  global imu_orien
  quat=Quaternion()
  quat=data.orientation
  imu_orien=R.from_quat(quat)
  have_imu_data=1
def feedbackCB(data):
  global alpha
  global beta
  alpha=data.data[12]
  beta=data.data[13]

def combine_orientation():
  global alpha
  global beta
  global RTAB_orien
  
  r_BB_cam=[0,0,0]
  position = RTAB_position
  #orien_rtab = RTAB_orien.as_quat
  #angle=math.sqrt(orien_imu[0]**2 + orien_imu[0]**2 + orien_imu[0]**2)
  #orien_imu=[orien_imu[0]/angle,orien_imu[1]/angle,orien_imu[2]/angle]
  ''' T_cam_b=np.asarray([[math.cos(alpha)*math.cos(beta),math.cos(beta)*math.sin(alpha),-math.sin(beta)],
                   [-math.sin(alpha),math.cos(alpha),0],
                   [math.cos(alpha)*math.sin(beta),math.sin(alpha)*math.sin(beta),math.cos(beta)]])
  print("Angle feedback:")
  print(T_cam_b)
  position[0]=position[0]
  position[1]=position[1]
  position[2]=position[2]-.2
  q =quat2R(RTAB_orien)
  
  T_cam_b=T_cam_b.astype("float")
  orien=np.matmul(np.linalg.inv(T_cam_b),q)
  orien=R.from_dcm(orien)
  print("in func")
  orien_imu=orien.as_quat()'''
  position[0]=position[0]
  position[1]=position[1]
  position[2]=position[2]
  return [position, RTAB_orien]

if(__name__=='__main__'):
  try:
    pub=rospy.Publisher('pose_combined',PoseStamped,queue_size=10)
    rospy.init_node('frame_tf',anonymous=True)
    rospy.Subscriber('/rtabmap/odom',Odometry,RTAB_callback,queue_size=1)
    rospy.Subscriber('/data',Imu,IMU_callback,queue_size=1)
    #rospy.Subscriber('/servo_feedback',MotorVector,feedbackCB,queue_size=1)
    rate=rospy.Rate(5)
    while not rospy.is_shutdown():
      if(have_RTAB_data !=0):

        united_orientation = [1, 0, 0, 0]
        united_position = [0, 0, 0]
        res=combine_orientation()
        united_orientation=res[1]
        united_position=res[0]
        print(united_orientation)
        currentPose=PoseStamped()
        currentPose.header.stamp=rospy.Time.now()
        currentPose.pose.orientation.w=united_orientation[0]
        currentPose.pose.orientation.x=united_orientation[1]
        currentPose.pose.orientation.y=united_orientation[2]
        currentPose.pose.orientation.z=united_orientation[3]
        currentPose.pose.position.x=united_position[0]
        currentPose.pose.position.y=united_position[1]
        currentPose.pose.position.z=united_position[2]
        pub.publish(currentPose)
        print("Here")
      rate.sleep()
  except rospy.ROSInterruptException:
    pass
