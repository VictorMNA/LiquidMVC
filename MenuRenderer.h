// TODO: add header

#ifndef MENURENDERER_H
#define MENURENDERER_H

#include <Vector.h>

#include "LiquidMVC_config.h"

class MenuRenderer
{
  public:
    virtual void Init(void);
    virtual void Render(const Vector<MenuOption*>& array, const int& selected, const bool& editing);
};

#endif
