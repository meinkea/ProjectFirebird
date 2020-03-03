/*! This function set two arrays together element by element
 *
 *
 *
 */


#ifndef ARRAY_SET_H
  #define ARRAY_SET_H


  #include "esp_attr.h"


  void IRAM_ATTR 
    __attribute__((always_inline))
    __attribute__((nonull));
  array_set(
    float * arrDst,            //!< Array pointer where the result will be stored
    const float sclSrc,        //!< Float for the source scalar
    const unsigned int start,  //!< Starting element index to loop across
    const unsigned int end     //!< Last element index to loop across
  ) {
    for(unsigned int I=start; I<end; ++I) {
      arrDst[I] = sclSrc;
    }
    return;
  }


#endif // ARRAY_SET_H

 
