/*! \file lms9ds1REGS.h
* lms9ds1 Magnetometer and Accelerometer library
*
* \author	Ken Gregson
* \version	0.1
* \date		2018 
* \copyright	©2018, Ken Gregson, released under MIT License
*/

#ifndef _lsm9ds1REGS_h_
#define _lsm9ds1REGS_h_

/*
* Address and register definitions for SenseHAT LSM9DS1 IMU (accel, gyro, and mag)
*/

// LSM9DS1 I2C Addresses on SenseHAT //
#define ACCELGYRO_ADDR  0x6A
#define MAG_ADDR        0x1C

// LSM9DS1 Accelerometer and Gyroscope Registers //
#define ACT_THS          0x04
#define ACT_DUR          0x05
#define INT_GEN_CFG_XL   0x06 
#define INT_GEN_THS_X_XL 0X07
#define INT_GEN_THS_Y_XL 0X08
#define INT_GEN_THS_Z_XL 0X09
#define INT_GEN_DUR_XL   0X0A
#define REFERENCE_G      0x0B
#define INT1_CTRL        0x0C
#define INT2_CTRL        0x0D
#define WHO_AM_I         0x0F
#define CTRL_REG1_G      0x10
#define CTRL_REG2_G      0x11
#define CTRL_REG3_G      0x12
#define ORIENT_CFG_G     0x13
#define INT_GEN_SRC_G    0x14
#define OUT_TEMP_L       0x15
#define OUT_TEMP_H       0X16
#define STATUS_REG_G     0X17
#define OUT_X_L_G        0X18
#define OUT_X_H_G        0x19
#define OUT_Y_L_G        0x1A
#define OUT_Y_H_G        0x1B
#define OUT_Z_L_G        0x1C
#define OUT_Z_H_G        0x1D
#define CTRL_REG4        0x1E
#define CTRL_REG5_XL     0x1F
#define CTRL_REG6_XL     0x20
#define CTRL_REG7_XL     0x21
#define CTRL_REG8        0x22
#define CTRL_REG9        0x23
#define CTRL_REG10       0x24
#define INT_GEN_SRC_XL   0x26
#define STATUS_REG_XL    0x27
#define OUT_X_L_XL       0X28
#define OUT_X_H_XL       0X29
#define OUT_Y_L_XL       0X2A
#define OUT_Y_H_XL       0x2B
#define OUT_Z_L_XL       0x2C
#define OUT_Z_H_XL       0x2D
#define FIFO_CTRL        0x2E
#define FIFO_SRC         0x2F
#define INT_GEN_CGF_G    0x30
#define INT_GEN_THS_XH_G 0x31
#define INT_GEN_THS_XL_G 0x32
#define INT_GEN_THS_YH_G 0x33
#define INT_GEN_THS_YL_G 0x34
#define INT_GEN_THS_ZH_G 0x35
#define INT_GEN_THS_ZL_G 0x36
#define INT_GEN_DUR_G    0x37

// LMS9DS1Magnetometer Registers //
#define OFFSET_X_REG_L_M 0x05
#define OFFSET_X_REG_H_M 0x06
#define OFFSET_Y_REG_L_M 0x07
#define OFFSET_Y_REG_H_M 0x08
#define OFFSET_Z_REG_L_M 0x09
#define OFFSET_Z_REG_H_M 0x0A
#define WHO_AM_I_M       0x0F
#define CTRL_REG1_M      0x20
#define CTRL_REG2_M      0x21
#define CTRL_REG3_M      0x22
#define CTRL_REG4_M      0x23
#define CTRL_REG5_M      0x24
#define STATUS_REG_M     0x27
#define OUT_X_L_M        0x28
#define OUT_X_H_M        0x29
#define OUT_Y_L_M        0x2A
#define OUT_Y_H_M        0x2B
#define OUT_Z_L_M        0x2C
#define OUT_Z_H_M        0x2D
#define INT_CFG_M        0x30
#define INT_SRC_M        0x31
#define INT_THS_L_M      0x32
#define INT_THS_H_M      0x33

// Magnetometer CTRL_REG1_M (0x20)
#define ODR_M_0p625      0x00 // 0.625 Hz output
#define ODR_M_1p25       0x04 // 1.25 Hz output
#define ODR_M_2p5        0x08 // 2.5 Hz output
#define ODR_M_5          0x0C // 5 Hz output
#define ODR_M_10         0x10 // 10 Hz output (default)
#define ODR_M_20         0x14 // 20 Hz output
#define ODR_M_40         0x18 // 40 Hz output
#define ODR_M_80         0x1C // 80 Hz output
#define TEMP_COMP_DIS    0x00 // Temperature compensation disabled (default)
#define TEMP_COMP_ENB    0x80 // Temperature compensation enabled
#define OM_LOW           0x00 // Low-power mode (default)
#define OM_MEDIUM        0x20 // Medium-performance mode
#define OM_HIGH          0x40 // High-performance
#define OM_ULTRA         0x60 // Ultra-high performance
#define FAST_ODR_DIS     0x00 // Fast(er than 80 Hz) output data rate disabled (default)
#define FAST_ODR_ENB     0x02 // Fast ODR enabled
#define ST_DIS           0x00 // Self-test disabled (default)
#define ST_ENB           0x01 // Self-test enabled

