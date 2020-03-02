/*!
 *
 */


void array_add(float * arrRes, const float * arrOprA, const float * arrOprB, const unsigned int start, const unsigned int end) {
  for(unsigned int I=start; I<end; ++I) {
    arrRes[I] = arrOprA[I] + arrOprB[I];
  }
  return;
}


