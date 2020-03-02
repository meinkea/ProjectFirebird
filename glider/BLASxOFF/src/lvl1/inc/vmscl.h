/*!
 *
 */


#ifndef BLAS_VMSCL_H
  #define BLAS_VMSCL_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vmscl(
         struct vector * vRes,
         const struct vector * vOpr,
         const float sclOpr
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VMSCL_H


