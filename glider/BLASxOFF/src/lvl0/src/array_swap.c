/*!
 *
 */


void array_(float * arrSrcDstA, float * arrSrcDstB) {
  float * temp = arrSrcDstA;

  arrSrcDstA = arrSrcDstB;
  arrSrcDstB = temp;

  return;
}


