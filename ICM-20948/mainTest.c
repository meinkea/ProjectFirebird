// mainTest.c
//
//


#include <stdio.h>


#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <arpa/inet.h>
#include <errno.h>


// From https://jameshfisher.com/2017/02/23/printing-bits/
//

void print_byte_as_bits(char val) {
	for(unsigned int i=7; 0<=i; i--) {
		printf("%c", (val & (1 << i)) ? '1' : '0');
	}
}

void print_bits(char * ty, char * val, unsigned char * bytes, size_t num_bytes) {
	printf("(%*s) %*s = [ ", 15, ty, 16, val);
	for (size_t i=0; i<num_bytes; i++) {
		print_byte_as_bits(bytes[i]);
		printf(" ");
	}
	printf(" ");
}

#define SHOW(T,V) do { T x = V; print_bits(#T, #V, (unsigned char *) &x, sizeof(x)); } while(0)

//
// End of

#include "ICM-20948.h"

// Main Test Method
int main(void) {

	struct tagDriveInstance icm = DriverClass.new(2,225,4,5);
	printf("%d %d %d %d \n\n", icm.setting_1, icm.setting_2, icm.setting_3, icm.setting_4);
	SHOW(int, icm.setting_1);
	SHOW(struct BANK0_READINGS, icm.bank_0_readings);
	int res = icm.add(&icm, 10);
	SHOW(int, res);

	return 0;
}






