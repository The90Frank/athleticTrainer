#ifndef __MATRIX_H
#define __MATRIX_H

#include "AsyncExecutor.h"
#include "LedControl.h"

class Matrix : public AsyncExecutor
{
private:
  LedControl* lc;
  byte* image;
  byte* blankImg;

public:
    Matrix(uint32_t DIN, uint32_t CLK, uint32_t CS);

    void setImage(byte* img);
    void setLed(uint32_t row, uint32_t  col, bool state);
    
    void task();
    void taskBoot();
    void taskShutdown();
};

#endif
