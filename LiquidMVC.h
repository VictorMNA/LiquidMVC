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
	#include <LiquidMenu.h>

    class MenuOption{
    	
    };

	class LiquidMVC : public LiquidSystem  {
		public:


		#ifdef ENCODERMENU_H
			EncoderMenu *_controller;

			#ifdef LiquidCrystal_I2C_h
				LiquidMVC( LiquidCrystal_I2C *lcd, EncoderMenu *controller ){
					_lcd = lcd;
					_controller = controller;
				};
			#endif

			#ifdef LiquidCrystal_h
				LiquidMVC( LiquidCrystal *lcd, EncoderMenu *controller ){
					_lcd = lcd;
					_controller = controller;
				};
			#endif

			LiquidMVC( EncoderMenu *controller ){
				_controller = controller;
			};

		#endif

		#ifdef KEYPADMENU_H
			KeypadMenu _controller;

			#ifdef LiquidCrystal_I2C_h
				LiquidMVC( LiquidCrystal_I2C *lcd, KeypadMenu *controller ){
					_lcd = lcd;
					_controller = controller;
				};
			#endif

			#ifdef LiquidCrystal_h
				LiquidMVC( LiquidCrystal *lcd, KeypadMenu *controller ){
					_lcd = lcd;
					_controller = controller;
				};
			#endif

			LiquidMVC( KeypadMenu *controller ){
				_controller = controller;
			};

		#endif

		#ifdef LiquidCrystal_I2C_h
			LiquidCrystal_I2C *_lcd;

			LiquidMVC( LiquidCrystal_I2C *lcd){
				_lcd = lcd;
			};

		#endif

		#ifdef LiquidCrystal_h
			LiquidCrystal *_lcd;

			LiquidMVC( LiquidCrystal lcd ){
				_lcd = lcd;
			};

		#endif

		void init(){
			_lcd->init(); 
			_lcd->backlight();

		};

		void listmenu(int numargs, ...) {
			va_list ap;

			va_start(ap, numargs);
			while (numargs--){
				int total;
				total += va_arg(ap, int);
			}
			va_end(ap);
		}
  };
#endif