#!/usr/bin/env python
import rospy
from std_msgs.msg import String, Bool
import math
from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import Joy
goalMsg=PoseStamped()
auton_goalMsg=PoseStamped()
first_message=False
currentAngle=0
nextAngle=0
angleIntegrationSensitivity=.1
robotInAuton=False
def joystick_callback(data):
  global nextAngle
  global angleIntegrationSensitivity
  #TODO: Add relative goals, ie new_x=old_x+joy_x
  xAxis=data.axes[1]*.2
  yAxis=data.axes[0]*.2
  angleIntegrationSensitivity=.2*(1+data.axes[3])
  nextAngle=angleIntegrationSensitivity*data.axes[2]
  first_message=True
  goalMsg.pose.position.x=xAxis
  goalMsg.pose.position.y=yAxis
  goalMsg.pose.position.z=0
  
def servo_Target():
  global currentAngle
  global nextAngle
  cnt=0
  dir = 1
  pub =rospy.Publisher('goal',PoseStamped,queue_size=10)
  rospy.init_node('goal',anonymous=True)
  rospy.Subscriber('joy',Joy,joystick_callback,queue_size=1)
  autonStatusSubscriber()
  rate=rospy.Rate(5) # 10 Hz refresh rate
  while not rospy.is_shutdown():
    if(robotInAuton==False):
      goalMsg.header.frame_id="/map"
      goalMsg.header.stamp=rospy.Time.now()
      zAxis=currentAngle+angleIntegrationSensitivity*nextAngle
      currentAngle=zAxis
      goalMsg.pose.orientation.w=math.cos(zAxis*math.pi)
      goalMsg.pose.orientation.x=0
      goalMsg.pose.orientation.y=0
      goalMsg.pose.orientation.z=math.sin(zAxis*math.pi)
#    goalMsg.pose.position.x=5
#    goalMsg.pose.position.y=0
#    goalMsg.pose.position.z=0
#    goalMsg.pose.orientation.x=0
#    goalMsg.pose.orientation.y=0
#    goalMsg.pose.orientation.z=0
#    goalMsg.pose.orientation.w=1
      rospy.loginfo("Publishing target position. Angle: "+str(currentAngle))
      pub.publish(goalMsg)
    rate.sleep()
# Subscriber to the robot_in_auton node
def autonStatusCallback(data):
  global robotInAuton
  if(data.data==True):
 # In autonomous mode. The robot should watch for messages from some sort of 
 # "Path planning" node, sampled every 1 meter.
    rospy.loginfo("Robot is now in autonomous mode.")
    robotInAuton=True
  else:
    # in teleoperation, the robot subscribes to the joystick node, and is controlled by a human
    rospy.loginfo("Robot is now in teleoperation mode.")
    robotInAuton=False
def autonStatusSubscriber():
  rospy.Subscriber('robot_in_auton',Bool,autonStatusCallback,queue_size=1)
if(__name__ == '__main__'):
  try:
    servo_Target()
  except rospy.ROSInterruptException:
    pass






