/*! Utitility function for initializing vector datatypes
 *
 *  Return Codes
 *     0 ~ Vector Initialization and Allocation was successful
 *    -1 ~ (ERROR) Vector has already been initialized
 *    -2 ~ (ERROR) Malloc has failed
 *
 */


#include "../inc/vinit.h"

#include <stddef.h>
#include <stdlib.h>


int vinit(struct vector * V, const unsigned int l) {
  // Check to see if vector has already been allocated
  if(V->flags & V_ALLOCATED_F == V_ALLOCATED_F) {
    return -1;
  }

  float * Vptr = NULL;
  
  // Allocating Vector Memory
  Vptr = (float *) malloc(l * sizeof(float));
  //  For clarity, explict casting is use (like C++) instead of implicit (like C)

  // Check for if malloc return failed (NULL)
  if(Vptr == NULL) {
    return -2;
  }

  // Zero out vector
  array_zero(Vptr, 0, l); 

  // Ready to set up new vector -> Reset Flags
  V->flags = 0;

  // Set length of vector
  V->l = l;

  // Hand over the new vector
  V->v = Vptr;

  // Set vector Allocated flag
  V->flags = V_ALLOCATED_F;

  return 0;
}