// Magnometer Scale, CTRL_REG2_M (0x21) //
#define FS_M_4           0x00 // +/- 4 gauss (default)
#define FS_M_8           0x20 // +/- 8 gauss
#define FS_M_12          0x40 // +/- 12 gauss
#define FS_M_16          0x60 // +/- 16 gauss

// Magnetometer Operating Mode, CTRL_REG3_M (0x22) //
#define MD_M_CONTINUOUS  0x00 // Continuous conversion mode
#define MD_M_SINGLE      0x01 // Single conversion mode
#define MD_M_POWERDOWN   0x03 // Poweer-down mode (default)

// Register CTRL_REG6_XL (0x20) - Accelerometer only operation
// Accelerometer Scale //
#define FS_XL_2          0x00 // +/- 2 g (default)
#define FS_XL_4          0x08 // +/- 4 g
#define FS_XL_8          0x10 // +/- 8 g
#define FS_XL_16         0x18 // +/- 16 g

// Accelerometer Output Data Rate
#define ODR_XL_OFF       0x00 // Power-down
#define ODR_XL_10        0x20 // 10 Hz
#define ODR_XL_50        0x40 // 50 Hz
#define ODR_XL_119       0x60 // 119 Hz
#define ODR_XL_238       0x80 // 238 Hz
#define ODR_XL_476       0xA0 // 476 Hz
#define ODR_XL_952       0xC0 // 952 Hz

// Accelerometer BW Scaling
#define BW_SCAL_ODR      0x00 // BW determined by ODR (default)
#define BW_SCAL_XL       0x04 // BW selected by BW_XL
#define BW_XL_408        0x00 // 408 Hz BW (default)
#define BW_XL_211        0x01 // 211 Hz BW
#define BW_XL_105        0x02 // 105 Hz BW
#define BW_XL_50         0x03 // 59 Hz BW

// Register CTRL_REG1_G (0x10) - Combined Gyro and Accelerometer operation
// Gyroscope Full Scale //
#define FS_G_245         0x00 // 245 dps
#define FS_G_500         0x08 // 500 dps
#define FS_G_2000        0x18 // 2000 dps

// Accelerometer + Gyro Output Data Rate
#define ODR_G_OFF        0x00 // Power-down
#define ODR_G_14p9       0x20 // 14.9 Hz output, 5 Hz cutoff
#define ODR_G_59p5       0x40 // 59.5 Hz output, 19 Hz cutoff
#define ODR_G_119        0x60 // 119 Hz output, 38 Hz cutoff
#define ODR_G_238        0x80 // 238 Hz output, 76 Hz cutoff
#define ODR_G_476        0xA0 // 476 Hz output, 100 Hz cutoff
#define ODR_G_952        0xC0 // 952 Hz output, 100 Hz cutoff

// Angular rate sensor control register CTRL_REG3_G (0x12)
#define LP_DIS           0x00 // Low-power disaled (default)
#define LP_ENB           0x80 // Low-power enabled
#define HP_DIS           0x00 // High-pass filter disabled
#define HP_ENB           0x40 // High-pass filter enabled
#define HP_CUTOFF_0      0x00 // Cutoff config 0 (default)
#define HP_CUTOFF_1      0x01 // Cutoff config 0
#define HP_CUTOFF_2      0x02 // Cutoff config 0
#define HP_CUTOFF_3      0x03 // Cutoff config 0
#define HP_CUTOFF_4      0x04 // Cutoff config 0 (0.5Hz@119Hz ODR)
#define HP_CUTOFF_5      0x05 // Cutoff config 0
#define HP_CUTOFF_6      0x06 // Cutoff config 0
#define HP_CUTOFF_7      0x07 // Cutoff config 0
#define HP_CUTOFF_8      0x08 // Cutoff config 0
#define HP_CUTOFF_9      0x09 // Cutoff config 0

// Accelerometer + Gyro Bandwidth
// (See table 47 in datasheet for translation to LPF2 cutoff frequency)
#define BW_G_0           0x00 // Lowest
#define BW_G_1           0x01 // 2nd lowest
#define BW_G_2           0x02 // 2nd highest
#define BW_G_3           0x03 // Highest

// Identification information embedded in LSM9DS1 registers
#define I_AM_LSM9DS1_ACCELGYRO     0x68
#define I_AM_LSM9DS1_MAGNETOMETER  0x3D

#endif /* _lsm9ds1REGS_h_ */
