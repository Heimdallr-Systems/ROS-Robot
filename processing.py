import math
import numpy as np
import matplotlib.pyplot as plt

stddevx=[]
stddevy=[]
stddevz=[]
for i in range(0,5):
  errorx=[]
  errory=[]
  errorz=[]
  cnt =0
  sampnum=[]
  filename="test"+str(i+1)+".txt"
  file=open(filename,'r')
  data=file.read().splitlines()
  file.close()
  for line in data:
    line = line[1:]
    line=line[:-1]
    line=line.split(" ")
    line=list(filter(None,line))
    aa=[0,0,0]
    print(line)
    aa[0]=180.0/math.pi*float(line[0].strip())
    aa[1]=180.0/math.pi*float(line[1].strip())
    aa[2]=180.0/math.pi*float(line[2].strip())
    if(aa[0]>50):
      aa[0]=aa[0]-180.0
    else:
      aa[0]=aa[0]+180.0
    errorx.append(0.0-aa[0])
    errory.append(0.0-aa[1])
    errorz.append(0.0-aa[2])
    cnt +=1
    sampnum.append(cnt)
  stddevx.append(np.std(errorx))
  stddevy.append(np.std(errory))
  stddevz.append(np.std(errorz))

  print("Noise in the y standard deviation: " + str(np.std(errory)))
  for a in range(0,20):
    del errorx[0]
    del errory[0]
    del errorz[0]
    del sampnum[0]
  plt.subplot(3,1,1)
  plt.scatter(sampnum,errorx)
  plt.subplot(3,1,2)
  plt.scatter(sampnum,errory)
  plt.subplot(3,1,3)
  plt.scatter(sampnum,errorz)
  plt.show()
  print("Show")
print("X-axis average noise: " + str(np.mean(stddevx)))
print("Y-axis average noise: " + str(np.mean(stddevy)))
print("Z-axis average noise: " + str(np.mean(stddevz)))
