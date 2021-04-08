# ROS-Robot

This repository contains the ROS1 workspace for the Heimdallr robot that we built as our senior capstone.


## ROS Nodes

All ROS nodes are found under [/src](/src)

### pose_measure

Complementary filter for determining robot orientation and position. 

### robot_goal_gen

Generates the trajectory for the robot to follow. 

### robotkinematics

Implementation of the robot's kinematics algorithm. Most code was made using MATLAB Coder. The MATLAB code 
it is generated from can be found in [Heimdallr-Systems/kinematics-MATLAB](https://github.com/Heimdallr-Systems/kinematics-MATLAB/). 

### ros-imu-bno055

Reads data from the BNO055 9DOF IMU. 

_Note: This is implemented as a git submodule, and will require submodule initialization to use_

### servo_control

Main servo feedback control. 

**IMPORTANT** This module requires extra steps to set up. See the [node's README](/src/servo_control/README.md) for more details

### servo_driver

Interface to the the PCA9685 PWM IC that is used to set the servo motors to the correct position. 

