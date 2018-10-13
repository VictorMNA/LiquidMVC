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

void LiquidMVC::ShowMenu()
{
  Serial.println("\fMenu:");
  if(_optionSelected == -1)
  {
    Serial.println("><: Back");
  }
  else
  {
    Serial.println(": Back");
  }

  for(int Index = 0; Index < _sizeOfMenu; Index++)
  {
    if(Index == _optionSelected)
    {
      Serial.print(">"+ String(Index + 1) + "<");
    }
    else
    {
      Serial.print(String(Index + 1));
    }
    Serial.print(": "+ _menuSystem[Index]->getName());

    if(_menuSystem[Index]->getType() == MenuOption::Type::INT_VALUE)
    {
      Serial.print(" : ");

      if((Index == _optionSelected) && _editMode)
      {
        Serial.print(">");
      }
      Serial.print(String((static_cast<MenuOptionIntValue*>(_menuSystem[Index]))->getValue()));
      if((Index == _optionSelected) && _editMode)
      {
        Serial.print("<");
      }
      Serial.println();
    }
    else
    {
      Serial.println();
    }
  }
}


void LiquidMVC::ExecMenu()
{
  bool MenuRunning = true;

  _editMode = false;
  _optionSelected = 0;
  _renderer.Render();
  ShowMenu();

  while(MenuRunning)
  {
    switch(_controller.Read())
    {
      case MenuController::Event::SELECT:
        Serial.println("Controller returns Select");
        if(_optionSelected == -1)
        {
          MenuRunning = false;
        }
        else if(_menuSystem[_optionSelected]->getType() == MenuOption::Type::ACTION)
        {
          (static_cast<MenuOptionAction*>(_menuSystem[_optionSelected]))->ExecuteCallback();
        }
        else if(_menuSystem[_optionSelected]->getType() == MenuOption::Type::INT_VALUE)
        {
          _editMode = !_editMode;
        }
        _renderer.Render();
        ShowMenu();
        break;

      case MenuController::Event::PREV:
        if(_editMode)
        {
          if(_menuSystem[_optionSelected]->getType() == MenuOption::Type::INT_VALUE)
          {
            (static_cast<MenuOptionIntValue*>(_menuSystem[_optionSelected]))->PrevValue();
          }
        }
        else
        {
          if(_optionSelected >= 0)
          {
            _optionSelected--;
          }
        }
        _renderer.Render();
        ShowMenu();
        break;

      case MenuController::Event::NEXT:
        if(_editMode)
        {
          (static_cast<MenuOptionIntValue*>(_menuSystem[_optionSelected]))->NextValue();
        }
        else
        {
          if(_optionSelected < (_sizeOfMenu - 1))
          {
            _optionSelected++;
          }
        }
        _renderer.Render();
        ShowMenu();
        break;
    }
  }
}

