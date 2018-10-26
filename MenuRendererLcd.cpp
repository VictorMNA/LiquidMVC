// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include "MenuOption.h"
#include "MenuRendererLcd.h"




void MenuRendererLcd::Init()
{
  Serial.println("MenuRendererLcd: Init called");
}


void MenuRendererLcd::Render(const Vector<MenuOption*>& array, const int& selected, const bool& editing)
{
  Serial.println("MenuRendererLcd: Render called");
}    
