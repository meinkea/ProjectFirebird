/*! This function swap two arrays together element by element
 *
 *
 *
 */


#ifndef ARRAY_SWAP_H
  #define ARRAY_SWAP_H


  #include "esp_attr.h"


  void IRAM_ATTR
    __attribute__((always_inline))
    __attribute__((nonull));
  array_swap(
    float * arrSrcDstA,
    float * arrSrcDstB
  ) {
    float * temp = arrSrcDstA;
  
    arrSrcDstA = arrSrcDstB;
    arrSrcDstB = temp;
  
    return;
  }


#endif // ARRAY_SWAP_H

 
