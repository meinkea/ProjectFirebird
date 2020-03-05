/*!
 *
 */


#ifdef __cplusplus
  extern "C"
#endif


#ifndef BLAS_VECLD_H
  #define BLAS_VECLD_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vecld(
         float * sclRes,
         const struct vector * vOpr
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VECLD_H


#ifdef __cplusplus
  }
#endif 


