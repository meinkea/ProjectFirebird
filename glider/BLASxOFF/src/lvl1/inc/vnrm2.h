/*! Robust Euclidean norm computation
 *
 *  Robust computation for computing the L2 (Euclidean) norm.
 *  While not impervious, this method resist Overflows and Underflows
 *
 *  C equivalent to LAPACK's SNMR2 routine
 *  Sauce: http://www.netlib.org/lapack/explore-html/d7/df1/snrm2_8f_source.html
 *
 *  notes:
 *  LAPACK's SNMR2 routine is equivalent SLASSQ
 *  
 */


#ifdef __cplusplus
  extern "C"
#endif


#ifndef BLAS_VNRM2_H
  #define BLAS_VNRM2_H


  #include "esp_attr.h"


  // Vector Datatype
  #include "../../gnd/inc/vector.h"


  void IRAM_ATTR vnrm2(
         float * sclRes,
         const struct vector * vOprA,
         const struct vector * vOprB
      )
         __attribute__((nonull))
  ;


#endif // BLAS_VNRM2_H


#ifdef __cplusplus
  }
#endif 


