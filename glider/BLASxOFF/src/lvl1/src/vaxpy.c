/*!
 *
 */


#include "../inc/vaxpy.h"


// level 0
#include "../../lvl0/inc/array_add.h"


void vaxpy(struct vector * vRes, const struct vector * vOprA, const struct vector * vOprB) {
  array_add(vRes->v, vOprA->v, vOprB->v, 0, vRes->l);
  return;
}


