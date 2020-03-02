/*!
 *
 */


#ifndef BLAS_VSWAP_H
  #define BLAS_VSWAP_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vswap(
         struct vector * vScrDstA,
         struct vector * vScrDstB
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VSWAP_H


