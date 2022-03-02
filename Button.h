#ifndef __BUTTON_H
#define __BUTTON_H

#include "AsyncExecutor.h"

class Button : public AsyncExecutor
{
private:
    uint32_t buttonPin;
    bool clicked;
    
public:
    Button(uint32_t pin);
    bool isClicked() { return clicked; }
    
    void task();
    void taskBoot();
    void taskShutdown();
};

#endif
