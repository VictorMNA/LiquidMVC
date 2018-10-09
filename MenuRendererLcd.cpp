// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif



#include "MenuRendererLcd.h"




void MenuRendererLcd::Init()
{
  Serial.println("MenuRendererLcd: Init called");
}


void MenuRendererLcd::Render()
{
  Serial.println("MenuRendererLcd: Render called");
}    
