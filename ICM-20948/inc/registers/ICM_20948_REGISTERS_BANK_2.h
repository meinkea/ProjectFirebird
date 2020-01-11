//
//  ICM_20948_REGISTERS_BANK_2.h
//


#ifndef ICM_20498_REGISTERS_BANK_2_H
 #define ICM_20498_REGISTERS_BANK_2_H
 
 
 /* BANK 2 REGISTER ADDRESSES */
 
 #define GYRO_SMMPLRT_DIV		0x00 // 0
 #define GYRO_CONFIG_1			0x01 // 1
 #define GYRO_CONFIG_2			0x02 // 2
 #define XG_OFFS_USRH			0x03 // 3
 #define XG_OFFS_USRL			0x04 // 4
 #define YG_OFFS_USRH			0x05 // 5
 #define YG_OFFS_USRL			0x06 // 6
 #define ZG_OFFS_USRH			0x07 // 7
 #define ZG_OFFS_USRL			0x08 // 8
 #define ODR_ALIGN_EN			0x09 // 9
 
 #define ACCEL_SMPLRT_DIV_1		0x10 // 16
 #define ACCEL_SMPLRT_DIV_2		0x11 // 17
 #define ACCEL_INTEL_CTRL		0x12 // 18
 #define ACCEL_WOM_THR			0x13 // 19
 #define ACCEL_CONFIG			0x14 // 20
 #define ACCEL_CONFIG_2			0x15 // 21
 
 #define FSYNC_CONFIG			0x52 // 82
 #define TEMP_CONFIG			0x53 // 83
 #define MOD_CTRL_USR			0X54 // 84
 
 #ifndef REG_BANK_SEL
  #define REG_BANK_SEL			0xF7 // 127
 #endif // REG_BANK_SEL
 
 
#endif // ICM_20498_REGISTERS_BANK_2_H
