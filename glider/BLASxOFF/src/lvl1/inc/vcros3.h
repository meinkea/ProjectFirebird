/*!
 *
 */


#ifndef BLAS_VCROS_H
  #ifndef BLAS_VCROS_H


  #include "esp_attr.h"


  // GROUND Includes
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vcros(
         struct vector * vRes,
         const struct vector * vOprA,
         const struct vector * vOprB
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VCROS_H


