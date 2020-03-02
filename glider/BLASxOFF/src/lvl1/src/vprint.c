/*!
 *
 */


#include "../inc/vprint.h"
#include "../../lvl0/inc/array_print.h"
#include <stddef.h>



void vprint(char * buf, const struct vector * vSrc) {
  float * vS = vSrc->v;

  for(unsigned int I=0; I<vSrc; ++I) {
    array_print(buf[I], vS[I]);
  }

  return;
}


int vprint_init_buffer(char * buf, const struct vector * vSrc) {
  // Check to see if buffer is NULL
  if(buf != NULL) {
    return -1; // Not a clean buffer
  }
  
  char * Bptr = NULL;

  // Allocating String Buffer
  Bptr = (char *) malloc(calc_buffer_size_req(vSrc));

  // Check for if malloc return failed (NULL)
  if(Bptr == NULL) {
    return -2;
  }

  // Hand over the new char buffer
  buf = Bptr;

}


int vprint_free_buffer(char * buf) {
  // Check to see if the buffer is NULL
  if(buf == NULL) {
    return -1; // Buffer already allocated!! (DO NOT FREE TWICE!)
  }
  
  free(buf);

  return 0;
}



  //! This useful function calculates the required char buffer size for printing
  //!
unsigned int calc_buffer_size_req(const struct vector * vOpr) {
    return (unsigned int) (sizeof(char) * (vOpr->l * (BLAS_PRINT_ARRAY__NUM_DIGITS) +1));
}


