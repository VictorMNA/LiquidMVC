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

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

  //#include <stdarg.h>
//#include <LiquidMenu.h>

#include "MenuOption.h"
#include "MenuController.h"
#include "MenuRenderer.h"

class LiquidMVC  {
	public:
    LiquidMVC(MenuRenderer *renderer, MenuController *controller):
    _renderer(renderer),
    _controller(controller)
    {
    };

  	void Init(){
      _renderer->Init();
      _controller->Init();
  	};
	
	void add_option( MenuOption option){
		Serial.println( option.getTypeName() );
	};

  private:
    MenuOption _menusystem[];
    MenuRenderer *_renderer;
    MenuController *_controller;
    //LiquidSystem _sys;
};
  
#endif

