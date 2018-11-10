// TODO: add header


#include <LiquidMVC.h>

#include <MenuControllerEncoder.h>
#include <MenuRendererLcd.h>


#define LCD_ROWS  4
#define LCD_COLS  20


#define LCD_PIN_RS  4
#define LCD_PIN_RW  6
#define LCD_PIN_EN  7
#define LCD_PIN_D4  8
#define LCD_PIN_D5  13
#define LCD_PIN_D6  11
#define LCD_PIN_D7  3


#define BACKLIGHT_PIN 5




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


int Backlight;
MenuOptionIntValue BacklightMenu("Backlight", Backlight, 0, 16);

void ChangeBacklight(void)
{
  analogWrite(BACKLIGHT_PIN, Backlight * 16);
}

int Number;
MenuOptionIntValue NumberMenu("Number", Number);


MenuOption *MenuArray[] =
{
  &NumberMenu,
  &FingersAndToesMenu,
  &BacklightMenu
};
const int SizeOfMenuArray = sizeof(MenuArray) /sizeof(MenuArray[0]);

LiquidCrystal lcd(LCD_PIN_RS, LCD_PIN_RW, LCD_PIN_EN, LCD_PIN_D4, LCD_PIN_D5, LCD_PIN_D6, LCD_PIN_D7);
MenuControllerEncoder ControllerEncoder(A0, A1, A2, false, true);
MenuRendererLcd RendererLcd(lcd, LCD_COLS, LCD_ROWS);
LiquidMVC MyMenu(RendererLcd, ControllerEncoder);


void setup()
{
  Backlight = 15;
  ChangeBacklight();
  BacklightMenu.setValueChangedCallback(ChangeBacklight);
  
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.clear();
  
  MyMenu.Init();
  MyMenu.setMenuArray(MenuArray, SizeOfMenuArray);  
}

void loop()
{
  MyMenu.ExecMenu();
}


