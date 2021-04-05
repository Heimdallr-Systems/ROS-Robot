from __future__ import division
import time
import math
# Import the PCA9685 module.
import Adafruit_PCA9685


# Uncomment to enable debug output.
#import logging
#logging.basicConfig(level=logging.DEBUG)

# Helper function to make setting a servo pulse width simpler.
def set_servo_pulse(channel, pulse,pwm):
    pulse_length = 1000000    # 1,000,000 us per second
    pulse_length //= 60       # 60 Hz
    print('{0}us per period'.format(pulse_length))
    pulse_length //= 4096     # 12 bits of resolution
    print('{0}us per bit'.format(pulse_length))
    pulse *= 1000
    pulse //= pulse_length
    pwm.set_pwm(channel, 0, pulse)

def init_pca9685():
    # Initialise the PCA9685 using the default address (0x40).
    pwm = Adafruit_PCA9685.PCA9685(address=0x40, busnum=1)

    # Set frequency to 60hz, good for servos.
    pwm.set_pwm_freq(60)
    return pwm
def rad2pulse(rad):
    # Convert radians to servo pulses
    pstart = 150 # us
    pend = 600 # us
    pmiddle = (pend-pstart)/2+pstart # us
    radrange=270*math.pi/180
    return int((pend-pstart)/radrange*rad+pmiddle)
def drive_servos(pwm,servo_pos,i):
    # Servo pos is given in radians
    #for i in range(0,min(len(servo_pos),15)):
    pwm.set_pwm(i,0,rad2pulse(servo_pos))
    feedback = "driving port " + str(i) + " to " + str(rad2pulse(servo_pos))
    return [pwm,feedback]
'''pwm=init_pca9685()
print('Moving servo on channel 0, press Ctrl-C to quit...')
while True:
    print("forward")
    # Move servo on channel O between extremes.
    pwm=drive_servos(pwm,[math.pi/2,-math.pi/2,0])
    #pwm=drive_servos(pwm,[150,150,150])
    time.sleep(1)
    print("back")
    pwm=drive_servos(pwm,[-math.pi/4,-math.pi/8,math.pi/3])
    #pwm=drive_servos(pwm,[600,600,600])
    time.sleep(1)
'''
