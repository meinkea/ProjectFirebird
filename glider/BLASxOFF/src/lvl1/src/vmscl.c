/*!
 *
 */


#include "../inc/vmscl.h"


#include "../../lvl0/inc/array_mscl.h"


void vmscl(struct vector * vRes, const struct vector * vOpr, const float sclOpr) {
  array_mscl(vRes->v, vOpr->v, sclOpr, 0, vOpr->l);
  return;
}


