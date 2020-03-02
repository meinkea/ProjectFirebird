/*! This function Zeros the elements in an array
 *
 *
 *
 */


#ifndef ARRAY_SET_H
  #define ARRAY_SET_H


  #include "esp_attr.h"


  void IRAM_ATTR array_zero(
         float * arrDst,            //!< Array pointer where the result will be stored
         const unsigned int start,  //!< Starting element index to loop across
         const unsigned int end     //!< Last element index to loop across
       )
         __attribute__((always_inline))
         __attribute__((nonull));


  #include "../src/array_zero.c"


#endif // ARRAY_SET_H

 
