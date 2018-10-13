// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


#include "LiquidMVC.h"


LiquidMVC::LiquidMVC(MenuRenderer& renderer, MenuController& controller):
_renderer(renderer),
_controller(controller)
{
};

void LiquidMVC::Init()
{
  _renderer.Init();
  _controller.Init();
};

