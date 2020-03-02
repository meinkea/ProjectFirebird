/*!
 *
 */


#ifndef BLAS_VPRINT_H
  #ifndef BLAS_VPRINT_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"
  #include "../../lvl0/inc/array_print.h"


  void IRAM_ATTR vprint(
         char * buf,
         const struct vector * vSrc,
      )
         __attribute__((nonull))
  ;


  int vprint_init_buffer(
        char * buf,
        const struct vector * vSrc
      )
  ;


  int vprint_free_buffer(
        char * buf
      )
  ;


  //! This useful function calculates the required char buffer size for printing
  //!
  inline unsigned int calc_buffer_size_req(const struct vector * vOpr) {
    return (unsigned int) (sizeof(char) * (vOpr->l * (BLAS_PRINT_ARRAY__NUM_DIGITS) +1));
  }


#endif // BLAS_VPRINT_H


