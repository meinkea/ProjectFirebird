/*! Arduino Header file that flattens the includes
 *
 *  Arduino doesn't preform searches down beneath the main library directory unless told to0.
 *  So this header file does just that.
 *
 */


//  /* If we're not using GNU C, elide __attribute__ */
//  #ifndef __GNUC__
//  #  define  __attribute__(x)  /*NOTHING*/
//  #endif


#ifndef BLASxOFF_H
  #define BLASxOFF_H


  #include "./gnd/inc/BLAS_datatypes.h"
  #include "./lvl0/inc/level0.h"
  //#include "./lvl1/inc/level1.h"


#endif // BLASxOFF_H
