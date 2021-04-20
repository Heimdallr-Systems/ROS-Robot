#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Joy
import numpy as np
x=[]
y=[]
z=[]
def callback(data):
  global timing
  global x
  global y
  global z
  msgtime=data.header.stamp
  comptime=rospy.Time.now()
  if(msgtime>comptime):
    return
  timing.append((comptime-msgtime).to_sec())
#  print(timing[-1])

timing=[]

if __name__=='__main__':

  rospy.init_node("timing",anonymous=True)
  rospy.Subscriber("/joy",Joy,callback)
  print("Running")
  while not rospy.is_shutdown():
    #print("Maths")
    if(len(timing)>0):
      std=np.std(timing)
      maxim=max(timing)
      minim=min(timing)
      avg=np.mean(timing)
      print("Length: " + str(len(timing)) + ", Max: " + str(maxim) + ", Min: " +str(minim) + ", Average: " + str(avg) + ", stdDev: " + str(std))
    if(len(timing)>=30*8):
      file=open("output.txt","w+")
      dat=str(x)+"\n"+str(y)+"\n"+str(z)
      file.write(dat)
      file.close()
      break
    #rospy.spin()
