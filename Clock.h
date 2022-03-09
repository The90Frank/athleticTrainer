#ifndef __CLOCK_H
#define __CLOCK_H

#include "AsyncExecutor.h"
#include <TM1637.h>

class Clock : public AsyncExecutor
{
private:
    uint32_t value;
    TM1637 * tm;

    void displayNumber(int num);
    
public:
    Clock(uint32_t clk, uint32_t dio);

    void setNumber(uint32_t n);
    
    void task();
    void taskBoot();
    void taskShutdown();
};

#endif
