// TODO: add header


#include <LiquidMVC.h>

#include <MenuControllerSerial.h>
#include <MenuRendererSerial.h>




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

MenuControllerSerial ControllerSerial(Serial);
MenuRendererSerial RendererSerial(Serial);
LiquidMVC MyMenu(RendererSerial, ControllerSerial);


void setup()
{
  Serial.begin(115200);

  MyMenu.Init();
  MyMenu.setMenuArray(MenuArray, SizeOfMenuArray);  
}

void loop()
{
  MyMenu.ExecMenu();
}


