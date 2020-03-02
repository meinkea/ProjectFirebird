/*! This function adds all the elements in an array and returns the sum
 *
 *
 *
 */


#ifndef ARRAY_ASUM_H
  #define ARRAY_ASUM_H


  #include "esp_attr.h"


  void IRAM_ATTR array_asum(
         float * sclRes,            //!< Float pointer for return value
         const float * arrOpr,      //!< Array pointer for elements to sum
         const unsigned int start,  //!< Starting element index to loop across
         const unsigned int end     //!< Last element index to loop across
       )
         __attribute__((always_inline))
         __attribute__((nonull));


  #include "../src/array_asum.c"


#endif // ARRAY_ASUM_H
