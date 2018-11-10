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


void LiquidMVC::ListMenu()
{
  Serial.println("- Start menu list");

  for(int Index = 0; Index < _menuSystem.size(); Index++)
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


void LiquidMVC::ExecMenu()
{
  NavigateMenu(_menuSystem);
}

void LiquidMVC::NavigateMenu(const Vector<MenuOption*>& array)
{
  bool MenuRunning = true;
  int OptionSelected = 0;

  _editMode = false;

  _renderer.Render(array, OptionSelected, _editMode);

  while(MenuRunning)
  {
    switch(_controller.Read())
    {
      case MenuController::Event::SELECT:
        Serial.println("Controller returns Select");
        if(OptionSelected == -1)
        {
          MenuRunning = false;
        }
        else if(array[OptionSelected]->getType() == MenuOption::Type::ACTION)
        {
          (static_cast<MenuOptionAction*>(array[OptionSelected]))->ExecuteCallback();
        }
        else if(array[OptionSelected]->getType() == MenuOption::Type::INT_VALUE)
        {
          _editMode = !_editMode;
        }
        else if(array[OptionSelected]->getType() == MenuOption::Type::SUBMENU)
        {
          NavigateMenu((static_cast<MenuOptionSubmenu*>(array[OptionSelected]))->getMenu());
        }
        _renderer.Render(array, OptionSelected, _editMode);
        break;

      case MenuController::Event::PREV:
        if(_editMode)
        {
          if(array[OptionSelected]->getType() == MenuOption::Type::INT_VALUE)
          {
            (static_cast<MenuOptionIntValue*>(array[OptionSelected]))->PrevValue();
          }
        }
        else
        {
          if(OptionSelected >= 0)
          {
            OptionSelected--;
          }
        }
        _renderer.Render(array, OptionSelected, _editMode);
        break;

      case MenuController::Event::NEXT:
        if(_editMode)
        {
          (static_cast<MenuOptionIntValue*>(array[OptionSelected]))->NextValue();
        }
        else
        {
          if(OptionSelected < (((int)array.size()) - 1))
          {
            OptionSelected++;
          }
        }
        _renderer.Render(array, OptionSelected, _editMode);
        break;
    }
  }
}

