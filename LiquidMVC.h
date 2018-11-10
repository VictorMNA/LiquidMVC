/*
  Design and created by Blascarr
  EncoderMe
  Name    : Blascarr
  Description: EncoderMenu.h
  version : 1.0
 
    Blascarr invests time and resources providing this open source code like some other libraries, please
    respect the job and support open-source software.
    
    Written by Adrian for Blascarr
*/

#ifndef LIQUIDMVC_H
#define LIQUIDMVC_H 

#include <Vector.h>

#include "MenuOption.h"
#include "MenuController.h"
#include "MenuRenderer.h"



class LiquidMVC  {
	public:
    LiquidMVC(MenuRenderer& renderer, MenuController& controller);
    void Init(void);

    template <size_t MENU_MAX_SIZE>
    void setMenuArray(MenuOption *(&array)[MENU_MAX_SIZE], int size = 0)
    {
       _menuSystem.setStorage(array, size);
    }

    void ListMenu(void);
    void ExecMenu(void);

  private:
    Vector<MenuOption*> _menuSystem;
    bool _editMode;
    MenuRenderer& _renderer;
    MenuController& _controller;

    void NavigateMenu(const Vector<MenuOption*>& array);
};
  
#endif

