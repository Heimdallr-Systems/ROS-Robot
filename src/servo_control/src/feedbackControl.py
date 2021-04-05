#!/usr/env/bin python
import spi as spimod
import ros
from servo_control.msgs import MotorVector

def spiConnect():
  spi=spimod.SPI("/dev/spidev1.0")
  spi.mode=spimod.SPI.MODE_0
  spi.bits_per_word= 8
  spi.speed=50000
  return spi
