/*!
 *
 */


void array_copy(float * arrDst, const float * arrSrc, const unsigned int start, const unsigned int end) {
  for(unsigned int I=start; I<end; ++I) {
    arrDst[I] = arrSrc[I];
  }
  return;
}


