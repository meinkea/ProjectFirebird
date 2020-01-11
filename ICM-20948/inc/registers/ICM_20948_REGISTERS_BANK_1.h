//
//  ICM_20948_RAGISTERS_BANK_1.h



#ifndef ICM_20498_REGISTERS_BANK_1_H
 #define ICM_20498_REGISTERS_BANK_1_H
 
 
 /* BANK 1 REGISTER ADDRESSES */
 
 #define SELF_TEST_X_GYRO			0x02 // 2
 #define SELF_TEST_Y_GYRO			0x03 // 3
 #define SELF_TEST_Z_GYRO			0x04 // 4
 
 #define SELF_TEST_X_ACCEL			0x0E // 14
 #define SELF_TEST_Y_ACCEL			0x0F // 15
 #define SELF_TEST_Z_ACCEL			0x10 // 16
 
 #define XA_OFSS_H					0x14 // 20
 #define XA_OFFS_L					0x15 // 21
 
 #define YA_OFFS_H					0x17 // 23
 #define YA_OFFS_L					0x18 // 24
 
 #define ZA_OFFS_H					0x1A // 26
 #define ZA_OFFS_L					0x1B // 27
 
 #define TIMEBASE_CORRECTION_PLL	0x28 // 40
 
 #ifndef REG_BANK_SE
  #define REG_BANK_SEL				0xF7 // 127 
 #endif // REG_BANK_SEL
 
 
#endif // ICM_20498_REGISTERS_BANK_1_H
