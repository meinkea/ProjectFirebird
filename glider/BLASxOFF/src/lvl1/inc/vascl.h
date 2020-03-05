/*!
 *
 */


#ifdef __cplusplus
  extern "C"
#endif


#ifndef BLAS_VASCL_H
  #define BLAS_VASCL_H


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


#ifdef __cplusplus
  }
#endif 


