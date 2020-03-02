/*!
 *
 */


#include "../inc/vaxsy.h"


// level 0
#include "../../lvl0/inc/array_subtract.h"


void vaxsy(struct vector * vRes, const struct vector * vOprA, const struct vector * vOprB) {
  array_subtract(vRes->v, vOprA->v, vOprB->v, 0, vRes->l); 
  return;
}


