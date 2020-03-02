/*!
 *
 */


#ifndef BLAS_VLOAD_H
  #ifndef BLAS_VLOAD_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vload(
         struct vector * vDst
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VLOAD_H


