// TODO: add header


#include <LiquidMVC.h>

#include <MenuControllerEncoder.h>
#include <MenuRendererOled.h>


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Fonts/Org_01.h>
#define FONT Org_01

#define OLED_X_PIXELS  128
#define OLED_Y_PIXELS  32


#define OLED_RESET  -1



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


int Number1;
MenuOptionIntValue Number1Menu("Number 1", Number1);

int Number2;
MenuOptionIntValue Number2Menu("Number 2", Number2);

MenuOption *MenuArray[] =
{
  &Number1Menu,
  &Number2Menu,
  &FingersAndToesMenu
};
const int SizeOfMenuArray = sizeof(MenuArray) /sizeof(MenuArray[0]);

Adafruit_SSD1306 oled(OLED_RESET);
MenuControllerEncoder ControllerEncoder(A0, A1, A2, false, true);
MenuRendererOled RendererOled(oled, OLED_X_PIXELS, OLED_Y_PIXELS, FONT.yAdvance);
LiquidMVC MyMenu(RendererOled, ControllerEncoder);


void setup()
{
 
  Wire.begin();
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  oled.clearDisplay();   
  oled.display();   
  oled.setFont(&FONT);  
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setTextWrap(false); 
  
  MyMenu.Init();
  MyMenu.setMenuArray(MenuArray, SizeOfMenuArray);  
}

void loop()
{
  MyMenu.ExecMenu();
}
