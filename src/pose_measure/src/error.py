#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Imu
from scipy.spatial.transform import Rotation as R

def callback(data):
  print("In callback")
  new=""
  orien_q=[data.orientation.w,data.orientation.x,data.orientation.y,data.orientation.z]
  orien=R.from_quat(orien_q)
  orien_AA=orien.as_rotvec()
  new=str(orien_AA)+"\n"
  file=open("test_imu.txt",'a+')
  file.write(new)
  file.close()
  print("saved a line to a file")
if(__name__=='__main__'):
  print("Node doing node things")
  rospy.init_node('error_logging',anonymous=True)
  rospy.Subscriber('imu/data',Imu,callback,queue_size=1)
  rospy.spin()
