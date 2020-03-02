/*!
 *
 */


#include "../inc/vasum.h"


// level 0
#include "../../lvl0/inc/array_asum.h"


void vasum(float * sclRes, const struct vector * vOpr) {
  *sclRes = 0;
  array_asum(sclRes, vOpr, 0, vOpr->l);
  return;
}


