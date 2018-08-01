/*********************************************************************************
*DISTRIBUTION STATEMENT A. Approved for public release. Distribution is unlimited.
*
*This material is based upon work supported under Air Force Contract No. FA8721-05-C-0002
*and/or FA8702-15-D-0001. Any opinions, findings, conclusions or recommendations
*expressed in this material are those of the author(s) and do not necessarily reflect the
*views of the U.S. Air Force.
*
*© 2018 Massachusetts Institute of Technology.
*
*The software/firmware is provided to you on an As-Is basis
*
*Delivered to the U.S. Government with Unlimited Rights, as defined in DFARS Part
*252.227-7013 or 7014 (Feb 2014). Notwithstanding any copyright notice, U.S. Government
*rights in this work are defined by DFARS 252.227-7013 or DFARS 252.227-7014 as detailed
*above. Use of this work other than as specifically authorized by the U.S. Government may
*violate any copyrights that exist in this work.
*********************************************************************************/ 
/*************************************************************************
** File:
**   $Id: lsm9ds1_lib.c $
**
** Purpose: 
**   lsm9ds1 Magnometer and Accelerometer library
**
*************************************************************************/

/*************************************************************************
** Includes
*************************************************************************/

#include "lsm9ds1_lib.h"
#include <math.h>
#include <time.h>

/*************************************************************************
** Macro Definitions
*************************************************************************/

/*************************************************************************
** Private Function Prototypes
*************************************************************************/
int32 LSM9DS1_LibInit(void);

int32 LSM9DS1_LibInit(void) {

    if (LSM9DS1_HwInit() != LSM9DS1_OK) {
        OS_printf("LSM303D Hardware Init Failed. \n");
    }
    
    return CFE_SUCCESS;

} /* End LSM9DS1_LibInit */

/************************/
/*  End of File Comment */
/************************/
