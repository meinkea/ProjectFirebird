/*! This function adds a scalar too each element in an array
 *
 *  - This function is deliberatly placed in Instruction RAM.
 *    Meaning that this function will always remained cached.
 *  - the __attribute__((always_inline)) tells the compiler to ALWAYS inline to function reguardless of optimization levels
 *  - the __attribute__((nonull)) tells the compiler that the function's pointer arguments cannot bell NULL 
 */


#ifndef ARRAY_ASCL_H
  #define ARRAY_ASCL_H


  #include "esp_attr.h"


  void IRAM_ATTR array_ascl(
         float * arrRes,        //!< Array pointer where the result will be stored
         const float * arrOpr,      //!< Pointer for the array operand
         const float sclOpr,        //!< Scalar operand to add to the elements of the array operand
         const unsigned int start,  //!< Begining element index to begin loop
         const unsigned int end     //!< Last element index to loop across
       )
         __attribute__((always_inline))
         __attribute__((nonull));


  #include "../src/array_ascl.c"


#endif // ARRAY_ASCL_H


