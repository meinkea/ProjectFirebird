//
//  ICM_20948_BANK_3.h
//


#ifndef ICM_20948_BANK_3_H
 #define ICM_20948_BANK_3_H
 
 #include <stdint.h>
 
 
 struct BANK3 {
 
 	// I2C MASTER SETTINGS
 	//
 
 	// REG 0x00 (0)
 	uint8_t I2C_MST_ODR_CONFIG   :4;
 	uint8_t                      :4;
 	
 	// REG 0x01 (1)
 	uint8_t I2C_MST_CLK          :4;
 	uint8_t I2C_MST_P_NSR        :1;
 	uint8_t                      :2;
 	uint8_t MULT_MST_EN          :1;
 	
 	// REG 0x02 (2)
 	uint8_t I2C_SLV0_DELAY_EN    :1;
 	uint8_t I2C_SLV1_DELAY_EN    :1;
 	uint8_t I2C_SLV2_DELAY_EN    :1;
 	uint8_t I2C_SLV3_DELAY_EN    :1;
 	uint8_t I2C_SLV4_DELAY_EN    :1;
 	uint8_t                      :2;
 	uint8_t DELAY_ES_SHADOW      :1;
 
 
 	// I2C SLAVE 0 SETTINGS
 	//
 	
 	// REG 0x03 (3)
 	uint8_t I2C_ID_0             :7;
 	uint8_t I2C_SLV0_RNW         :1;
 	
 	// REG 0x04 (4)
 	uint8_t I2C_SLV0_REG         :8;
 	
 	// REG 0x05 (5)
 	uint8_t I2C_SLV0_LENG        :4;
 	uint8_t I2C_SLV0_GRP         :1;
 	uint8_t I2C_SLV0_REG_DIS     :1;
 	uint8_t I2C_SLV0_BYTE_SW     :1;
 	uint8_t	I2C_SLV0_EN          :1;
 	
 	// REG 0x06 (6)
 	uint8_t I2C_SLV0_DO          :8;
 	
 	// I2C SLAVE 1 SETTINGS
 	//
 	
 	// REG 0x07 (7)
 	uint8_t I2C_ID_1             :7;
 	uint8_t I2C_SLV1_RNW         :1;
 	
 	// REG 0x08 (8)
 	uint8_t I2C_SLV1_REG         :8;
 	
 	// REG 0x09 (9)
 	uint8_t I2C_SLV1_LENG        :4;
 	uint8_t I2C_SLV1_GRP         :1;
 	uint8_t I2C_SLV1_REG_DIS     :1;
 	uint8_t I2C_SLV1_BYTE_SW     :1;
 	uint8_t	I2C_SLV1_EN          :1;
 	
 	// REG 0x0A (10)
 	uint8_t I2C_SLV1_DO          :8;
 	
 	// I2C SLAVE 2 SETTINGS
 	//
 	
 	// REG 0x0B (11)
 	uint8_t I2C_ID_2             :7;
 	uint8_t I2C_SLV2_RNW         :1;
 	
 	// REG 0x0C (12)
 	uint8_t I2C_SLV2_REG         :8;
 	
 	// REG 0x0D (13)
 	uint8_t I2C_SLV2_LENG        :4;
 	uint8_t I2C_SLV2_GRP         :1;
 	uint8_t I2C_SLV2_REG_DIS     :1;
 	uint8_t I2C_SLV2_BYTE_SW     :1;
 	uint8_t	I2C_SLV2_EN          :1;
 	
 	// REG 0x0E (14)
 	uint8_t I2C_SLV2_DO          :8;
 	
 	
 	// I2C SLAVE 3 SETTINGS
 	//
 	
 	// REG 0x0F (15)
 	uint8_t I2C_ID_3             :7;
 	uint8_t I2C_SLV3_RNW         :1;
 	
 	// REG 0x10 (16)
 	uint8_t I2C_SLV3_REG         :8;
 	
 	// REG 0x11 (17)
 	uint8_t I2C_SLV3_LENG        :4;
 	uint8_t I2C_SLV3_GRP         :1;
 	uint8_t I2C_SLV3_REG_DIS     :1;
 	uint8_t I2C_SLV3_BYTE_SW     :1;
 	uint8_t	I2C_SLV3_EN          :1;
 	
 	// REG 0x12 (18)
 	uint8_t I2C_SLV3_DO          :8;
 	
 	// I2C SLAVE 4 SETTINGS
 	//
 	
 	// REG 0x13 (19)
 	uint8_t I2C_ID_4             :7;
 	uint8_t I2C_SLV4_RNW         :1;
 	
 	// REG 0x14 (20)
 	uint8_t I2C_SLV4_REG         :8;
 	
 	// REG 0x15 (21)
 	uint8_t I2C_SLV4_DLY         :5;
 	uint8_t I2C_SLV4_REG_DIS     :1;
 	uint8_t I2C_SLV4_BYTE_SW     :1;
 	uint8_t	I2C_SLV4_EN          :1;
 	
 	// REG 0x16 (22)
 	uint8_t I2C_SLV4_DO          :8;
 	
 	// REG 0x17 (23)
 	uint8_t I2C_SLV4_DI          :8;
 }
 
 
#endif // ICM_20948_BANK_3_H
