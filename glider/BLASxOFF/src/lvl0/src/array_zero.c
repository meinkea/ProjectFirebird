/*!
 *
 */


void array_zero(float * arrDst, const unsigned int start, const unsigned int end) {
  for(unsigned int I=start; I<end; ++I) {
    arrDst[I] = 0.0;
  }
  return;
}


