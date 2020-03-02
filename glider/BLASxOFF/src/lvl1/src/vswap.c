/*!
 *
 */


#include "../inc/vswap.h"

#include <stddef.h>


void vswap(struct vector * vSrcDstA, struct vector * vSrcDstB) {
  int flags_temp = 0;
  unsigned int l_temp = 0;
  char * name_temp = NULL;
  float * v_temp = NULL;

  flags_temp       = vSrcDstA->flags;
  l_temp           = vSrcDstA->l;
  name_temp        = vSrcDstA->name;
  v_temp           = vSrcDstA->v;

  vSrcDstA->flags  = vSrcDstB->flags;
  vSrcDstA->l      = vSrcDstB->l;
  vSrcDstA->name   = vSrcDstB->name;
  vSrcDstA->v      = vSrcDstB->v;

  vSrcDstB->flags  = flags_temp;
  vSrcDstB->l      = l_temp;
  vSrcDstB->name   = name_temp;
  vSrcDstB->v      = v_temp;

  return;
}


