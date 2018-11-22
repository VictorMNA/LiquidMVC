// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "MenuControllerSerial.h"


MenuControllerSerial::MenuControllerSerial(Stream& stream):
_serialStream(stream)
{

}

void MenuControllerSerial::Init()
{
  _escSequence = MenuControllerSerial::EscSequence::NONE;
}

MenuController::Event MenuControllerSerial::Read()
{
  int received;

  if(_serialStream.available())
  {
    received = _serialStream.read();

    switch(_escSequence)
    {
      case MenuControllerSerial::EscSequence::NONE:
        switch(received)
        {
          case '\r': //carry return
            return MenuController::Event::SELECT;
            break;

          case '\033': // ESC
            _escSequence = MenuControllerSerial::EscSequence::ESC_RECEIVED;
            break;

          default:
            Serial.print("normal received: ");
            Serial.println(received, DEC);
            break;
        }
        break;

      case MenuControllerSerial::EscSequence::ESC_RECEIVED:
        switch(received)
        {
          case '[':
            _escSequence = MenuControllerSerial::EscSequence::BRACKET_RECEIVED;
            break;

            default:
              Serial.print("ESC received: ");
              Serial.println(received, DEC);            
              _escSequence = MenuControllerSerial::EscSequence::NONE;
              break;
        }
        break;

      case MenuControllerSerial::EscSequence::BRACKET_RECEIVED:
        switch(received)
        {
          case 'A': // up arrow
            _escSequence = MenuControllerSerial::EscSequence::NONE;
            return MenuController::Event::PREV;
            break;

          case 'B': // down arrow
            _escSequence = MenuControllerSerial::EscSequence::NONE;
            return MenuController::Event::NEXT;
            break;

            default:
              Serial.print("BRACKET received: ");
              Serial.println(received, DEC);            
              _escSequence = MenuControllerSerial::EscSequence::NONE;
              break;
        }      
        break;
    }
  }

  return MenuController::Event::NONE;
}

