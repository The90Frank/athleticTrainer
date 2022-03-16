#include "Button.h"
#include "LedSimple.h"
#include "Matrix.h"
#include "Timer.h"
#include "OutManager.h"
#include "Clock.h"
#include <LinkedList.h>

Button* plus;
Button* minus;
Timer* timer;
Clock* clok;
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

  clok = new Clock(8,9);

  timer = new Timer(1000,plus,minus,outManager,clok);
  
  timer->execStart();
  plus->execStart();
  minus->execStart();
  clok->execStart();
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
  clok->exec();
  outManager->exec();
}
