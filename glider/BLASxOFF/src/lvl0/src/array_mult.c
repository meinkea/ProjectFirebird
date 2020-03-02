/*!
 *
 */


void array_mult(float * arrRes, const float * arrOprA, const float * arrOprB, const unsigned int start, const unsigned int end, const float sclOpr) {
  for(unsigned int I=start; I<end; ++I) {
    arrRes[I] = arrOprA[I] * arrOprB[I];
  }
  return;
}


