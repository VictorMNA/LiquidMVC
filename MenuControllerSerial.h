// TODO: add header

#ifndef MENUCONTROLLERSERIAL_H
#define MENUCONTROLLERSERIAL_H

#include "MenuController.h"

class MenuControllerSerial: public MenuController
{
  public:
    MenuControllerSerial(Stream& Stream);

    void Init(void) override;
    MenuController::Event Read(void) override;

  private:
    enum class EscSequence
    {
      NONE,
      ESC_RECEIVED,
      BRACKET_RECEIVED
    };  

  	Stream& _serialStream;
  	EscSequence _escSequence;	
};

#endif