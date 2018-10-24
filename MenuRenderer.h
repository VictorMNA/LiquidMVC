// TODO: add header

#ifndef MENURENDERER_H
#define MENURENDERER_H

#include <Vector.h>

class MenuRenderer
{
  public:
    virtual void Init(void);
    virtual void Render(Vector<MenuOption*>& array, const int& selected, const bool& editing);
};

#endif
