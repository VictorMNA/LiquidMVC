// TODO: add header

//#include "LiquidMVC.h"

#include "Tests.h"


#include "MenuOption.h"

void setup() {
  
  Serial.begin(115200);
  Serial.println("Program started...");
  Serial.println();

  TestMenuOption();
  
  PrintNextTest();
  
  TestArrayOptions();

  PrintNextTest();
  
  TestMenuRendererLcd();

  PrintNextTest();
  
  TestMenuControllerEncoder();  

  PrintNextTest();

  TestLiquidMVCInit();
  
}

void loop() {


}

void PrintNextTest(void)
{
  Serial.println();
  Serial.println("Next test...");
  Serial.println();  
}

