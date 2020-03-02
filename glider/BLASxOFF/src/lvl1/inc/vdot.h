/*!
 *
 */


#ifndef BLAS_VDOT_H
  #ifndef BLAS_VDOT_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vdot(
         struct vector * vRes,
         const struct vector * vOprA,
         const struct vector * vOprB
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VDOT_H


