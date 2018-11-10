// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "MenuOption.h"
#include "MenuRendererLcd.h"

MenuRendererLcd::MenuRendererLcd():
lcd(LCD_PIN_RS, LCD_PIN_RW, LCD_PIN_EN, LCD_PIN_D4, LCD_PIN_D5, LCD_PIN_D6, LCD_PIN_D7)
{
}

void MenuRendererLcd::Init()
{
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.clear();
  analogWrite(LCD_BACKLIGHT_PIN, 200);
}

String MenuRendererLcd::GenerateSelectableElementString(MenuOption* element, bool selected, bool editing)
{
  String Text;

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


void MenuRendererLcd::Render(const Vector<MenuOption*>& array, const int& selected, const bool& editing)
{
  // TODO: make for variable display size
  lcd.clear();

  if(LCD_ROWS > 2)
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

  lcd.setCursor(0, (LCD_ROWS <= 2)?0:1);
  if(selected == -1)
  {
    lcd.print(">Back");
  }
  else
  {
    lcd.print(GenerateSelectableElementString(array[selected], true, editing));
  }

  int next = 1;
  for(int row = (LCD_ROWS <= 2)?1:2; row < LCD_ROWS; row++, next++)
  {
    lcd.setCursor(0, row);
    if((selected + next) < array.size())
    {
      lcd.print(GenerateSelectableElementString(array[selected + next], false, false));
    }
  }
}

