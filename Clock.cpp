#include "Clock.h"

void Clock::task(){
  displayNumber(value);
}

void Clock::taskBoot(){
  displayNumber(0);
}

void Clock::taskShutdown(){
  displayNumber(0);
}

Clock::Clock(uint32_t clk, uint32_t dio){
  tm = new TM1637(clk,dio);
  tm -> set(2);
  tm->init();
  setNumber(0);
  setInterval(10);
  init();
}

void Clock::setNumber(uint32_t n){
  value = n;
}

void Clock::displayNumber(int num){   
    tm->display(3, num % 10);   
    tm->display(2, num / 10 % 10);   
    tm->display(1, num / 100 % 10);   
    tm->display(0, num / 1000 % 10);
}
