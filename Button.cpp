#include "Button.h"

void Button::task(){
  if (digitalRead(buttonPin) == HIGH) {
    clicked = true;
  } else {
    clicked = false;
  }
}

void Button::taskBoot(){
  clicked = false;
}

void Button::taskShutdown(){
  clicked = false;
}

Button::Button(uint32_t pin){
  buttonPin = pin;
  pinMode(buttonPin, INPUT);
  clicked = false;
  setInterval(1);
  
  init();
}
