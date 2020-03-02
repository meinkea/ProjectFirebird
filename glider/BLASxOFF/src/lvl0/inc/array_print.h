 /*! Returns a pointer to a printable string of the data in a Vector
  *
  *
  *
  */
 
 
 #ifndef ARRAY_PRINT_H
   #define ARRAY_PRINT_H


  #include <stdio.h>

  #include "esp_attr.h"

#ifndef BLAS_PRINT_CONST
 #define BLAS_PRINT_CONST

  // ----- DEFINE CONSTANTS -----
  // Max and Min value limits for check
  #define BLAS_PRINT_MAX_NUM 9999.0f
  #define BLAS_PRINT_MIN_NUM 0.0001f

  // Define the max digits (should mirror from Max and Min value limits)
  #define BLAS_PRINT_WHL_MAX_DIGITS 4 // max digits to the left of '.'
  #define BLAS_PRINT_DEC_MAX_DIGITS 4 // max digits to the right of '.'

  // Initial Place Value Extractor
  #define BLAS_PRINT_WHL_MODL 1000 // = 10^(WHL_MAX_DIGITS-1)
  #define BLAS_PRINT_DEC_MODL 1000 // = 10^(DEC_MAX_DIGITS-1)

  // TOTAL Size of char buffer
  #define BLAS_PRINT_ARRAY__NUM_DIGITS (BLAS_PRINT_WHL_MAX_DIGITS+1+BLAS_PRINT_DEC_MAX_DIGITS+1)

#endif // BLAS_PRINT_CONST

  void IRAM_ATTR array_print(
         char * buf,        //!< Pointer to string buffer for printing
         const float sclSrc  //!< Array pointer for source data
       )
         __attribute__((always_inline))
         __attribute__((nonull));


  #include "../src/array_print.c"


#endif // ARRAY_PRINT_H


