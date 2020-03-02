/*!
 *
 */


#ifndef BLAS_VPRINT_H
  #define BLAS_VPRINT_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vprint(
         char * buf,
         const struct vector * vSrc
      )
         __attribute__((nonull))
  ;


  int vprint_init_buffer(
        char * buf,
        const struct vector * vSrc
      )
         __attribute__((nonull))
  ;


  int vprint_free_buffer(
        char * buf
      )
         __attribute__((nonull))
  ;

  unsigned int calc_buffer_size_req(
                 const struct vector * vOpr
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VPRINT_H


