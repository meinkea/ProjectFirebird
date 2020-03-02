/*!
 *
 */


// Level 0 includes
#include "../inc/vcros3.h"


void vcros3(struct vector * vRes, const struct vector * vOprA, const struct vector * vOprB) {
  // Derefence Vector Data
  float * vR = vRes->v;
  float * vA = vOprA->v;
  float * vB = vOprB->v ;

  // Dereference Vector Operand A
  float vA0 = vA[0];
  float vA1 = vA[1];
  float vA2 = vA[2];

  // Dereference Vector Operand B
  float vB0 = vB[0];
  float vB1 = vB[1];
  float vB2 = vB[2];

  // Compute cross product
  vR[0] = vA1 * vB2 - vA2 * vB1;
  vR[1] = vA2 * vB0 - vA0 * vB2;
  vR[2] = vA0 * vB1 - vA1 * vB0;
  return;
}


