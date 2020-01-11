//
//  ICM_20948_BANKS.h
//


#ifndef ICM_20948_BANKS_H
 #define ICM_20948_BANKS_H
 
 #include <stdint.h>
 
 
 // Container for Register Banks
 struct BANKS {
 	uint8_t :4;
 	uint8_t :USER_BANKS :2;
 	uint8_t :2;
 	
 	struct BANK0_SETTINGS bank_0_settings;
 	struct BANK0_READINGS bank_0_readings;
 	struct BANK0_I2C_SLV  bank_0_slv;
 
 	struct BANK1          bank1;
 	
 	struct BANK2          bank2;
 	
 	struct BANK3          bank3;
 };
 
 
#endif // ICM_20948_BANKS_H
