/*
 * Created on February 2, 2019 by Wesley Stirk
 * 
 * This file has the implementation of the basic members and functions needed to control the 30A BLDC ESC from Hobbypower
 * It relies heavily on the Servo library for much of its functionality. 
 * s
 * Last Updated February 2, 2019 by Wesley Stirk
 */

#include "ESC_30A.h"

ESC_30A::ESC_30A(uint8_t pin)
{
  //bldc.attach(pin); //attach the correct pin to the 'servo' 
  //full_stop();
  //bldc.write(40);
  this->pin = pin;
}

void ESC_30A::init()
{

  bldc.attach(pin);
  full_stop();
}

void ESC_30A::throttle(speed_t mSpeed)
{
  if(mSpeed <= ESC_30A_MAX_SPEED || mSpeed >= ESC_30A_MIN_SPEED) //double check that the given speed in the appropriate ranged
  {
    uint8_t rate = mSpeed;//map(mSpeed, ESC_30A_MIN_SPEED, ESC_30A_MAX_SPEED, 0, 180); //servos go from 0 to 180 so it needs to be mapped to that range.
    Serial.println(rate);
    bldc.write(rate); //set the appropriate speed
    currentSpeed = mSpeed; //remember what speed we are at. 
  }
}

speed_t ESC_30A::get_speed()
{
  return currentSpeed;
}

void ESC_30A::full_speed()
{
  throttle(ESC_30A_MAX_SPEED);
}

void ESC_30A::full_stop()
{
  throttle(ESC_30A_MIN_SPEED);
}
