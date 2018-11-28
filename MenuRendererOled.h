// TODO: add header

#ifndef MENURENDEREROLED_H
#define MENURENDEREROLED_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "MenuRenderer.h"

class MenuRendererOled: public MenuRenderer
{
  public:
    MenuRendererOled(Adafruit_SSD1306 &oled_object, int x_pixels, int y_pixels, int font_height);
    void Init(void) override {};
    void Render(const Vector<MenuOption*>& array, const int& selected, const bool& editing) override;

  private:
    Adafruit_SSD1306 &_oled;
    int _xMax;
    int _yMax;
    int _fontHeight;

    String GenerateSelectableElementString(MenuOption* element, bool selected, bool editing);
};

#endif