/*!
 *
 */


#ifndef BLAS_VECLD_H
  #ifndef BLAS_VECLD_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vecld(
         struct vector * vRes,
         const struct vector * vOpr
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VECLD_H


