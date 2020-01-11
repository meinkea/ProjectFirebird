#ifndef ICM_20948_CALLS_H
#define ICM_20948_CALLS_H


#include <stdint.h>

struct bank0 {
	uint8_t enable;
    


	// reg 03 USER_CTRL
	uint8_t : 1;
	uint8_t I2C_MST_RST : 1; 
	uint8_t SRAM_RST : 1;
	uint8_t DMP_RST : 1;
	uint8_t I2C_IF_DIS : 1;
	uint8_t I2C_MST_EN : 1;
	uint8_t FIFO_EN : 1;
	uint8_t DMP_EN : 1;


	// reg 05 LP_CONFIG
	uint8_t : 4;
	uint8_t GYRO_CYCLE : 1;
	uint8_t ACCEL_CYCLE : 1;
	uint8_t I2C_MST_CYCLE : 1;

	// reg 00i
	uint8_t WHO_AM_I : 8;
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



unsigned GetField(unsigned int all, unsigned int mask, unsigned int shift);

unsigned SetField(unsigned int all, unsigned int mask, unsigned int shift, unsigned int value);



#endif // ICM-20948_CALLS_H
