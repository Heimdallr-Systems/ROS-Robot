#!/usr/bin/env python
import rospy
from std_msgs.msg import Float32
import math
pi=math.pi
pan_angle=0.0
tilt_angle=0.0
tilt_offset=pi/2.0+pi/12.0
pan_increment=0.5*pi/180.0
pan_max=pi/2.0
tilt_max=pi/6.0
tilt_increment=4.0*pan_increment*(tilt_max/pan_max)
pan_dir=1.0
tilt_dir=1.0
wait_cnt=0
loop_rate=10
wait_max=2*loop_rate
full_rotation_cnt=0
if __name__=='__main__':
  try:
    rospy.init_node('pantilt',anonymous=True)
    pan=rospy.Publisher('pan_target',Float32,queue_size=100)
    tilt=rospy.Publisher('tilt_target',Float32,queue_size=100)
    rate=rospy.Rate(loop_rate)
    while not rospy.is_shutdown():
#        print("tilt overflow, loop count: " + str(loop_cnt))
      if(full_rotation_cnt%2==0):
        if(abs(pan_angle)>=pan_max):
          pan_dir=-pan_dir
        if(abs(tilt_angle)>=tilt_max):
          tilt_dir=-tilt_dir
        if(abs(pan_angle)<=0.5*pi/180.0):
          full_rotation_cnt+=1
          print("pan overflow, rotation count: " + str(full_rotation_cnt))

        pan_angle+=pan_dir*pan_increment
        tilt_angle+=tilt_dir*tilt_increment
        print("Pan angle: " + str(pan_angle*180.0/pi) + ", tilt angle: " + str(tilt_angle*180.0/pi))
      else:
        wait_cnt+=1
        if(wait_cnt==wait_max):
          wait_cnt=0
          full_rotation_cnt+=1
      pan.publish(pan_angle)
      tilt.publish(tilt_angle+tilt_offset)

      rate.sleep()

  except rospy.ROSInterruptException:
    pass


