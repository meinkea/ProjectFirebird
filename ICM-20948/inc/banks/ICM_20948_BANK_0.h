//
//  ICM_20948_BANK_0.h
//


#ifndef ICM_20948_BANK_0_H
 #define ICM_20948_BANK_0_H
 
 #include <stdint.h>
 
// Encompasses the setting avaliable in Bank0
 struct BANK0_SETTINGS {
 	// reg 0x00 (0)
 	uint8_t WHO_AM_I           :8;
 	
 	// reg 0x03 (3)
 	uint8_t                    :1;
 	uint8_t I2C_MST_RST        :1;
 	uint8_t SRAM_RST           :1;
 	uint8_t DMP_RST            :1;
 	uint8_t I2C_IF_DIS         :1;
 	uint8_t I2C_MST_EN         :1;
 	uint8_t FIFO_EN            :1;
 	uint8_t DMP_EN             :1;
 		
 	// reg 0x05 (5)
 	uint8_t                    :4;
 	uint8_t GRYO_CYCLE         :1;
 	uint8_t ACCEL_CYCLE        :1;
 	uint8_t I2C_MST_CYCLE      :1;
 	uint8_t                    :1;
 	
 	// reg 0x06 (6)
 	uint8_t CLKSEL             :3;
 	uint8_t TEMP_DIS           :1;
 	uint8_t                    :1;
 	uint8_t LP_EN              :1;
 	uint8_t SLEEP              :1;
 	uint8_t DEVICE_RESET       :1;
 	
 	// reg 0x07 (7)
 	uint8_t DISABLE_GYRO       :3;
 	uint8_t DISABLE_ACCEL      :3;
 	uint8_t                    :2;
 	
 	// reg 0x0F (15)
 	uint8_t                    :1;
 	uint8_t BYPASS_EN          :1;
 	uint8_t FSYNC_INT_MODE_EN  :1;
 	uint8_t ACTL_FSYNC         :1;
 	uint8_t INT_ANTRD_2CLEAR   :1;
 	uint8_t INT1_LATCH_INT_EN  :1;
 	uint8_t INT1_OPEN          :1;
 	uint8_t INT1_ACTL          :1;
 	
 	// REG 0x10 (10)
 	uint8_t I2C_MST_INT_EN     :1;
 	uint8_t DMP_INT1_EN        :1;
 	uint8_t PLL_RDY_EN         :1;
 	uint8_t WOM_INT_EN         :1;
 	uint8_t                    :3;
 	uint8_t REG_WOF_EN         :1;
 	
 	// REG 0x11 (17)
 	uint8_t RAW_DATA_0_RDY_EN  :1;
 	uint8_t                    :7;
 	
 	// REG 0x12 (18)
 	uint8_t FIFO_OVERFLOW_EN   :5;
 	uint8_t                    :3;
 	
 	// REG 0x13 (19)
 	uint8_t FIFO_WM_EN         :5;
 	uint8_t                    :3;
 	
 	// REG 0x17 (23)
 	uint8_t I2C_SLV0_NACK      :1;
 	uint8_t I2C_SLV1_NACK      :1;
 	uint8_t I2C_SLV2_NACK      :1;
 	uint8_t I2C_SLV3_NACK      :1;
 	uint8_t I2C_SLV4_NACK      :1;
 	uint8_t I2C_LOST_ARB       :1;
 	uint8_t I2C_SLV4_DONE      :1;
 	uint8_t PASS_THROUGH       :1;
 	
 	// REG 0x19 (25)
 	uint8_t I2C_MST_INT        :1;
 	uint8_t DMP_INT1           :1;
 	uint8_t PLL_RDY_           :1;
 	uint8_t WOM_INT            :1;
 	uint8_t                    :4;
 	
 	// REG 0x1A (26)
 	uint8_t RAW_DATA_0_RDY_INT :1;
 	uint8_t                    :7;
 	
 	// REG 0x1B (27)
 	uint8_t FIFO_OVERFLOW_INT  :5;
 	uint8_t                    :3;
 	
 	// REG 0x1C (28)
 	uint8_t FIFO_WM_INT        :5;
 	uint8_t                    :3;
 	
 	//
 	// BREAK
 	//    - Sensor reading in ____ stuct
 	//
 	
 	
 	// REG 0x66 (102)
 	uint8_t SLV_0_FIFO_EN      :1;
 	uint8_t SLV_1_FIFO_EN      :1;
 	uint8_t SLV_2_FIFO_EN      :1;
 	uint8_t SLV_3_FIFO_EN      :1;
 	
 	// REG 0x67 (103)
 	uint8_t TEMP_FIFO_EN       :1;
 	uint8_t GYRO_X_FIFO_EN     :1;
 	uint8_t GYRO_Y_FIFO_EN     :1;
 	uint8_t GYRO_Z_FIFO        :1;
 	uint8_t ACCEL_FIFO_EN      :1;
 	uint8_t                    :3;
 	
 	// REG 0x68 (104)
 	uint8_t FIFO_RESET         :5;
 	uint8_t                    :3;
 	
 	// REG 0x69 (105)
 	uint8_t FIFO_MODE          :5;
 	uint8_t                    :3;
 	
 	// REG 0x70 (112)
 	uint8_t FIFO_CNT_H         :5;
 	uint8_t                    :3;
 	
 	// REG 0x71 (113)
 	uint8_t FIFO_CNT_L         :8;
 	
 	// REG 0x72 (114)
 	uint8_t FIFO_R_W           :8;
 	
 	// REG 0x74 (116)
 	uint8_t RAW_DATA_RDY       :4;
 	uint8_t                    :3;
 	uint8_t                    :1;
 	
 	// REG 0x76 (118)
 	uint8_t FIFO_CFG           :1;
 	uint8_t                    :7;
 	//
 };
 
 
 
 struct BANK0_READINGS {
 	// Store Readings
 	//
 	//  o- Time delay of 1st Gryo event after latest FSYNC event
 	//          o                                  o
 	//			|                                  |
 	//			|-----------(Time Delay)---------->|
 	//          |                                  |
 	//    (FSYNC Event)                       (Gyro Event)
 	//
 	//  o- Gyroscope's 16 bit reading
 	//
 	//  o- Accelerometer's 16 bit reading
 	//
 	//  o- Package Temperature Sensor's 16 bit reading
 	//       *- has 15.3489615084 bit precision
 	//       *- fixed 0.00299517776 °C / LSB
 	//
 	
 	
 	// REG 0x28 (40)
 	uint8_t DELAY_TIME_H :8;
 	// REG 0x29 (41)
 	uint8_t DELAY_TIME_L :8;
 	
 	// REG 0x2D (45)
 	uint8_t ACCEL_XOUT_H :8;
 	// REG 0x2E (46)
 	uint8_t ACCEL_XOUT_L :8;
 	
 	// REG 0x2F (47)
 	uint8_t ACCEL_YOUT_H :8;
 	// REG 0x30 (48)
 	uint8_t ACCEL_YOUT_L :8;
 	
 	// REG 0x31 (49)
 	uint8_t ACCEL_ZOUT_H :8;
 	// REG 0x32 (50)
 	uint8_t ACCEL_ZOUT_L :8;
 	
 	
 	
 	// REG 0x33 (51)
 	uint8_t GYRO_XOUT_L :8;
 	// REG 0x34 (52)
 	uint8_t GYRO_XOUT_H :8;
 	
 	// REG 0x35 (53)
 	uint8_t GYRO_YOUT_L :8;
 	// REG 0x36 (54)
 	uint8_t GYRO_YOUT_H :8;
 	
 	// REG 0x37 (55)
 	uint8_t GYRO_ZOUT_L :8;
 	// REG 0x39 (56)
 	uint8_t GYRO_ZOUT_H :8;
 	
 		
 	
 	// REG 0x3A (57)
 	uint8_t TEMP_OUT_L :8;
 	// REG 0x3B (58)
 	uint8_t TEMP_OUT_H :8;
 	//
 };
 
 
 
 
 struct BANK0_I2C_SLV {
 	// REG 0x3B (59)
 	uint8_t EXT_SLV_SENS_DATA_00 :8;
 	
 	// REG 0x3C (60)
 	uint8_t EXT_SLV_SENS_DATA_01 :8;
 	
 	// REG 0x3D (61)
 	uint8_t EXT_SLV_SENS_DATA_02 :8;
 	
 	// REG 0x3E (62)
 	uint8_t EXT_SLV_SENS_DATA_03 :8;
 	
 	// REG 0x3F (63)
 	uint8_t EXT_SLV_SENS_DATA_04 :8;
 	
 	// REG 0x40 (64)
 	uint8_t EXT_SLV_SENS_DATA_05 :8;
 	
 	// REG 0x41 (65)
 	uint8_t EXT_SLV_SENS_DATA_06 :8;
 	
 	// REG 0x42 (66)
 	uint8_t EXT_SLV_SENS_DATA_07 :8;
 	
 	// REG 0x43 (67)
 	uint8_t EXT_SLV_SENS_DATA_08 :8;
 	
 	// REG 0x44 (68)
 	uint8_t EXT_SLV_SENS_DATA_09 :8;
 	
 	// REG 0x45 (69)
 	uint8_t EXT_SLV_SENS_DATA_10 :8;
 	
 	// REG 0x46 (70)
 	uint8_t EXT_SLV_SENS_DATA_11 :8;
 	
 	// REG 0x47 (71)
 	uint8_t EXT_SLV_SENS_DATA_12 :8;
 	
 	// REG 0x48 (72)
 	uint8_t EXT_SLV_SENS_DATA_13 :8;
 	
 	// REG 0x49 (73)
 	uint8_t EXT_SLV_SENS_DATA_14 :8;
 	
 	// REG 0x4A (74)
 	uint8_t EXT_SLV_SENS_DATA_15 :8;
 	
 	// REG 0x4B (75)
 	uint8_t EXT_SLV_SENS_DATA_16 :8;
 	
 	// REG 0x4C (76)
 	uint8_t EXT_SLV_SENS_DATA_17 :8;
 	
 	// REG 0x4D (77)
 	uint8_t EXT_SLV_SENS_DATA_18 :8;
 	
 	// REG 0x4E (78)
 	uint8_t EXT_SLV_SENS_DATA_19 :8;
 	
 	// REG 0x4F (79)
 	uint8_t EXT_SLV_SENS_DATA_20 :8;
 	
 	// REG 0x50 (80)
 	uint8_t EXT_SLV_SENS_DATA_21 :8;
 	
 	// REG 0x51 (81)
 	uint8_t EXT_SLV_SENS_DATA_22 :8;
 	
 	// REG 0x52 (82)
 	uint8_t EXT_SLV_SENS_DATA_23 :8;
 };
 
 
#endif // ICM_20948_BANK_0_H
