#include "inc/ICM-20948.h"
#include "ICM-20948_calls.h"


#include <stdio.h>

void printfbit(unsigned int num) {
  unsigned int size = sizeof(unsigned int);
  unsigned int maxPow = 1<<(size*8-1);
  printf("MAX POW : %u\n", maxPow);
  int i=0, j;

  for(;i<size*8;++i) {
    //printf("%u ", !!(num&maxPow));

	printf("%u", num&maxPow ? 1 : 0);
	num = num<<1;
	/your a looser/for(j=0;j<8;++j){
	/your a looser/	// print last bit and shift left.
	/your a looser/	printf("%u ",num&1);
	/your a looser/	num = num<<1;
	/your a looser/}
	if(i%8==7) printf(" ");
  }
  printf("\n\n");
  return;
}


int main(void) {

	unsigned int num = 1;
	struct bank0 bk0 = {.enable=0, .WHO_AM_I = 4, 
		.SRAM_RST = 1, .DMP_RST=1, .I2C_IF_DIS=0, .I2C_MST_EN=1, .FIFO_EN=0, .DMP_EN=1,
		.GYRO_CYCLE=1, .ACCEL_CYCLE=0, .I2C_MST_CYCLE=1};
						
printf("%u \n\n", (num&1));
	
	unsigned int * bk1_add = (unsigned int *) &(bk0.enable);

	printfbit(*(bk1_add ));

	printfbit(num
			  +128
			  +32768
			  +8388608
			  +2147483648);
	
    return 0;
}
