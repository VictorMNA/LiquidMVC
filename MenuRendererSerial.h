// TODO: add header

#ifndef MENURENDERERSERIAL_H
#define MENURENDERERSERIAL_H

#include "MenuRenderer.h"

class MenuRendererSerial: public MenuRenderer
{
  public:
  	MenuRendererSerial(Stream& stream);
    void Init(void) override;
    void Render(const Vector<MenuOption*>& array, const int& selected, const bool& editing) override;

  private:
  	Stream& _serialStream;
    void PrintSelectableElement(String text, bool selected);
};

#endif
