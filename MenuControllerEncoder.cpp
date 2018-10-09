// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif



#include "MenuControllerEncoder.h"




void MenuControllerEncoder::Init()
{
  Serial.println("MenuControllerEncoder: Init called");
}


void MenuControllerEncoder::Read()
{
  Serial.println("MenuControllerEncoder: Read called");
}

