/*!
 *
 */


#ifndef BLAS_VNRM1_H
  #ifndef BLAS_VNRM1_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vnrm1(
         float * sclRes,
         const struct vector * vOprA,
         const struct vector * vOprB
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VNRM1_H


