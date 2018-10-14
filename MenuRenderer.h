// TODO: add header

#ifndef MENURENDERER_H
#define MENURENDERER_H

class MenuRenderer
{
  public:
    virtual void Init(void);
    virtual void Render(MenuOption *array[], const int& size, const int& selected, const bool& editing);
};

#endif
