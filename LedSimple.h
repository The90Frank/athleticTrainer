#ifndef __LEDSIMPLE_H
#define __LEDSIMPLE_H

#include "AsyncExecutor.h"

class LedSimple : public AsyncExecutor
{
private:
    uint32_t ledPin;
    
public:
    LedSimple(uint32_t pin);

    void setLed(bool state);
    
    void task();
    void taskBoot();
    void taskShutdown();
};

#endif
