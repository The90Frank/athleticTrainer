#ifndef __OUTMANAGER_H
#define __OUTMANAGER_H

#include "AsyncExecutor.h"
#include "LedSimple.h"
#include "Matrix.h"
#include <LinkedList.h>

class OutManager : public AsyncExecutor
{
protected:

    LinkedList<LedSimple*>* leds;
    LinkedList<Matrix*>* matrixs;
    LinkedList<byte*>* images;
    
    void closeAll();
    
public:
    OutManager(LinkedList<LedSimple*>* _leds, LinkedList<Matrix*>* _matrixs);

    void bootAnimation();

    void exec();
    
    void task();
    void taskBoot();
    void taskShutdown();
};

#endif
