// TODO: add header

#ifndef MENURENDERERLCD_H
#define MENURENDERERLCD_H

#include <LiquidCrystal.h>

#include "MenuRenderer.h"

class MenuRendererLcd: public MenuRenderer
{
  public:
    MenuRendererLcd();
    void Init(void) override;
    void Render(const Vector<MenuOption*>& array, const int& selected, const bool& editing) override;

  private:
    LiquidCrystal lcd;

    String GenerateSelectableElementString(MenuOption* element, bool selected, bool editing);
};

#endif
