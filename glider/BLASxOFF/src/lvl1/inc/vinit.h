/*!
 *
 */


#ifndef BLAS_VINIT_H
  #ifndef BLAS_VINIT_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  int IRAM_ATTR vinit(
         struct vector * V,
         const unsigned int l
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VINIT_H


