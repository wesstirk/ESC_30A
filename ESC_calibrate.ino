/*
 * Created February 15, 2019 by Wesley Stirk
 * 
 * This sketch takes a ESC_30A and calibrates for further use. 
 * Should be used once per controller. 
 * 
 * Last updated February 15, 2019 by Wesley Stirk
 */

#include "ESC_30A.h"

#define BAUDRATE 9600
#define CONTROL_PIN 9

//#define USE_CALIBRATE
#ifdef USE_CALIBRATE

void setup()
{
  Serial.begin(BAUDRATE);
  Serial.println("Starting the ESC_30A Calibration!");

  ESC_30A controller(CONTROL_PIN);
  controller.init();
  controller.calibrate();
}

void loop()
{
  
}


#endif
