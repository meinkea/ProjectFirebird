/*! This header file wraps the level1 functions
 * 
 *  Level one function contain BLAS methods with runtime of O(1)
 * 
 */


#ifndef BLAS_LEVEL1_H
  #define BLAS_LEVEL1_H


  #include"vascl.h"  // Add scalar to all elements in Vector A
  #include"vasum.h"  // 
  #include"vaxpy.h"  // Vector A Add Vector B
  #include"vaxsy.h"  // Vector A Subtract Vector B
  #include"vcopy.h"  // Copy Vector A to Vector B
  #include"vcros.h"  // Cross product for Vector A x Vector B
  #include"vdot.h"   // Dot product for Vector A * Vector B
  #include"vecld.h"  // Euclidean norm - 
  #include"vinit.h"  //
  #include"vload.h"
  #include"vmscl.h"  // 
  #include"vmult.h"
  #include"vnrm1.h"  // L1 norm - 
  #include"vnrm2.h"  // L2 norm - 
  #include"print.h"  // Return printable string of Vector A
  #include"puts.h"   // Return printable string of Vector A with return character '\n'
  #include"vswap.h"  // Swap data from Vector A with Vector B
  #include"vzero.h"  // Zero/clear data in Vector A


#endif // BLAS_LEVEL1_H


