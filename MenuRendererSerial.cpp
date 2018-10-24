// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include "MenuOption.h"
#include "MenuRendererSerial.h"


void MenuRendererSerial::Init()
{
  Serial.end(); // the Serial can be previously configured
  Serial.begin(115200);
  Serial.println("MenuRendererSerial: Init called");
}

void MenuRendererSerial::PrintSelectableElement(String text, bool selected)
{
    if(selected)
    {
      Serial.print(">");
    }

    Serial.print(text);

    if(selected)
    {
      Serial.print("<");
    } 
}


void MenuRendererSerial::Render(Vector<MenuOption*>& array, const int& selected, const bool& editing)
{
  Serial.println("\fMenu:");

  PrintSelectableElement("Back", (selected == -1));
  Serial.println();

  for(int Index = 0; Index < array.size(); Index++)
  {
    PrintSelectableElement(array[Index]->getName(), ((Index == selected) && !editing));

    if(array[Index]->getType() == MenuOption::Type::INT_VALUE)
    {
      Serial.print(": ");
      PrintSelectableElement(String((static_cast<MenuOptionIntValue*>(array[Index]))->getValue()), ((Index == selected) && editing));
    }
    Serial.println();
  }
}

