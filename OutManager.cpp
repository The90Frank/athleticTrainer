#include "OutManager.h"
#include "MatrixImages.h"

void OutManager::exec(){
  if(objectActive){
    currentMillis = millis();
    if (currentMillis > previousMillis + interval) {
      previousMillis = currentMillis;
      task();
    } else if (currentMillis > previousMillis + (interval-50)) { //(interval-1000) se si vuole un black fisso di 1 secondo
      closeAll();
    } 
  }  
}

void OutManager::closeAll(){
  for(uint32_t i=0; i<leds->size(); i++){
    leds->get(i)->execStop();
  }
  for(uint32_t i=0; i<matrixs->size(); i++){
    matrixs->get(i)->execStop();
  }
}

void OutManager::task(){
  uint32_t ledIdx = rand() % leds->size();
  leds->get(ledIdx)->execStart();

  uint32_t imgIdx = rand() % images->size();
  byte* image = images->get(imgIdx);
  for(uint32_t i=0; i<matrixs->size(); i++){
    matrixs->get(i)->setImage(image);
    matrixs->get(i)->execStart();
  }
  
}

void OutManager::taskBoot(){
   closeAll();
   task();
}

void OutManager::taskShutdown(){
  closeAll();
}

OutManager::OutManager(LinkedList<LedSimple*>* _leds, LinkedList<Matrix*>* _matrixs){
  matrixs=_matrixs;
  leds=_leds;
  images = new LinkedList<byte*>();
  
  images->add(new byte[8] IMAGE_FA);
  images->add(new byte[8] IMAGE_FB);
  images->add(new byte[8] IMAGE_FC);
  images->add(new byte[8] IMAGE_FD);
  images->add(new byte[8] IMAGE_FE);
  
  setInterval(100);
  init();
}

void OutManager::bootAnimation(){
  //cose scenografiche
  for(uint32_t i=0; i<leds->size(); i++){
    leds->get(i)->setLed(true);
    delay(200);
  }
  for(uint32_t i=0; i<matrixs->size(); i++){
    for(uint32_t j=0; j<8; j++){
      for(uint32_t k=0; k<8; k++){
        matrixs->get(i)->setLed(j, k, true);
        delay(50);
      }
    }
    for(uint32_t j=0; j<8; j++){
      for(uint32_t k=0; k<8; k++){
        matrixs->get(i)->setLed(k, j, false);
        delay(50);
      }
    }
  }
  for(uint32_t i=0; i<leds->size(); i++){
    leds->get(leds->size()-i-1)->setLed(false);
    delay(200);
  }
  closeAll();
  delay(2000);
}
