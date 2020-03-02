/*!
 *
 */


#include "../inc/vzero.h"

#include "../../lvl0/inc/array_zero.h"


void vzero(struct vector * vDst) {
  array_zero(vDst, 0, vDst->l);
  return;
}


