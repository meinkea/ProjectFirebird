/*!
 *
 */


void array_set(float * arrDst, const float sclSrc, const unsigned int start, const unsigned int end) {
  for(unsigned int I=start; I<end; ++I) {
    arrDst[I] = sclSrc;
  }
  return;
}


