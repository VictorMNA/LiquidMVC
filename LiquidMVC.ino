// TODO: add header

//#include "LiquidMVC.h"

#include "Tests.h"


#include "MenuOption.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Program started...");
  Serial.println();

  TestLiquidMVC();

  Serial.println();
  Serial.println("Tests ended.");
  Serial.println();
}

void loop() {


}

void PrintNextTest(void)
{
  Serial.println();
  Serial.println("Next test...");
  Serial.println();  
}

