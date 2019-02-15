/*
 * Created on February 2, 2019 by Wesley Stirk
 * 
 * This class has the basic members and functions needed to control the 30A BLDC ESC from Hobbypower
 * It relies heavily on the Servo library for much of its functionality. 
 * 
 * Last Updated February 2, 2019 by Wesley Stirk
 */

#ifndef BLDC_ESC_30A
#define BLDC_ESC_30A

#include "Arduino.h"
#include <stdint.h>
#include <Servo.h>

typedef uint8_t speed_t; //used for recording the speed

#define ESC_30A_MAX_SPEED 100 
#define ESC_30A_MIN_SPEED 0

class ESC_30A
{
  public:
    //constructor of class
    //initializes the controller with the control
    ESC_30A(uint8_t controlPin);

    /*
     * Controls the speed of the motor. The function that will be mainly used. 
     * speed needs to be a value between 0 and 100 representing the percent of maximum
     */
    void throttle(speed_t mSpeed);

    void init();

    /*
     * returns the current speed of the motor. 
     */
    speed_t get_speed();

    /*
     * Sets the motor to full speed
     */
    void full_speed();

    /*
     * Turns the motor all the way off.  
     */
    void full_stop();

  private:
    speed_t currentSpeed; //keeps track of the current speed of the motor
    uint8_t pin;
    Servo bldc; //the Servo library that will do a lot of the controls. 
  
};


#endif
