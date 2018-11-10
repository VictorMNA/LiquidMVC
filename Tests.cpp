// TODO: add header

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "LiquidMVC.h"

#include "MenuRendererLcd.h"
#include "MenuControllerEncoder.h"

#include "Tests.h"


#define LCD_ROWS  4
#define LCD_COLS  20

#define LCD_PIN_RS  4
#define LCD_PIN_RW  6
#define LCD_PIN_EN  7
#define LCD_PIN_D4  8
#define LCD_PIN_D5  13
#define LCD_PIN_D6  11
#define LCD_PIN_D7  3

#define LCD_BACKLIGHT_PIN 5






int Fingers = 10;
int Toes = 10;
MenuOptionIntValue SubElemento1("fingers", Fingers, 0, 10);
MenuOptionIntValue SubElemento2("toes", Toes, 0, 10);

MenuOption *SubMenu[] =
{
  &SubElemento1,
  &SubElemento2
};

int Potatoes = 16;

void Juan(void)
{
  Serial.println("Juan called!!!");
}

MenuOptionIntValue Elemento1("Potato chips", Potatoes);
MenuOptionSubmenu  Elemento2("I am a submenu", SubMenu, 2);
MenuOptionAction   Elemento3("Juan", Juan);
#define BACKLIGHT_PIN 5
int Backlight;
MenuOptionIntValue Elemento4("Backlight", Backlight, 0, 15);

void ChangeBacklight(void)
{
  analogWrite(BACKLIGHT_PIN, Backlight * 16);
}

MenuOption *ArrayMenu[] =
{
  &Elemento1,
  &Elemento2,
  &Elemento3,
  &Elemento4
};
const int SizeOfMenu = sizeof(ArrayMenu) /sizeof(ArrayMenu[0]);
  

LiquidCrystal lcd(LCD_PIN_RS, LCD_PIN_RW, LCD_PIN_EN, LCD_PIN_D4, LCD_PIN_D5, LCD_PIN_D6, LCD_PIN_D7);
MenuRendererLcd RendererLcd(lcd, LCD_COLS, LCD_ROWS);
MenuControllerEncoder ControllerEncoder(A0, A1, A2, false, true);

LiquidMVC MyMenu(RendererLcd, ControllerEncoder);

void TestLiquidMVC()
{
  Serial.println(">>> TestLiquidMVC test start");

  Backlight = 15;
  ChangeBacklight();

  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.clear();

  MyMenu.Init();
  Elemento4.setValueChangedCallback(ChangeBacklight);
  MyMenu.setMenuArray(ArrayMenu, SizeOfMenu);
  MyMenu.ExecMenu();

  Serial.println("TestLiquidMVC test end <<<");
}


