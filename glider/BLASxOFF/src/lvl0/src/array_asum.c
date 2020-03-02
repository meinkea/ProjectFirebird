/*!
 *
 */


void array_asum(float * sclRes, const float * arrOpr, const unsigned int start, const unsigned int end) {
  float res = 0.0;
  for(unsigned int I=start; I<end; ++I){
    res += arrOpr[I];
  }
  *sclRes += res;
  return;
}


