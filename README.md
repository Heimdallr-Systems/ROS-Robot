# ROS-Robot

This repository contains the ROS1 workspace for the Heimdallr robot that we built as our senior capstone.


## ROS Nodes

All ROS nodes are found under [/src](/src)

### pose_measure

Does something regarding the robot pose. 
TODO: Get Trevor to add details

### robot_goal_gen

Used to get and generate the robot goal
TODO: Get Trevor to add more details

### robotkinematics

Implementation of the robot's kinematics algorithm. Most code was made using MATLAB Coder. The MATLAB code 
it is generated from can be found in [Heimdallr-Systems/kinematics-MATLAB](https://github.com/Heimdallr-Systems/kinematics-MATLAB/). 

### ros-imu-bno055

Reads data from the BNO055 9DOF IMU. 

_Note: This is implemented as a git submodule, and will require submodule initialization to use_

### servo_control

Main servo control code, including determining positions to set to, and reading from ADC.

**IMPORTANT** This module requires extra steps to set up. See the [node's README](/src/servo_control/README.md) for more details

### servo_driver

Interface to the the PCA9685 PWM IC that is used to set the servo motors to the correct position. 

