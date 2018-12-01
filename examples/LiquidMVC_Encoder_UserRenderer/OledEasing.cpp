// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Easing.h>

#include <MenuOption.h>
#include "OledEasing.h"

OledEasing::OledEasing(Adafruit_SSD1306 &oled_object, int x_pixels, int y_pixels, int font_height):
_oled(oled_object),
_xMax(x_pixels),
_yMax(y_pixels),
_fontHeight(font_height)
{
}

String OledEasing::GenerateSelectableElementString(MenuOption* element, bool selected, bool editing)
{
  String Text;

  // TODO: make string adaptable to cols of display

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


void OledEasing::Render(const Vector<MenuOption*>& array, const int& selected, const bool& editing)
{
  int Rows;

  Rows = _yMax / (_fontHeight + 1);

  _oled.clearDisplay();
  _oled.setTextColor(WHITE);

  if(Rows > 2)
  {
    _oled.setCursor(1, _fontHeight);
    if(selected == 0)
    {
      _oled.print("Back");
    }
    else if(selected > 0)
    {
      _oled.print(GenerateSelectableElementString(array[selected - 1], false, false));
    }
  }

  int Next = 1;
  for(int Row = 3; Row <= Rows; Row++, Next++)
  {
    _oled.setCursor(1, Row * (_fontHeight + 1) - 1);
    if((selected + Next) < array.size())
    {
      _oled.print(GenerateSelectableElementString(array[selected + Next], false, false));
    }
  }

  if(editing)
  {
      _oled.fillRect(0, _fontHeight + 2, _xMax, _fontHeight + 2, WHITE);
      _oled.setTextColor(BLACK);
      _oled.setCursor(1, 1 + _fontHeight * 2);
      if(selected == -1)
      {
        _oled.print("Back");
      }
      else
      {
        _oled.print(GenerateSelectableElementString(array[selected], true, true));
      }   

      _oled.display();
  }
  else
  {
    _oled.display();

    String Text = GenerateSelectableElementString(array[selected], true, false);
    const int total = 8;
    int x;
    for(int i = 0; i <= total; i++)
    {
      x = Easing::easeOutBounce(i, 128, -127, total);

      _oled.fillRect(0, _fontHeight + 2, _xMax, _fontHeight + 2, WHITE);
      _oled.setTextColor(BLACK);
      _oled.setCursor(x, 1 + _fontHeight * 2);
      if(selected == -1)
      {
        _oled.print("Back");
      }
      else
      {
        _oled.print(Text);
      }   
      _oled.display();
      delay(20);
    }
  }
}

