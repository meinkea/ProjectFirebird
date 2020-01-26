//
//  ICM_20948_BANK_2.h
//


#ifndef ICM_20948_BANK_2_H
 #define ICM_20948_BANK_2_H
 
 #include <stdint.h>
 
 
 struct BANK2 {
 	// REG 0x00 (0)
 	uint8_t GYRO_SMPPLRT_DIV     :8;
 	
 	// REG 0x01 (1)
 	uint8_t GYRO_FCHOICE         :1;
 	uint8_t GYRO_FS_SEL          :2;
 	uint8_t GYRO_DLPFCFG         :3;
 	uint8_t                      :2;
 	
 	// REG 0x02 (2)
 	uint8_t GYRO_AVGCFG          :3;
 	uint8_t ZGYRO_CTEN           :1;
 	uint8_t YGYRO_CTEN           :1;
 	uint8_t XGYRO_CTEN           :1;
 	
 	
 	// REG 0x03 (3)
 	uint8_t XG_OFFS_USER_H       :8;
 	// REG 0x04 (4)
 	uint8_t XG_OFFS_USER_L       :8;
 	
 	// REG 0x05 (5)
 	uint8_t YG_OFFS_USER_H       :8;
 	// REG 0x06 (6)
 	uint8_t YG_OFFS_USER_L       :8;
 	
 	// REG 0x07 (7)
 	uint8_t ZG_OFFS_USER_H       :8;
 	// REG 0x08 (8)
 	uint8_t ZG_OFFS_USER_L       :8;
 	
 	
 	
 	// REG 0x09 (9)
 	uint8_t ODR_ALIGN_EN         :1;
 	uint8_t                      :7;
 	
 	// REG 0x10 (16)
 	uint8_t ACCEL_SMPLRT_DIV_H   :4;
 	uint8_t                      :4;
 	
 	// REG 0x11 (17)
 	uint8_t ACCEL_SMPLRT_DIV_L   :8;
 	
 	// REG 0x12 (18)
 	uint8_t ACCEL_INTEL_MODE_INT :1;
 	uint8_t ACCEL_INTEL_EN       :1;
 	uint8_t                      :6;
 	
 	// REG 0x13 (19)
 	uint8_t WOM_THRESHOLD        :8;
 	
 	// REG 0x14 (20)
 	uint8_t ACCEL_FCHOICE        :1;
 	uint8_t ACCEL_FS_SEL         :2;
 	uint8_t ACCEL_DLPFCFG        :3;
 	uint8_t                      :2;
 	
 	// REG 0x15 (21)
 	uint8_t DEC3_CFG             :2;
 	uint8_t AZ_ST_EN_REG         :1;
 	uint8_t AY_ST_EN_REG         :1;
 	uint8_t AX_ST_EN_REG         :1;
 	uint8_t                      :3;
 	
 	// REG 0x52 (82)
 	uint8_t EXT_SYNC_SET         :4;
 	uint8_t WOF_EDGE_INT         :1;
 	uint8_t WOF_DEGLITCH_INT     :1;
 	uint8_t                      :1;
 	uint8_t DELAY_TIME_EN        :1;
 	
 	// REG 0x53 (83)
 	uint8_t TEMP_DLPFCFG         :3;
 	uint8_t                      :5;
 	
 	// REG 0x54 (84)
 	uint8_t REG_LP_DMP_EN        :1;
 	uint8_t                      :7;
 };
 
 
#endif // ICM_20948_BANK_2_H
