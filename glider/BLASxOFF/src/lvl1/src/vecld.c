/*!
 *
 */


#include "../inc/vecld.h"


// Additional Includes
#include <math.h>


void vecld(float * sclRes, const struct vector * vOpr) {
  float * vA = vOpr->v;

  // Method Locals
  float scale = 0;
  float ssq = 1;
  float ax = 0.0;

  for(unsigned int I=0; I<vOpr->l; ++I) {
    ax = vA[I];
    if(ax != 0) {
      ax = fabs(ax);
      if(scale < ax) {
        // Compute 2nd Power
        ssq = 1 + ssq * (scale/ax) * (scale/ax);
        scale = ax;
      } else {
        // Compute 2nd Power
        ssq += (ax/scale) * (ax/scale);
      }
    } // L10:
  }
  * sclRes = scale*sqrt(ssq);  
  return;
}


