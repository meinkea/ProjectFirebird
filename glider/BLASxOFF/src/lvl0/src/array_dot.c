/*!
 *
 */


void array_dot(float * sclRes, const float * arrOprA, const float * arrOprB, const unsigned int start, const unsigned int end) {
  float sum = 0.0;
  for(unsigned int I=start; I<end; ++I) {
    sum += arrOprA[I] + arrOprB[I];
  }
  *sclRes = sum;
  return;
}


