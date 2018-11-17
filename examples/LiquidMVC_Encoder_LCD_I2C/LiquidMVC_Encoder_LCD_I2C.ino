// TODO: add header

#include <LiquidMVC.h>

#include <MenuControllerEncoder.h>
#include <MenuRendererLcdI2c.h>


#define LCD_ROWS  2
#define LCD_COLS  16



int Fingers = 10;
int Toes = 10;

MenuOptionIntValue FingersMenu("Fingers", Fingers, 0, 10);
MenuOptionIntValue ToesMenu("Toes", Toes, 0, 10);

MenuOption *FingersAndToesArray[] =
{
  &FingersMenu,
  &ToesMenu
};
const int SizeOfFingersAndToesArray = sizeof(FingersAndToesArray) /sizeof(FingersAndToesArray[0]);
MenuOptionSubmenu FingersAndToesMenu("Fingers & toes", FingersAndToesArray, SizeOfFingersAndToesArray);


int Number;
MenuOptionIntValue NumberMenu("Number", Number);


MenuOption *MenuArray[] =
{
  &NumberMenu,
  &FingersAndToesMenu
};
const int SizeOfMenuArray = sizeof(MenuArray) /sizeof(MenuArray[0]);

LiquidCrystal_I2C lcd(0x3f, LCD_COLS, LCD_ROWS);
MenuControllerEncoder ControllerEncoder(A0, A1, A2, false, true);
MenuRendererLcdI2c RendererLcd(lcd, LCD_COLS, LCD_ROWS);
LiquidMVC MyMenu(RendererLcd, ControllerEncoder);


void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  MyMenu.Init();
  MyMenu.setMenuArray(MenuArray, SizeOfMenuArray);  
}

void loop()
{
  MyMenu.ExecMenu();
}


