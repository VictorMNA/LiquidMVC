// TODO: add header

#ifndef MENUCONTROLLERENCODER_H
#define MENUCONTROLLERENCODER_H

#include "MenuController.h"

#include "EncoderMenu.h"

class MenuControllerEncoder: public MenuController
{
  public:
    MenuControllerEncoder(uint8_t pinA, uint8_t pinB, uint8_t pinSW, bool clockwise = true, bool pullup = false);

    void Init(void) override;
    MenuController::Event Read(void) override;

  private:
    EncoderMenu _encoder;

// TODO: try to get working _lastEvent beeing part of the class
//       view MenuControllerEncoder.cpp for more info
//    MenuController::Event _lastEvent;
//
//    void GenerateSelectEvent(void);
//    void GeneratePrevEvent(void);
//    void GenerateNextEvent(void);
//    void NullFunction(void);
};

#endif

