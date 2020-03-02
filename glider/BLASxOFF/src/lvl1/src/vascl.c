/*!
 *
 */


#include "../inc/vascl.h"


// level 0
#include "../../lvl0/inc/array_ascl.h"


void vascl(struct vector * vRes, const struct vector * vOpr, const float sclOpr) {
  array_ascl(vRes->v, vOpr->v, sclOpr, vRes, 0, vRes->l);
  return;
}


