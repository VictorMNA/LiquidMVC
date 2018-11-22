// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include "MenuOption.h"
#include "MenuRendererSerial.h"


MenuRendererSerial::MenuRendererSerial(Stream& stream):
_serialStream(stream)
{

}

void MenuRendererSerial::Init()
{

}

void MenuRendererSerial::PrintSelectableElement(String text, bool selected)
{
    if(selected)
    {
      _serialStream.print(">");
    }

    _serialStream.print(text);

    if(selected)
    {
      _serialStream.print("<");
    } 
}


void MenuRendererSerial::Render(const Vector<MenuOption*>& array, const int& selected, const bool& editing)
{
  _serialStream.print("\033c"); // clear console
  _serialStream.println("Menu:");

  PrintSelectableElement("Back", (selected == -1));
  _serialStream.println();

  for(int Index = 0; Index < array.size(); Index++)
  {
    PrintSelectableElement(array[Index]->getName(), ((Index == selected) && !editing));

    if(array[Index]->getType() == MenuOption::Type::INT_VALUE)
    {
      _serialStream.print(": ");
      PrintSelectableElement(String((static_cast<MenuOptionIntValue*>(array[Index]))->getValue()), ((Index == selected) && editing));
    }
    _serialStream.println();
  }
}

