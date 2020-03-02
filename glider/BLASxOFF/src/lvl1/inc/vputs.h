/*!
 *
 */


#ifndef BLAS_VPUTS_H
  #define BLAS_VPUTS_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vputs(
         char * buf,
         const struct vector * vSrc
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VPUTS_H


