/*! Returns a pointer to a putsable string with the return character '\n'
 *
 *
 *
 */


#ifndef ARRAY_PUTS_H
  #define ARRAY_PUTS_H


  #include "esp_attr.h"


  void IRAM_ATTR array_puts(
         char * string,             //!< Pointer to string buffer for printing
         const float * arrSrc,      //!< Array pointer for source data
         const unsigned int start,  //!< Starting element index to loop across
         const unsigned int end     //!< Last element index to loop across
       )
         __attribute__((always_inline))
         __attribute__((nonull));


  #include "../src/array_puts.c"


#endif // ARRAY_PUTS_H


