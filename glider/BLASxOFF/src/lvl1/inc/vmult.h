/*!
 *
 */


#ifdef __cplusplus
  extern "C"
#endif


#ifndef BLAS_VMULT_H
  #define BLAS_VMULT_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vmult(
         struct vector * vRes,
         const struct vector * vOprA,
         const struct vector * vOprB
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VMULT_H


#ifdef __cplusplus
  }
#endif 


