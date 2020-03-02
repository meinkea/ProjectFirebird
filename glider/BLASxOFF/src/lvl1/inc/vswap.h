/*!
 *
 */


#ifndef BLAS_VSWAP_H
  #ifndef BLAS_VSWAP_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vswap(
         struct vector * vRes,
         const struct vector * vOpr,
         const float sclOpr
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VSWAP_H


