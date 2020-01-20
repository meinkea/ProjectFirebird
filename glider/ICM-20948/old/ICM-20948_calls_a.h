
#include <stdint.h>

struct bank0 {
	// reg 00
	uint8_t WHO_AM_I : 8;

	// reg 03 USER_CTRL
	uint8_t : 1; 
	uint8_t SRAM_RST : 1;
	uint8_t DMP_RST : 1;
	uint8_t I2C_IF_DIS : 1;
	uint8_t I2C_MST_EN : 1;
	uint8_t FIFO_EN : 1;
	uint8_t DMP_EN : 1;
/*
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
*/
};

struct bank1 {


};



struct bank2 {




};

struct bank3 {



};



unsigned GetField(unsigned int all, unsigned int mask, unsigned int shift) {
	    return (all & mask) >> shift;
}

unsigned SetField(unsigned int all, unsigned int mask, unsigned int shift, unsigned int value) {
	    return (all & ~mask) | ((value << shift) & mask);
}





#include <stdint.h>

struct bank0 {
	// reg 00
	uint8_t WHO_AM_I : 8;

	// reg 03 USER_CTRL
	uint8_t : 1; 
	uint8_t SRAM_RST : 1;
	uint8_t DMP_RST : 1;
	uint8_t I2C_IF_DIS : 1;
	uint8_t I2C_MST_EN : 1;
	uint8_t FIFO_EN : 1;
	uint8_t DMP_EN : 1;
/*
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
	uint8_t : 0;
*/
};

struct bank1 {


};



struct bank2 {




};

struct bank3 {



};



unsigned GetField(unsigned int all, unsigned int mask, unsigned int shift) {
	    return (all & mask) >> shift;
}

unsigned SetField(unsigned int all, unsigned int mask, unsigned int shift, unsigned int value) {
	    return (all & ~mask) | ((value << shift) & mask);
}




