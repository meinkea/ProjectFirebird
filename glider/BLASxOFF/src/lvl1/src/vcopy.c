/*!
 *
 */


#include "../inc/vcopy.h"


// Level 0
#include "../../lvl0/inc/array_copy.h"


void vcopy(struct vector * vDst, const struct vector * vSrc) {
  array_copy(vDst->v, vSrc->v, 0, vDst->l);
  return;
}


