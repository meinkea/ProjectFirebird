/*!
 *
 */


#include "../inc/vecld.h"


#include "../../lvl0/inc/array_dot.h"


// Additional Includes
#include <math.h>


void vecld(float * sclRes, const struct vector * vOpr) {
  array_dot(sclRes, vOpr->v, 0, vOprA->l);
  * sclRes = (float) sqrt(* sclRes); 
  return;
}


