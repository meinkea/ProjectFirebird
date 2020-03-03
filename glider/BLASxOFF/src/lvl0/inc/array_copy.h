/*! This function copies the elements of one arrays into another array
 *
 *
 *
 */


#ifndef ARRAY_COPY_H
  #define ARRAY_COPY_H


  #include "esp_attr.h"


  void IRAM_ATTR 
    __attribute__((always_inline))
    __attribute__((nonull))
  array_copy(
         float * arrDst,            //!< Array pointer destination to copy source data into
         const float * arrSrc,      //!< Array pointer for source data
         const unsigned int start,  //!< Starting element index to loop across
         const unsigned int end     //!< Last element index to loop across
  ) {
    for(unsigned int I=start; I<end; ++I) {
      arrDst[I] = arrSrc[I];
    }
    return;
  }


#endif // ARRAY_COPY_H


