/*!
 *
 */


void array_add(float * arrRes, float * arrOprA, float * arrOprB, unsigned int start, unsigned int end) {
  for(unsigned int I=start; I<end; ++I) {
    arrRes[I] = arrOprA[I] + arrOprB[I];
  }
  return;
}


