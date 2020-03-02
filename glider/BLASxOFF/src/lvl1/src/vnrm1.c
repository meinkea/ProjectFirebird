/*!  Taxicab norm (aka Manhattan norm)
 *
 */


#include "../inc/vnrm1.h"

#include <stdlib.h>


void vnrm1(float * sclRes, const struct vector * vOprA, const struct vector * vOprB) {
  float * vA = vOprA->v;
  float * vB = vOprB->v;


  float res = 0.0;
  unsigned int length = vOprA->l;


  for(unsigned int I=0; I<length; ++I) {
    res += abs(vA[I] - vB[I]);
  }

  * sclRes = res;
  return;
}


