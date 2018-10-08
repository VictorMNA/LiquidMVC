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
    	public:
    		String _txt;
    		virtual int optionMode(){  }
    		/*MenuOption(  ){

    		}*/

    		/*void add_option(option_evt _option){

    		}

    		void add_option(option_value _option){

    		}

    		void add_option(option_link _option){

    		}*/

	    	/*void listmenu(int numargs, ...) {
				va_list ap;

				va_start(ap, numargs);
				while (numargs--){
					int total;
					total += va_arg(ap, int);
				}
				va_end(ap);
			}*/
    };

	class option_evt : public MenuOption {
		public:
		
		void (*_f)(void);

		option_evt(String txt, void (*func)() = NULL){
			_txt = txt;
			_f = func;
		}

	};

	class option_link : public MenuOption {
		public:

		option_link(String txt ){
			_txt = txt;
		}
	};

    class option_value : public MenuOption {
		public:
			int *_value;

			option_value(String txt, int *value ){
				_txt = txt;
				_value = value;
			}
	};

	class LiquidMVC  {
		public:
			LiquidSystem _sys;
			MenuOption _menusystem[];

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
			KeypadMenu *_controller;

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
		
		void add_option( MenuOption _option){
			//Serial.println( typeof( _option ) );
			//Serial.println( typeid(_option).name() );
			/*option_value *a;
			option_link *b;
			option_evt *c;*/
			Serial.println( _option.optionMode() );

			if( _option.optionMode() == 0){

			}
			/*if( a = dynamic_cast< option_value* >( &_option )  ){

			}*/

    	}
		
  };
#endif