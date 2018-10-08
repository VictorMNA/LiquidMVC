// TODO: add header

//#include "LiquidMVC.h"

#include "Tests.h"


#include "MenuOption.h"

void setup() {
  
  Serial.begin(115200);
  Serial.println("Program started...");
  Serial.println();
  Serial.println();

  TestMenuOption();
  
  Serial.println();
  Serial.println();
  Serial.println("Next test...");
  Serial.println();
  Serial.println();
  
  TestArrayOptions();
}

void loop() {


}

