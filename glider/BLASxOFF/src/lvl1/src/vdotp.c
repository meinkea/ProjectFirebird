/*!
 *
 */


#include "../inc/vdotp.h"


// Level 0
#include "../../lvl0/inc/array_dot.h"


void vdotp(float * sclRes, const struct vector * vOprA, const struct vector * vOprB) {
  array_dot(sclRes, vOprA->v, vOprB->v, 0, vOprA->l);
  return;
}


