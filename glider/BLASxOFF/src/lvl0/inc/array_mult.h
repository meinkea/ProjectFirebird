/*! This function multiplies elements of an array by a scalar
 *
 *
 *
 */


#ifdef __cplusplus
  extern "C"
#endif


#ifndef ARRAY_MULT_H
  #define ARRAY_MULT_H


  #include "esp_attr.h"


  void IRAM_ATTR 
    __attribute__((always_inline))
    __attribute__((nonull))
  array_mult(
    float * arrRes,            //!< Array pointer where the result will be stored
    const float * arrOprA,     //!< Array pointer for the 1st operand
    const float * arrOprB,     //!< Array pointer for the 2nd operand
    const unsigned int start,  //!< Starting element index to loop across
    const unsigned int end     //!< Last element index to loop across
  ) {
    for(unsigned int I=start; I<end; ++I) {
      arrRes[I] = arrOprA[I] * arrOprB[I];
    }
    return;
  }


#endif // ARRAY_MULT_H


#ifdef __cplusplus
  }
#endif 


