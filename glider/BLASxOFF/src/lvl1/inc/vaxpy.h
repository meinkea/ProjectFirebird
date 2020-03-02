/*!
 *
 */


#ifndef BLAS_VAXPY_H
  #define BLAS_VAXPY_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vaxpy(
         struct vector * vRes,
         const struct vector * vOprA,
         const struct vector * vOprB
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VAXPY_H


