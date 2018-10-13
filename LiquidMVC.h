/*
  Design and created by Blascarr
  LiquidMVC
  Author    : Blascarr
  Description: LiquidMVC.h
  version : 1.0
 
    Blascarr invests time and resources providing this open source code like some other libraries, please
    respect the job and support open-source software.
    
    Written by Adrian for Zaragoza Maker Space
*/

#ifndef LIQUIDMVC_H
#define LIQUIDMVC_H 

#include "MenuOption.h"
#include "MenuController.h"
#include "MenuRenderer.h"

    //#include <stdarg.h>
	#include <LiquidMenu.h>
    typedef void (*CallbackFunction)(void);
	class MenuOption{
    	public:
    		String _txt;

    		enum class MenuType
			{
				MENU_NONE,
				MENU_INT_VALUE,
				MENU_CALLBACK,
				MENU_LINK
			};

			virtual int optionMode(){  }
    		MenuOption;

    		MenuOption(String name, MenuType type = MenuType::MENU_NONE):
				_name(name),
				_type(type){

    		}

    		MenuType getType(void){
				return _type;
			}


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
		private:
			String  _name;
			MenuType _type;
    };

	class option_evt : public MenuOption {
		public:
			option_evt(String name, CallbackFunction function) : MenuOption(name, MenuType::MENU_CALLBACK){
				_callback = function;
			}
			void (*_f)(void);
			int optionMode(){ return 1; }
			void ExecuteCallback(void)
			{
				if(_callback != NULL){
					_callback();
				}
			}
			private:
    			CallbackFunction _callback;
	};

	class option_link : public MenuOption {
		public:
			option_link(String name) : MenuOption(name, MenuType::MENU_LINK){
			
			}  
			int optionMode(){ return 2; }

	};

    class option_value : public MenuOption {
		public:

			option_value(String name, int* value) : MenuOption(name, MenuType::MENU_INT_VALUE){
				_value = value;
			}
			int optionMode(){ return 3; }
			int getValue(void){
				return *_value;
			}

		private:
			int* _value;
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
			
			void add_option( MenuOption& _option){
				
				//Serial.println( _option.optionMode() );

				if( _option.getType() == MenuOption::MenuType::MENU_INT_VALUE){
					//Serial.println( "OPTION__VALUE" );
				}

				if( _option.getType() == MenuOption::MenuType::MENU_CALLBACK){
					//Serial.println( "OPTION__LINK" );
				}

				if( _option.getType() == MenuOption::MenuType::MENU_LINK){
					//Serial.println( "OPTION_LINK" );
				}

			}
		
  };
#endif