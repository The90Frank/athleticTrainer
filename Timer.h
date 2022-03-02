#ifndef __TIMER_H
#define __TIMER_H

#define __TIMER_H_FIXED_DELTA 100
#define __TIMER_H_MAX_INTER 1200000
#define __TIMER_H_MIN_INTER __TIMER_H_FIXED_DELTA

#include "AsyncExecutor.h"
#include "Button.h"
#include "OutManager.h"

class Timer : public AsyncExecutor
{
private:
    uint32_t timing;
    Button* plus;
    Button* minus;
    OutManager* outmanager;
    
    
public:
    Timer(uint32_t _timeing, Button* _plus, Button* _minus, OutManager* _outmanager);
    
    void increase(uint32_t delta);
    void decrease(uint32_t delta);

    void task();
    void taskBoot();
    void taskShutdown();

    uint32_t getTiming() {return timing;}
};

#endif
