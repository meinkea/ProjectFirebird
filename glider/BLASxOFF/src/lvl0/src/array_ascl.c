/*! Function definition for adding a scalar to an array
 *
 */


void array_ascl(float * arrRes, const float * arrOpr, const float sclOpr, const unsigned int start, const unsigned int end) {
  for(unsigned int I=start; I<end;++I) {
    arrRes[I] = arrOpr[I] + sclOpr;
  }
  return;
}


