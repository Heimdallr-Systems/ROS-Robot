# Servo_Control

This ROS node interacts with the ADC to read the position of all of the servos on the robot, as well as 
other control systems. 

As a bonus, it also reads the battery voltage.

It requires `libgpiod-dev` to be installed with apt. Documentation is installed with the package `libgpiod-doc`.

The pin used by the ADC for the EOC detection in Pin 15 on the header. The Linux GPIO SYSFS system calls it `gpio194`.
In the gpiod system, it is Line 194 of `gpiochip0`

By default, the GPIO devies (`/dev/gpiochip0` and `/dev/gpiochip1`) are owned by the user `root` and are in the group 
`root`. This requires any code that accesses the GPIO through this sustem to be run as root. If you want to be able to
access the GPIO without running a program as root, you will need to copy the file `99-gpio.rules` in this directory
to the folder  `/etc/udev/rules.d`. See the comments in that file for more details on how it works. 