/*! This function substract two arrays together element by element
 *
 *
 *
 */


#ifndef ARRAY_SUBTRACT_H
  #define ARRAY_SUBTRACT_H


  #include "esp_attr.h"


  void IRAM_ATTR array_substract(
         float * arrRes,      //!< Array pointer where the result will be stored
         const float * arrOprA,     //!< Array pointer for the 1st operand
         const float * arrOprB,     //!< Array pointer for the 2nd operand
         const unsigned int start,  //!< Starting element index to loop across
         const unsigned int end     //!< Last element index to loop across
       )
         __attribute__((always_inline))
         __attribute__((nonull));


  #include "../src/array_subtract.c"


#endif // ARRAY_SUBTRACT_H


