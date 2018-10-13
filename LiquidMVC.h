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

#include "MenuOption.h"
#include "MenuController.h"
#include "MenuRenderer.h"

class LiquidMVC  {
	public:
    LiquidMVC(MenuRenderer& renderer, MenuController& controller);
    void Init(void);

    void setMenuArray(MenuOption* array[], int size);

    void ListMenu(void);

    void ExecMenu(void);

  private:
    MenuOption** _menuSystem;
    int _sizeOfMenu;
    int _optionSelected;
    bool _editMode;
    MenuRenderer& _renderer;
    MenuController& _controller;

    void ShowMenu(void);
};
  
#endif

