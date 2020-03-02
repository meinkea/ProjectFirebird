/*!
 *
 */


void array_mscl(float * arrRes, const float * arrOpr, const float sclOpr, const unsigned int start, const unsigned int end) {
  for(unsigned int I=start; I<end; ++I) {
    arrRes[I] = sclOpr * arrOpr[I];
  }
  return;
}


