/*! This function computes the dot product between two arrays
 *
 *
 *
 */


#ifndef ARRAY_DOT_H
  #define ARRAY_DOT_H


  #include "esp_attr.h"


  void IRAM_ATTR array_dot(
         float * sclRes,      //!< Array pointer where the result will be stored
         const float * arrOprA,     //!< Array pointer for the 1st operand
         const float * arrOprB,     //!< Array pointer for the 2nd operand
         const unsigned int start,  //!< Starting element index to loop across
         const unsigned int end     //!< Last element index to loop across
       )
         __attribute__((always_inline))
         __attribute__((nonull));


  #include "../src/array_dot.c__"


#endif // ARRAY_DOT_H


