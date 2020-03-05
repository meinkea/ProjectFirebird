/*! This function Zeros the elements in an array
 *
 *
 *
 */


#ifdef __cplusplus
  extern "C"
#endif


#ifndef ARRAY_SET_H
  #define ARRAY_SET_H


  #include "esp_attr.h"


  void IRAM_ATTR
    __attribute__((always_inline))
    __attribute__((nonull))
  array_zero(
    float * arrDst,            //!< Array pointer where the result will be stored
    const unsigned int start,  //!< Starting element index to loop across
    const unsigned int end     //!< Last element index to loop across
  ) {
    for(unsigned int I=start; I<end; ++I) {
      arrDst[I] = 0.0;
    }
    return;
  }


#endif // ARRAY_SET_H


#ifdef __cplusplus
  }
#endif 


