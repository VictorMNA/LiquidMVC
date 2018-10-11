// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "MenuControllerEncoder.h"


// TODO: try to get working _lastEvent beeing part of the class
//
// As the callbacks of EncoderMenu need to be "void (*f)()"
// if we try to use a pointer to "MenuControllerEncoder::GenerateSelectEvent()"
// need to be casted to "void (*f)()" to compile.
// But doing this the method should lost the concept of class and the update of
// _lastEvent (as a part of the class) doesn't work.
// So, by now, _lastEvent and the callbacks aren't part of the class.

MenuController::Event _lastEvent;

void GenerateSelectEvent(void)
{
  Serial.println("Press");
  _lastEvent = MenuController::Event::SELECT;
}

void GeneratePrevEvent(void)
{
  Serial.println("Left");
  _lastEvent = MenuController::Event::PREV;
}

void GenerateNextEvent(void)
{
  Serial.println("Right");
  _lastEvent = MenuController::Event::NEXT;
}

void NullFunction(void)
{

}




MenuControllerEncoder::MenuControllerEncoder(uint8_t pinA, uint8_t pinB, uint8_t pinSW, bool clockwise, bool pullup):
_encoder(pinA, pinB, pinSW, clockwise, pullup)
//, _lastEvent(MenuController::Event::NONE)
{
  Serial.println("MenuControllerEncoder: constructor");
}

void MenuControllerEncoder::Init()
{
  _encoder.nolimits();
  _encoder.set_f_press(GenerateSelectEvent);
  _encoder.set_f_rotary(NullFunction, GeneratePrevEvent, GenerateNextEvent);

//  _encoder.set_f_press((void(*)(void))&MenuControllerEncoder::GenerateSelectEvent);
//  _encoder.set_f_rotary((void(*)(void))&MenuControllerEncoder::NullFunction, (void(*)(void))&MenuControllerEncoder::GeneratePrevEvent, (void(*)(void))&MenuControllerEncoder::GenerateNextEvent);

  _lastEvent = MenuController::Event::NONE;

  Serial.println("MenuControllerEncoder: Init called");
}

MenuController::Event MenuControllerEncoder::Read()
{
  _encoder.read();

  MenuController::Event EventToReturn = _lastEvent;
  _lastEvent = MenuController::Event::NONE;

  return EventToReturn;
}


//void MenuControllerEncoder::GenerateSelectEvent()
//{
//  Serial.println("Press");
//  _lastEvent = MenuController::Event::SELECT;
//}
//
//void MenuControllerEncoder::GeneratePrevEvent()
//{
//  Serial.println("Left");
//  _lastEvent = MenuController::Event::PREV;
//}
//
//void MenuControllerEncoder::GenerateNextEvent()
//{
//  Serial.println("Right");
//  _lastEvent = MenuController::Event::NEXT;
//}
//
//void MenuControllerEncoder::NullFunction()
//{
//
//}

