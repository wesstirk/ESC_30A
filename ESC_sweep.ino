/*
 * Created on February 27, 2019 by Wesley Stirk
 * 
 * This program is for running a basic demo of a motor spinning on a continuous loop. 
 * 
 * Last updated February 27, 2019 by Wesley Stirk
 */

//#define USE_SWEEP
#ifdef  USE_SWEEP

#include "ESC_30A.h"

#define CONTROL_PIN 9 //where the arduino connects to the ESC
#define DELAY_TIME 25 //given in ms

ESC_30A motor(CONTROL_PIN); //the ESC

void setup()
{
   motor.init(); //initialize the motor control
   motor.wait_startup(); //wait for everything to settle. 
}


void loop()
{
  for(int8_t i = ESC_30A_MIN_SPEED; i <= ESC_30A_MAX_SPEED; ++i) //throttle up. 
  {
    motor.throttle(i);
    delay(DELAY_TIME); //wait a little bit before moving on. 
  }

  for(int8_t i = ESC_30A_MAX_SPEED; i >= ESC_30A_MIN_SPEED ; ++i) //throttle down. 
  {
    motor.throttle(i);
    delay(DELAY_TIME);
  }
  
}

#endif
