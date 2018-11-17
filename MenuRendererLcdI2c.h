// TODO: add header

#ifndef MENURENDERERLCDI2C_H
#define MENURENDERERLCDI2C_H

#include <LiquidCrystal_I2C.h>

#include "MenuRenderer.h"

class MenuRendererLcdI2c: public MenuRenderer
{
  public:
    MenuRendererLcdI2c(LiquidCrystal_I2C &lcd_object, int cols, int rows);

    void Init(void) override {};
    void Render(const Vector<MenuOption*>& array, const int& selected, const bool& editing) override;

  private:
    LiquidCrystal_I2C &lcd;
    int _cols;
    int _rows;

    String GenerateSelectableElementString(MenuOption* element, bool selected, bool editing);
};

#endif
