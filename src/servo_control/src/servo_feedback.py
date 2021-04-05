#!/usr/bin/env python
import rospy
from servo_control.msg import MotorVector
from geometry_msgs.msg import PoseStamped
import math
import matplotlib.pyplot as plt
import numpy as np

def servo_sim(x,x_prev,ydot_prev,yddot_prev,dt):
  fc=0.3
  al=1.0/(2.0*math.pi*dt*fc+1.0)
  DR=0.65
  wn=1.5385
  ydott=al*ydot_prev+al*(x-x_prev)
  yddott=al*yddot_prev+al*(ydott-ydot_prev)
  yt=(x*wn**2-yddott-ydott*2.0*DR*wn)/wn**2
  if(yt==float('nan')):
    yt=0
  return([yt,ydott,yddott])

t=[]
tstep=0.1;
tend=10
y=MotorVector()
ydot=[0,0,0,0,0,0,0,0,0,0,0,0,0,0]
yddot=[0,0,0,0,0,0,0,0,0,0,0,0,0,0]
x=[]
targets=MotorVector()
lastTargets=MotorVector()
goalPos=[0, 0, 0]
def target_callback(data):
  global goalPos
  goalPos=data
def servo_target_callback(data):
  global targets
  targets.data=data.data
def servo_feedback_pub():
  global y
  global yddot
  global ydot
  global targets
  global lastTargets
  cnt=0
  rospy.init_node('servo_feedback_sim',anonymous=True)
  pub=rospy.Publisher('kinematics_feedback',MotorVector,queue_size=10)
 # pubPos=rospy.Publisher('rtabmap/odom',PoseStamped,queue_size=10)
  rospy.Subscriber("kinematics_target",MotorVector,servo_target_callback,queue_size=10)
  rospy.Subscriber("rtabmap/goal",PoseStamped,target_callback,queue_size=10)
  dt=0.1
  rate=rospy.Rate(1/dt)
  while not rospy.is_shutdown():
    tmpydot=[]
    tmpyddot=[]
    tmpfdbk=[]
    tgts=targets.data
    lasttgts=lastTargets.data
    for i in range(0,13):
      print(i)
      if(cnt==0):
        resp=servo_sim(tgts[i],0.0,0.0,0.0,dt)
      else:
        resp=servo_sim(targets.data[i],lastTargets.data[i],ydot[i],yddot[i],dt)
#      if(i<3):
#        if(cnt==0):
#          respPos=servo_sim(
      tmpydot.append(resp[1])
      tmpyddot.append(resp[2])
      tmpfdbk.append(resp[0])
    lastTargets.data=targets.data
    feedbacki=MotorVector()
    feedbacki.data=tmpfdbk
    print(type(feedbacki))
    ydot=tmpydot
    yddot=tmpyddot
    cnt+=1
    rospy.loginfo("Sending feedback: " + str(tmpfdbk))
    pub.publish(feedbacki)
    rate.sleep()

    '''for i in range(0,int(tend/tstep)):
    t.append(i*tstep)
    if(i*tstep<4):
      x.append(3.0)
    else:
      x.append(5.0)
    if(i==0):
      resp=servo_sim(x[0],0.0,0.0,0.0,tstep)
    else:
      resp=servo_sim(x[i],x[i-1],ydot[i-1],yddot[i-1],tstep)
    y.append(resp[0])
    ydot.append(resp[1])
    yddot.append(resp[2])'''

if(__name__=='__main__'):
  try:
    tmp=[]
    for i in range(0,13):
      tmp.append(0)
#      lastTargets.data[i]=0
    targets.data=tmp
    lastTargets.data=tmp
    servo_feedback_pub()
  except rospy.ROSInterruptException:
    pass
