// TODO: add header

#ifndef MENURENDERERLCD_H
#define MENURENDERERLCD_H

#include "MenuRenderer.h"

class MenuRendererLcd: public MenuRenderer
{
  public:
    void Init(void) override;
    void Render(void) override;  
};

#endif
