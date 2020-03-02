/*!
 *
 */


#include "../inc/vdot.h"


// Level 0
#include "../../lvl0/inc/array_dot.h"


void vdot(float * sclRes, const struct vector * vOprA, const struct vector * vOprB) {
  array_dot(sclRes->v, vOprA->v, vOprB->v, 0, vOprA->l);
  return;
}


