// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include "LiquidMVC.h"

#include "Tests.h"


//=============================================================
// tests for MenuOption

int EditableValue = 345;
int EditableValue2 = 8;

void Pepe(void)
{
  Serial.println("Pepe called!!!");
}

void Juan(void)
{
  Serial.println("Juan called!!!");
}

MenuOptionIntValue option1("Editable value", EditableValue);
MenuOptionAction   option2("Test button", Pepe);
//MenuOptionSubmenu  option3("Next menú");
MenuOptionIntValue option4("Editable with limits", EditableValue2, 7, 10);
#define SIZE_ARRAY 3

void TestMenuOption()
{
  MenuOption *Puntero[SIZE_ARRAY];
  int index;

  Puntero[0] = &option1;
  Puntero[1] = &option2;
  //Puntero[2] = &option3;
  Puntero[2] = &option4;
  
  Serial.println(">>> MenuOption test start");

  for(int times = 0; times < 5; times++)
  {
    Serial.println("----------");
    for(index = 0; index < SIZE_ARRAY; index++)
    {
      Serial.print(Puntero[index]->getTypeName() + " : " + Puntero[index]->getName());
      
      if(Puntero[index]->getType() == MenuOption::Type::INT_VALUE)
      {
        Serial.println(" : " + String((static_cast<MenuOptionIntValue*>(Puntero[index]))->getValue()));
        (static_cast<MenuOptionIntValue*>(Puntero[index]))->NextValue();
      }
          
      else
      {
        Serial.println();
      }
  
      if(Puntero[index]->getType() == MenuOption::Type::ACTION)
      {
        (static_cast<MenuOptionAction*>(Puntero[index]))->ExecuteCallback();
      }    
    }
  }

  Serial.println("------------------------------");

  for(int times = 0; times < 5; times++)
  {
    Serial.println("----------");
    for(index = 0; index < SIZE_ARRAY; index++)
    {
      if(Puntero[index]->getType() == MenuOption::Type::INT_VALUE)
      {
        Serial.println(Puntero[index]->getTypeName() + " : " + Puntero[index]->getName() + " : " + String((static_cast<MenuOptionIntValue*>(Puntero[index]))->getValue()));
        (static_cast<MenuOptionIntValue*>(Puntero[index]))->PrevValue();
      }
    }
  }

  Serial.println("MenuOption test end <<<");  
}

int Fingers = 10;
int Toes = 10;
MenuOptionIntValue SubElemento1("fingers", Fingers, 0, 10);
MenuOptionIntValue SubElemento2("toes", Toes, 0, 10);

MenuOption *SubMenu[] =
{
  &SubElemento1,
  &SubElemento2
};

int Potatoes = 16;

MenuOptionIntValue Elemento1("Potato chips", Potatoes);
MenuOptionSubmenu  Elemento2("I am a submenu", SubMenu, 2);
MenuOptionAction   Elemento3("Juan", Juan);
#define BACKLIGHT_PIN 5
int Backlight;
MenuOptionIntValue Elemento4("Backlight", Backlight, 0, 15);

void ChangeBacklight(void)
{
  analogWrite(BACKLIGHT_PIN, Backlight * 16);
}

MenuOption *ArrayMenu[] =
{
  &Elemento1,
  &Elemento2,
  &Elemento3,
  &Elemento4
};
const int SizeOfMenu = sizeof(ArrayMenu) /sizeof(ArrayMenu[0]);
  
void TestArrayOptions()
{  
  int index;
  
  Serial.println(">>> ArrayOptions test start");
  
  for(index = 0; index < SizeOfMenu; index++)
  {
    MenuOption &Element = *ArrayMenu[index];
    
    Serial.print(Element.getTypeName() + " : " + Element.getName());    
    if(Element.getType() == MenuOption::Type::INT_VALUE)
    {
      Serial.println(" : " + String((static_cast<MenuOptionIntValue&>(Element)).getValue()));
    }
        
    else
    {
      Serial.println();
    }

    if(Element.getType() == MenuOption::Type::ACTION)
    {
        (static_cast<MenuOptionAction&>(Element)).ExecuteCallback();
    }    
  }

  Serial.println("ArrayOptions test end <<<");
}

//=============================================================
// tests for MenuRenderer

#include "MenuRendererLcd.h"

MenuRendererLcd RendererLcd;

MenuRenderer *Renderer;

void TestMenuRendererLcd()
{
  Serial.println(">>> MenuRendererLcd test start");

  Renderer = &RendererLcd;
  Vector<MenuOption*> MenuElements(ArrayMenu, SizeOfMenu);

  Renderer->Init();
  Renderer->Render(MenuElements, 2, false);

  Serial.println("MenuRendererLcd test end <<<");
}

//=============================================================
// tests for MenuController

#include "MenuControllerEncoder.h"

MenuControllerEncoder ControllerEncoder(A0, A1, A2, false, true);

MenuController *Controller;

void TestMenuControllerEncoder()
{
  Serial.println(">>> MenuControllerEncoder test start");

  Controller = &ControllerEncoder;

  Controller->Init();

  Serial.println("Use encoder for a while...");
  for(long int index = 0; index < 200000; index++)
  {
    switch(Controller->Read())
    {
      case MenuController::Event::SELECT:
        Serial.println("Controller returns Select");
        break;

      case MenuController::Event::PREV:
        Serial.println("Controller returns Prev");
        break;

      case MenuController::Event::NEXT:
        Serial.println("Controller returns Next");
        break;

      case MenuController::Event::NONE:
        //Serial.println("Controller returns NONE");
        break;

      default:
        Serial.println("Controller returns ????");
        break;
    }
  }

  Serial.println("MenuControllerEncoder test end <<<");
}

//=============================================================
// tests for LiquidMVC

#include "MenuRendererSerial.h"

MenuRendererSerial RendererSerial;
//LiquidMVC MyMenu(RendererSerial, ControllerEncoder);
LiquidMVC MyMenu(RendererLcd, ControllerEncoder);

void TestLiquidMVCInit()
{
  Serial.println(">>> TestLiquidMVCInit test start");

  MyMenu.Init();
  MyMenu.setMenuArray(ArrayMenu, 4);
  MyMenu.ListMenu();

  Serial.println("TestLiquidMVCInit test end <<<");
}

void TestLiquidMVC()
{
  Serial.println(">>> TestLiquidMVC test start");

  Backlight = 15;
  ChangeBacklight();

  MyMenu.Init();
  Elemento4.setValueChangedCallback(ChangeBacklight);
  MyMenu.setMenuArray(ArrayMenu, 4);
  MyMenu.ExecMenu();

  Serial.println("TestLiquidMVC test end <<<");
}

//=============================================================
// tests for value changed callback
void TestValueChangedCallback()
{
  Serial.println(">>> TestValueChangedCallback test start");
  Serial.println("Look at the backlight!!!");

  Backlight = 0;

  ChangeBacklight();
  Elemento4.setValueChangedCallback(ChangeBacklight);

  for(int Times = 0; Times < 3; Times++)
  {
    for(int Index = 0; Index < 250; Index++)
    {
      Elemento4.NextValue();
      delay(10);
    }

    for(int Index = 250; Index > 0; Index--)
    {
      Elemento4.PrevValue();
      delay(10);
    }
  }

  Serial.println("TestValueChangedCallback test end <<<");
}

