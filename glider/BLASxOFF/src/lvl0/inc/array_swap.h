/*! This function swap two arrays together element by element
 *
 *
 *
 */


#ifndef ARRAY_SWAP_H
  #define ARRAY_SWAP_H


  #include "esp_attr.h"


  void IRAM_ATTR array_swap(
         float * arrSrcDstA,
         float * arrSrcDstB
       )
         __attribute__((always_inline))
         __attribute__((nonull));


  #include "../src/array_zero.c__"


#endif // ARRAY_SWAP_H

 
