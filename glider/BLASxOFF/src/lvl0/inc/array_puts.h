/*! Returns a pointer to a putsable string with the return character '\n'
 *
 *
 *
 */


#ifndef ARRAY_PUTS_H
  #define ARRAY_PUTS_H


  #include "esp_attr.h"


  void IRAM_ATTR 
    __attribute__((always_inline))
    __attribute__((nonull))
  array_puts(
    char * string,             //!< Pointer to string buffer for printing
    const float * arrSrc,      //!< Array pointer for source data
    const unsigned int start,  //!< Starting element index to loop across
    const unsigned int end     //!< Last element index to loop across
  ) {
    return;
  }


#endif // ARRAY_PUTS_H


