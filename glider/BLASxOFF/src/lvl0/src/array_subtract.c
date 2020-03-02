/*!
 *
 */


void array_subtract(float * arrRes, const float * arrOprA, const float * arrOprB, const unsigned int start, const unsigned int end) {
  for(unsigned int I=start; I<end; ++I) {
    arrRes[I] = arrOprA - arrOprB;
  }
  return;
}


