// TODO: add header

#ifndef MENUCONTROLLERENCODER_H
#define MENUCONTROLLERENCODER_H

#include "MenuController.h"

class MenuControllerEncoder: public MenuController
{
  public:
    void Init(void) override;
    void Read(void) override;  
};

#endif

