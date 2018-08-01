/*! \file lms9ds1.c
* lms9ds1 Magnetometer and Accelerometer library
*
* \author	Ken Gregson
* \version	0.1
* \date		2018 
* \copyright	©2018, Ken Gregson, released under MIT License
*/

#include <unistd.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include "wiringPi.h"
#include "wiringPiI2C.h"
#include "lsm9ds1REGS.h"
#include "lsm9ds1.h"

// This needs to be teleported to create a CFE specific application
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Library Initialization Routine                                  */
/* cFE requires that a library have an initialization routine      */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*
int32 LSM9DS1_LibInit(void) {
    
    if (LMS9DS1_HwInit() != CFE_SUCCESS) {
        OS_printf("LSM9DS1 Hardware Init Failed. \n");
    }
    
    return CFE_SUCCESS;
}
*/

// Library "global" scale factors (unscaled for now)
static double FULLSCALE_MAG = 1.0F;
static double FULLSCALE_GYRO = 1.0F;
static double FULLSCALE_ACCEL = 1.0F;

int LSM9DS1_HwInit(void) {
    // Open accelerometer/gyro and verify device ID
    int accelgyro_fd =  wiringPiI2CSetup(ACCELGYRO_ADDR);
    if (accelgyro_fd < 0) { return LSM9DS1_FAIL; }

    int whoami = wiringPiI2CReadReg8(accelgyro_fd, WHO_AM_I);
    if (whoami != I_AM_LSM9DS1_ACCELGYRO) { return LSM9DS1_FAIL; };

    /* Enable both Gyro and Accelerometer:
    *  Output data rate 119 Hz, Cutoff 31 Hz
    *  Gyro full scale: 500 dps, Accelerometer full scale: 8G
    */
    wiringPiI2CWriteReg8(accelgyro_fd, CTRL_REG1_G, ODR_G_119|FS_G_500|BW_G_1);
    wiringPiI2CWriteReg8(accelgyro_fd, CTRL_REG3_G, HP_ENB|HP_CUTOFF_4);
    wiringPiI2CWriteReg8(accelgyro_fd, CTRL_REG6_XL, ODR_XL_119|FS_XL_8|BW_XL_50);
    wiringPiI2CWriteReg8(accelgyro_fd, CTRL_REG7_XL, 0x0); // seems unnecessary

    close(accelgyro_fd);

    // Open magnetometer device and verify device ID
    int mag_fd = wiringPiI2CSetup(MAG_ADDR);
    if (mag_fd < 0) { return LSM9DS1_FAIL; }

    int whoami_m = wiringPiI2CReadReg8(mag_fd, WHO_AM_I_M);
    if (whoami_m != I_AM_LSM9DS1_MAGNETOMETER) { return LSM9DS1_FAIL; }

    /* Enable Magnetometer:
    *  Output data rate 20 Hz
    *  Full scale +/- 4 gauss
    *  Continuous conversion operating mode
    */
    wiringPiI2CWriteReg8(mag_fd, CTRL_REG1_M, ODR_M_20);
    wiringPiI2CWriteReg8(mag_fd, CTRL_REG2_M, FS_M_4);
    wiringPiI2CWriteReg8(mag_fd, CTRL_REG3_M, MD_M_CONTINUOUS);

    close(mag_fd);

    return LSM9DS1_OK;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* LSM9DS1 Lib functions                                           */
/*                                                                 */
/* * * * * * *** * * * * * * * * * * * * * * * * * * * * * * * * * */

//returns magnetometer vector
LSM9DS1_Vector_t LSM9DS1_GetMagData(void) {

    LSM9DS1_Vector_t mdata;
    
    int mag_fd =  wiringPiI2CSetup(MAG_ADDR);
    int mx = (int16_t)(wiringPiI2CReadReg8(mag_fd, OUT_X_L_M) |
        wiringPiI2CReadReg8(mag_fd, OUT_X_H_M) << 8);
    int my = (int16_t)(wiringPiI2CReadReg8(mag_fd, OUT_Y_L_M) |
        wiringPiI2CReadReg8(mag_fd, OUT_Y_H_M) << 8);
    int mz = (int16_t)(wiringPiI2CReadReg8(mag_fd, OUT_Z_L_M) |
        wiringPiI2CReadReg8(mag_fd, OUT_Z_H_M) << 8);

    //scale raw data to gauss (4 gauss full scale)
    // return raw data for now
    mdata.x = mx * FULLSCALE_MAG;
    mdata.y = my * FULLSCALE_MAG;
    mdata.z = mz * FULLSCALE_MAG;
    
    close(mag_fd);

    return mdata;
} /* End LSM9DS1_GetMagData */

//returns accelerometer data
LSM9DS1_Vector_t LSM9DS1_GetAccelData(void) {

    LSM9DS1_Vector_t adata;

    int accel_fd =  wiringPiI2CSetup(ACCELGYRO_ADDR);
    int ax = (int16_t)(wiringPiI2CReadReg8(accel_fd, OUT_X_H_XL) << 8 |
        wiringPiI2CReadReg8(accel_fd, OUT_X_L_XL));
    int ay = (int16_t)(wiringPiI2CReadReg8(accel_fd, OUT_Y_H_XL) << 8 |
        wiringPiI2CReadReg8(accel_fd, OUT_Y_L_XL));
    int az = (int16_t)(wiringPiI2CReadReg8(accel_fd, OUT_Z_H_XL) << 8 |
         wiringPiI2CReadReg8(accel_fd, OUT_Z_L_XL));

    //scale raw data to Gs (8 Gs full scale)
    // return raw data for now
    adata.x = ax * FULLSCALE_ACCEL;
    adata.y = ay * FULLSCALE_ACCEL;
    adata.z = az * FULLSCALE_ACCEL;
    
    close(accel_fd);
    
    return adata;
} /* End LSM9DS1_GetAccelData */

//returns gyroscope data 
LSM9DS1_Vector_t LSM9DS1_GetGyroData(void) {

    LSM9DS1_Vector_t gdata;

    int gyro_fd =  wiringPiI2CSetup(ACCELGYRO_ADDR);
    int gx = (int16_t)(wiringPiI2CReadReg8(gyro_fd, OUT_X_H_G) << 8 |
        wiringPiI2CReadReg8(gyro_fd, OUT_X_L_G));
    int gy = (int16_t)(wiringPiI2CReadReg8(gyro_fd, OUT_Y_H_G) << 8 |
        wiringPiI2CReadReg8(gyro_fd, OUT_Y_L_G));
    int gz = (int16_t)(wiringPiI2CReadReg8(gyro_fd, OUT_Z_H_G) << 8 |
         wiringPiI2CReadReg8(gyro_fd, OUT_Z_L_G));

    //scale raw data to dps (500 dps full scale)
    // return raw data for now
    gdata.x = gx * FULLSCALE_GYRO;
    gdata.y = gy * FULLSCALE_GYRO;
    gdata.z = gz * FULLSCALE_GYRO;
    
    close(gyro_fd);
    
    return gdata;
} /* End LSM9DS1_GetGyroData */
