// TODO: add header

#ifndef MENURENDERERSERIAL_H
#define MENURENDERERSERIAL_H

#include "MenuRenderer.h"

class MenuRendererSerial: public MenuRenderer
{
  public:
    void Init(void) override;
    void Render(Vector<MenuOption*>& array, const int& selected, const bool& editing) override;

  private:
    void PrintSelectableElement(String text, bool selected);
};

#endif
