#include "Matrix.h"
#include "MatrixImages.h"

void Matrix::task(){
  
}

void Matrix::taskBoot(){
  for (uint32_t row = 0; row < 8; row++) {
    lc->setRow(0, row, image[row]);
  }
}

void Matrix::taskShutdown(){
  setImage(blankImg);
  lc->clearDisplay(0);
}

Matrix::Matrix(uint32_t DIN, uint32_t CS, uint32_t CLK){
  lc = new LedControl(DIN, CLK, CS, 1);
  lc->shutdown(0, false);
  lc->setIntensity(0, 15);
  lc->clearDisplay(0);
  setInterval(1);
  blankImg=new byte[8] IMAGE_NO;
  image = blankImg;
  init();
}

void Matrix::setImage(byte* img){
  image = img;
}

void Matrix::setLed(uint32_t row, uint32_t  col, bool state){
  lc->setLed(0, row, col, state);
}
