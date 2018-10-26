// TODO: add header

#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "LiquidMVC_config.h"

class MenuController
{
  public:

    enum class Event
    {
      NONE,
      SELECT,
      PREV,
      NEXT
    };

    virtual void Init(void);
    virtual MenuController::Event Read(void);
  
};

#endif

