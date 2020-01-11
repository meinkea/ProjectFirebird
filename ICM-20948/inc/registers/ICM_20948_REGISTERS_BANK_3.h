//
//  ICM_20948_REGISTERS_BANK_3_H
//


#ifndef ICM_20498_REGISTERS_BANK_3_H
 #define ICM_20498_REGISTERS_BANK_3_H
 
 
 /* BANK 3 REGISTER ADDRESSES */
 
 #define I2C_MST_ODR_CONFIG		0x00 // 0
 #define I2C_MST_CTRL			0x01 // 1
 #define I2C_MST_DELAY_CTRL		0x02 // 2
 
 #define I2C_SLV0_ADDR			0x03 // 3
 #define I2C_SLV0_REG			0x04 // 4
 #define I2C_SLV0_CTRL			0x05 // 5
 #define I2C_SLV0_DO			0x06 // 6
 
 #define I2C_SLV1_ADDR			0x07 // 7
 #define I2C_SLV1_REG			0x08 // 8
 #define I2C_SLV1_CTRL			0x09 // 9
 #define I2C_SLV1_DO			0x0A // 10
 
 #define I2C_SLV2_ADDR			0x0B // 11
 #define I2C_SLV2_REG			0x0C // 12
 #define I2C_SLV2_CTRL			0x0D // 13
 #define I2C_SLV2_DO			0x0E // 14
 
 #define I2C_SLV3_ADDR			0x0F // 15
 #define I2C_SLV3_REG			0x10 // 16
 #define I2C_SLV3_CTRL			0x11 // 17
 #define I2C_SLV3_DO			0x12 // 18
 
 #define I2C_SLV4_ADDR			0x13 // 19
 #define I2C_SLV4_REG			0x14 // 20
 #define I2C_SLV4_CTRL			0x15 // 21
 #define I2C_SLV4_DO			0x16 // 22
 #define I2C_SLV4_DI			0x17 // 23
 
 #ifndef REG_BANK_SEL
  #define REG_BANK_SEL			0xF7 // 127
 #endif // REG_BANK_SEL
 
 
#endif // ICM_20498_REGISTERS_BANK_3_H
