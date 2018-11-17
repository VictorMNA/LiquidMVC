// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "MenuOption.h"
#include "MenuRendererLcdI2c.h"

MenuRendererLcdI2c::MenuRendererLcdI2c(LiquidCrystal_I2C &lcd_object, int cols, int rows):
lcd(lcd_object),
_cols(cols),
_rows(rows)
{
}

String MenuRendererLcdI2c::GenerateSelectableElementString(MenuOption* element, bool selected, bool editing)
{
  String Text;

  // TODO: make string adaptable to cols of display

  if(selected && !editing)
  {
    Text += ">";
  }

  Text += element->getName();

  if(element->getType() == MenuOption::Type::INT_VALUE)
  {
    Text += ": ";

    if(editing)
    {
      Text += ">";
    }

    Text += String(static_cast<MenuOptionIntValue*>(element)->getValue());

    if(editing)
    {
      Text += "<";
    }
  }

  return Text;
}


void MenuRendererLcdI2c::Render(const Vector<MenuOption*>& array, const int& selected, const bool& editing)
{
  lcd.clear();

  if(_rows > 2)
  {
    lcd.setCursor(0, 0);
    if(selected == 0)
    {
      lcd.print("Back");
    }
    else if(selected > 0)
    {
      lcd.print(GenerateSelectableElementString(array[selected - 1], false, false));
    }
  }

  lcd.setCursor(0, (_rows <= 2)?0:1);
  if(selected == -1)
  {
    lcd.print(">Back");
  }
  else
  {
    lcd.print(GenerateSelectableElementString(array[selected], true, editing));
  }

  int next = 1;
  for(int row = (_rows <= 2)?1:2; row < _rows; row++, next++)
  {
    lcd.setCursor(0, row);
    if((selected + next) < array.size())
    {
      lcd.print(GenerateSelectableElementString(array[selected + next], false, false));
    }
  }
}

