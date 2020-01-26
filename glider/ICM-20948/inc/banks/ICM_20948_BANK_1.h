//
//  ICM_20948_BANK_1.h
//


#ifndef ICM_20948_BANK_1_H
 #define ICM_20948_BANK_1_H
 
 #include <stdint.h>
 
 
 struct BANK1 {
 	// REG 0x02 (2)
 	uint8_t XG_ST_DATA :8;
 	
 	// REG 0x03 (3)
 	uint8_t YG_ST_DATA :8;
 	
 	// REG 0x04 (4)
 	uint8_t ZG_ST_GYRO :8;
 	
 	
 	
 	// REG 0x0E (14)
 	uint8_t XA_ST_DATA :8;
 	
 	// REG 0x0F (15)
 	uint8_t YA_ST_DATA :8;
 	
 	// REG 0x10 (16)
 	uint8_t ZA_ST_DATA :8;
 	
 	
 	
 	// REG 0x14 (20)
 	uint8_t XA_OFFS_H :8;
 	// REG 0x15 (21)
 	uint8_t           :1;
 	uint8_t XA_OFFS_L :7;
 	
 	// REG 0x17 (23)
 	uint8_t YA_OFFS_H :8;
 	// REG 0x18 (24)
 	uint8_t           :1;
 	uint8_t YA_OFFS_L :7;
 	
 	// REG 0x1A (26)
 	uint8_t ZA_OFFS_H :8;
 	// REG 0x1B (27)
 	uint8_t           :1;
 	uint8_t ZA_OFFS_L :7;
 	
 	
 	
 	// REG 0x28 (40)
 	uint8_t TBC_PLL :8;
 };
 
 
#endif // ICM_20948_BANKS
