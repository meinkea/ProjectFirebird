/*!
 *
 */


#ifdef __cplusplus
  extern "C"
#endif


#ifndef BLAS_VZERO_H
  #define BLAS_VZERO_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  // level 0
  void IRAM_ATTR vzero(
         struct vector * vDst
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VZERO_H


#ifdef __cplusplus
  }
#endif 


