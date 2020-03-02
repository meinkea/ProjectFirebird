/*! This function add two arrays together element by element
 *
 *
 *
 */


#ifndef ARRAY_ADD_H
  #define ARRAY_ADD_H


  #include "esp_attr.h"


  void IRAM_ATTR array_add(
         float * arrRes,      //!< Array pointer where the result will be stored
         const float * arrOprA,     //!< Array pointer for the 1st operand
         const float * arrOprB,     //!< Array pointer for the 2nd operand
         const unsigned int start,  //!< Starting element index to loop across
         const unsigned int end     //!< Last element index to loop across
       )
         __attribute__((always_inline))
         __attribute__((nonull));


  #include "../src/array_add.c__"


#endif // ARRAY_ADD_H


