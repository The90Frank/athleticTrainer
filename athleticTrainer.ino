#include "Button.h"
#include "LedSimple.h"
#include "Matrix.h"
#include "Timer.h"
#include "OutManager.h"
#include <LinkedList.h>

Button* plus;
Button* minus;
Timer* timer;
OutManager* outManager;

LinkedList<LedSimple*>* leds;
LinkedList<Matrix*>* matrixs;

void setup() {
  Serial.begin(9600);
  leds = new LinkedList<LedSimple*>();
  leds->add(new LedSimple(13));
  leds->add(new LedSimple(12));
  leds->add(new LedSimple(11));
  leds->add(new LedSimple(10));

  matrixs = new LinkedList<Matrix*>();
  matrixs->add(new Matrix(5,6,7));

  outManager = new OutManager(leds, matrixs);
  outManager->bootAnimation();
    
  plus = new Button(3);
  minus = new Button(2);

  timer = new Timer(5000,plus,minus,outManager);
  
  timer->execStart();
  plus->execStart();
  minus->execStart();
  outManager->execStart();
}

void loop() {
  for(uint32_t i=0; i<leds->size(); i++){
    leds->get(i)->exec();
  }
  for(uint32_t i=0; i<matrixs->size(); i++){
    matrixs->get(i)->exec();
  }
  timer->exec();
  plus->exec();
  minus->exec();
  outManager->exec();
}
