#include "LedSimple.h"

void LedSimple::task(){
  
}

void LedSimple::taskBoot(){
  digitalWrite(ledPin, HIGH);
}

void LedSimple::taskShutdown(){
  digitalWrite(ledPin, LOW);
}

LedSimple::LedSimple(uint32_t pin){
  ledPin = pin;
  setInterval(1024);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  init();
}

void LedSimple::setLed(bool state){
  if(state) digitalWrite(ledPin, HIGH);
  else digitalWrite(ledPin, LOW);
}
