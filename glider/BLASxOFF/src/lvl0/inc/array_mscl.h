/*! This function multiplies each element of an array by a scalar
 *
 *
 *
 */


#ifndef ARRAY_MSCL_H
  #define ARRAY_MSCL_H


  #include "esp_attr.h"


  void IRAM_ATTR array_mscl(
         float * arrRes,            //!< Array pointer where the result will be stored
         const float * arrOpr,      //!< Array pointer for the 1st operand
         const float sclOpr,        //!< float for the 2nd Scalar operand
         const unsigned int start,  //!< Starting element index to loop across
         const unsigned int end     //!< Last element index to loop across
       )
         __attribute__((always_inline))
         __attribute__((nonull));


  #include "../src/array_mscl.c"


#endif // ARRAY_MSCL_H


