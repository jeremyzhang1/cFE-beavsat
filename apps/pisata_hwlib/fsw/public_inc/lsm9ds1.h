/*! \file lms9ds1.h
* lms9ds1 Magnetometer and Accelerometer library
*
* \author	Ken Gregson
* \version	0.1
* \date		2018 
* \copyright	©2018, Ken Gregson, released under MIT License
*/

#ifndef _lsm9ds1_h_
#define _lsm9ds1_h_

// Local error/success return codes
#define LSM9DS1_OK 0
#define LSM9DS1_FAIL -1

//struct representing a vector
typedef struct {
    float x;
    float y;
    float z;

} LSM9DS1_Vector_t;

extern int LSM9DS1_HwInit(void);
extern LSM9DS1_Vector_t LSM9DS1_GetMagData(void);
extern LSM9DS1_Vector_t LSM9DS1_GetAccelData(void);
extern LSM9DS1_Vector_t LSM9DS1_GetGyroData(void);

#endif /* _lsm9ds1_h_ */

