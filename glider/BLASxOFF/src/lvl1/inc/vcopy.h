/*!
 *
 */


#ifdef __cplusplus
  extern "C"
#endif


#ifndef BLAS_VCOPY_H
  #define BLAS_VCOPY_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vcopy(
         struct vector * vDst,
         const struct vector * vSrc
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VCOPY_H


#ifdef __cplusplus
  }
#endif 


