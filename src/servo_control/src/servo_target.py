#!/usr/bin/env python
import rospy
import pca9685_controller as pca
from std_msgs.msg import String
from servo_control.msg import MotorVector
import math
def servo_Target():
  cnt=0
  dir = 1
  pub =rospy.Publisher('servo_goal_positions',MotorVector,queue_size=10)
  rospy.init_node('servo_goal_positions',anonymous=True)
  rate=rospy.Rate(10) # 10 Hz refresh rate
  while not rospy.is_shutdown():
    targets = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    target_str=""
    for i in range(0,len(targets)):
      targets[i]= cnt*math.pi/180
    cnt+=20*dir
    if(cnt>=120):
      dir = -1
    elif(cnt<=-120):
      dir = 1
    target_str=MotorVector()
    target_str.data=targets
    rospy.loginfo(str(targets))
    pub.publish(target_str)
    rate.sleep()

if(__name__ == '__main__'):
  try:
    servo_Target()
  except rospy.ROSInterruptException:
    pass

