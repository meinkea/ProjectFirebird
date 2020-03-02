/*!
 *
 */


#ifndef BLAS_VASUM_H
  #define BLAS_VASUM_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vasum(
         float * vRes,
         const struct vector * vOpr
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VASUM_H


