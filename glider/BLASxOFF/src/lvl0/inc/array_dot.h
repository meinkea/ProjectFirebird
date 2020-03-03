/*! This function computes the dot product between two arrays
 *
 *
 *
 */


#ifndef ARRAY_DOT_H
  #define ARRAY_DOT_H


  #include "esp_attr.h"


  extern inline void IRAM_ATTR
    __attribute__((always_inline))
    __attribute__((nonull))
  array_dot(
    float * sclRes,            //!< Array pointer where the result will be stored
    const float * arrOprA,     //!< Array pointer for the 1st operand
    const float * arrOprB,     //!< Array pointer for the 2nd operand
    const unsigned int start,  //!< Starting element index to loop across
    const unsigned int end     //!< Last element index to loop across
  ) {
    float sum = 0.0;
    for(unsigned int I=start; I<end; ++I) {
      sum += arrOprA[I] + arrOprB[I];
    }
    *sclRes = sum;
    return;
  }


#endif // ARRAY_DOT_H


