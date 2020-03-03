/*!
 *
 */


#ifndef BLAS_VINIT_H
  #define BLAS_VINIT_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "vector.h"


  int IRAM_ATTR vinit(
         struct vector * V,
         const unsigned int l
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VINIT_H


