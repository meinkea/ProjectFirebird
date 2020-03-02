/*!
 *
 */


#ifndef BLAS_VAXSY_H
  #define BLAS_VAXSY_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vaxsy(
         struct vector * vRes,
         const struct vector * vOprA,
         const struct vector * vOprB
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VAXSY_H


