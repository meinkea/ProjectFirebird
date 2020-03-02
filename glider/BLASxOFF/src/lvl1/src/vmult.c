/*!
 *
 */


#include "../inc/vmult.h"


#include "../../lvl0/inc/array_mult.h"


void vmult(struct vector * vRes, const struct vector * vOprA, const struct vector * vOprB) {
  array_mult(vRes->v, vOprA->v, vOprB->v, 0, vRes->l);
  return;
}


