// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include "MenuOption.h"

#include "Tests.h"


//=============================================================
// tests for MenuOption

int EditableValue = 345;

void Pepe(void)
{
  Serial.println("Pepe called!!!");
}

MenuOptionIntValue option1("Editable value", &EditableValue);
MenuOptionAction   option2("Test button", Pepe);
MenuOptionSubmenu  option3("Next menú");

void TestMenuOption()
{
  MenuOption *Puntero[3];
  int index;

  Puntero[0] = &option1;
  Puntero[1] = &option2;
  Puntero[2] = &option3;
  
  Serial.println(">>> MenuOption test start");

  for(int times = 0; times < 3; times++)
  {
    Serial.println("----------");
    for(index = 0; index < 3; index++)
    {
      Serial.println("-----");
      
      Serial.print(Puntero[index]->getTypeName() + " : " + Puntero[index]->getName());
      
      if(Puntero[index]->getType() == MenuOption::MenuType::MENU_INT_VALUE)
      {
        Serial.println(" : " + String((static_cast<MenuOptionIntValue*>(Puntero[index]))->getValue()));
        (static_cast<MenuOptionIntValue*>(Puntero[index]))->NextValue();
        (static_cast<MenuOptionIntValue*>(Puntero[index]))->NextValue();
        (static_cast<MenuOptionIntValue*>(Puntero[index]))->PrevValue();
      }
          
      else
      {
        Serial.println();
      }
  
      if(Puntero[index]->getType() == MenuOption::MenuType::MENU_ACTION)
      {
        (static_cast<MenuOptionAction*>(Puntero[index]))->ExecuteCallback();
      }    
    }
  }

  Serial.println("MenuOption test end <<<");  
  
}


