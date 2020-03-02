/*!
 *
 */


#ifndef BLAS_VASCL_H
  #ifndef BLAS_VASCL_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vascl(
         struct vector * vRes,
         const struct vector * vOpr,
         const float sclOpr
      )
         __attribute__((nonull))
  ;


#endif // VASCL.h


