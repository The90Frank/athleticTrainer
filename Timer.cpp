#include "Timer.h"

Timer::Timer(uint32_t _timing, Button* _plus, Button* _minus, OutManager* _outmanager){
  init();
  setInterval(100);
  timing = _timing;
  plus = _plus;
  minus = _minus;
  outmanager = _outmanager;
}

void Timer::increase(uint32_t delta){
  if(timing + delta <= __TIMER_H_MAX_INTER){ 
    timing += delta;
  } else {
    timing = __TIMER_H_MAX_INTER;                    
  }
}

void Timer::decrease(uint32_t delta){
  if(timing - delta > __TIMER_H_MIN_INTER){ 
    timing -= delta;
  } else {
    timing = __TIMER_H_MIN_INTER;                    
  }
}

void Timer::task(){
    if(plus->isClicked()){
      increase(__TIMER_H_FIXED_DELTA);
    }
    if(minus->isClicked()){
      decrease(__TIMER_H_FIXED_DELTA);
    }
    outmanager->setInterval(timing);
}

void Timer::taskBoot(){}

void Timer::taskShutdown(){}
