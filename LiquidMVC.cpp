// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


#include "LiquidMVC.h"


LiquidMVC::LiquidMVC(MenuRenderer& renderer, MenuController& controller):
_renderer(renderer),
_controller(controller),
_menuSystem(NULL),
_sizeOfMenu(0),
_optionSelected(0)
{
};

void LiquidMVC::Init()
{
  _renderer.Init();
  _controller.Init();
};

void LiquidMVC::setMenuArray(MenuOption* array[], int size)
{
  _menuSystem = array;
  _sizeOfMenu = size;
}


void LiquidMVC::ListMenu()
{
  Serial.println("- Start menu list");

  for(int Index = 0; Index < _sizeOfMenu; Index++)
  {
    Serial.print(String(Index + 1) + ": " + _menuSystem[Index]->getTypeName() + " : " + _menuSystem[Index]->getName());

    if(_menuSystem[Index]->getType() == MenuOption::Type::INT_VALUE)
    {
      Serial.println(" : " + String((static_cast<MenuOptionIntValue*>(_menuSystem[Index]))->getValue()));
      (static_cast<MenuOptionIntValue*>(_menuSystem[Index]))->NextValue();
    }
    else
    {
      Serial.println();
    }
  }

  Serial.println("- End menu list");
}

