//
//  ICM_20948_REGISTERS_BANK_0_H
//


#ifndef ICM_20498_REGISTERS_BANK_0_H
 #define ICM_20498_REGISTERS_BANK_0_H
 
 
 /* BANK 0 REGISTER ADDRESSES */
 
 #define reg_WHO_AM_I			0x00 // 0
 
 #define USER_CTRL				0x03 // 3
 
 #define LP_CONFIG				0x05 // 5
 #define PWR_MGMT_1				0x06 // 6
 #define PWR_MGMT_2				0x07 // 7
 
 #define INT_PIN_CFG			0x0F // 15
 #define INT_ENABLE				0x10 // 16
 #define INT_ENABLE_1			0x11 // 17
 #define INT_ENABLE_2			0x12 // 18
 #define INT_ENABLE_3			0x13 // 19
 
 #define I2C_MST_STATUS			0x17 // 23
 
 #define INT_STATUS				0x19 // 25
 #define INT_STATUS_1			0x1A // 26
 #define INT_STATUS_2			0x1B // 27
 #define INT_STATUS_3			0x1C // 28
 
 #define DELAY_TIMEH			0x28 // 40
 #define DELAY_TIMEL			0x29 // 41
 
 #define ACCEL_XOUT_H			0x2D // 45
 #define ACCEL_XOUT_L			0x2E // 46
 #define ACCEL_YOUT_H			0x2F // 47
 #define ACCEL_YOUT_L			0x30 // 48
 #define ACCEL_ZOUT_H			0x31 // 49
 #define ACCEL_ZOUT_L			0x32 // 50
 #define GYRO_XOUT_H			0x33 // 51
 #define GYRO_XOUT_L			0x34 // 52
 #define GYRO_YOUT_H			0x35 // 53
 #define GRYO_YOUT_L			0x36 // 54
 #define GRYO_ZOUT_H			0x37 // 55
 #define GYRO_ZOUT_L			0x38 // 56
 #define TEMP_OUT_H				0x39 // 57
 #define TEMP_OUT_L				0x3A // 58

 #define EXT_SLV_SENS_DATA_00	0x3B // 59
 #define EXT_SLV_SENS_DATA_01	0x3C // 60
 #define EXT_SLV_SENS_DATA_02	0x3D // 61
 #define EXT_SLV_SENS_DATA_03	0x3E // 62
 #define EXT_SLV_SENS_DATA_04	0x3F // 63
 #define EXT_SLV_SENS_DATA_05	0x40 // 64
 #define EXT_SLV_SENS_DATA_06	0x41 // 65
 #define EXT_SLV_SENS_DATA_07	0x42 // 66
 #define EXT_SLV_SENS_DATA_08	0x43 // 67
 #define EXT_SLV_SENS_DATA_09	0x44 // 68
 #define EXT_SLV_SENS_DATA_10	0x45 // 69
 #define EXT_SLV_SENS_DATA_11	0x46 // 70
 #define EXT_SLV_SENS_DATA_12	0x47 // 71
 #define EXT_SLV_SENS_DATA_13	0x48 // 72
 #define EXT_SLV_SENS_DATA_14	0x49 // 73
 #define EXT_SLV_SENS_DATA_15	0x50 // 74
 #define EXT_SLV_SENS_DATA_16	0x5A // 75
 #define EXT_SLV_SENS_DATA_17	0x5B // 76
 #define EXT_SLV_SENS_DATA_18	0x5C // 77
 #define EXT_SLV_SENS_DATA_19	0x5D // 78
 #define EXT_SLV_SENS_DATA_20	0x5E // 79
 #define EXT_SLV_SENS_DATA_21	0x5F // 80
 #define EXT_SLV_SENS_DATA_22	0x51 // 81
 #define EXT_SLV_SENS_DATA_23	0x52 // 82
 
 #define FIFO_EN_1				0x66 // 102
 #define FIFO_EN_2				0x67 // 103
 #define FIFO_RST				0x68 // 104
 #define FIFO_MODE				0x69 // 105
 
 #define FIFO_COUNT_H			0x70 // 112
 #define FIFO_COUNT_L			0x71 // 113
 #define FIFO_R_W				0x72 // 114
 
 #define DATA_RDY_STATUS		0X74 // 116
 
 #define FIFO_CFG				0x76 // 118
 
 #define MEM_START_ADDR			0x7C // 124  (supper secret)
 #define MEM_R_W				0x7D // 125  (supper secret)
 #define MEM_BANK_SEL			0x7E // 126  (supper secret)
 
 #ifndef REG_BANK_SE
  #define REG_BANK_SEL			0xF7 // 127 
 #endif // REG_BANK_SEL
 
 
#endif // ICM_20498_REGISTERS_BANK_0_H
