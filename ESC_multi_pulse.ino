/*
 * Created March 26, 2019 by Wesley Stirk
 * 
 * This file is to use for sending the motor to pulse for a designated amount of times. 
 * Last updated March 26, 2019 by Wesley Stirk
 */

#include "ESC_30A.h"


//#define ESC_MULTI_PULSE //comment out to use another sketch. 
#ifdef ESC_MULTI_PULSE

#define CONTROL_PIN 9 //where the arduino connects to the ESC. Must be a PWM pin. 
#define PULSE_TIME 1000 //given in ms. The amount of time the pulse is on. 
#define PULSE_WAIT 500 //given in ms. The amount of time between pulses. 
#define MOTOR_SPEED 100 //given in percentage. The speed that the motor will pulse to. 

#define NUM_PULSES 5 //the number of times that motor should pulse. 

#define SHORTEST_PULSE_HOBBY 300 //given in milliseconds
//the shortest possible pulse of increased PWM duty cycle. 
//found by experimentation using the ESC_pulse.ino code. 

#define SHORTEST_PULSE_HDD 350 //given in milliseconds. 




ESC_30A motor(CONTROL_PIN); //the ESC

void setup()
{
  motor.init(); //initialize the motor control
  motor.wait_startup(); //wait for everything to settle. 
  delay(500); //just for good measure. 
  for(uint8_t i = 0; i < NUM_PULSES; ++i)
  {
    motor.throttle(MOTOR_SPEED); //ramp up to the desired speed. 
    delay(PULSE_TIME); //wait for the needed amount of time. 
    motor.full_stop(); //and turn of the power. 
    delay(PULSE_WAIT);
  }
  

}

void loop()
{

}

#endif
