/*=======================================================================================
** File Name:  telem_r_private_types.h
**
** Title:  Type Header File for TELEM_R Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-07-30
**
** Purpose:  This header file contains declarations and definitions of all TELEM_R's private
**           data structures and data types.
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-30 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TELEM_R_PRIVATE_TYPES_H_
#define _TELEM_R_PRIVATE_TYPES_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include "cfe.h"

/*
** Local Defines
*/

/*
** Local Structure Declarations
*/

typedef struct
{
    uint8  ucCmdHeader[CFE_SB_CMD_HDR_SIZE];
} TELEM_R_NoArgCmd_t;


typedef struct
{
    uint32  counter;

    /* TODO:  Add input data to this application here, such as raw data read from I/O
    **        devices or data subscribed from other apps' output data.
    */

} TELEM_R_InData_t;

typedef struct
{
    uint8   ucTlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint32  uiCounter;
    
    float magX;
    float magY;
    float magZ;

    float accelX;
    float accelY;
    float accelZ;
} TELEM_R_OutData_t;

/* TODO:  Add more private structure definitions here, if necessary. */

/*
** External Global Variables
*/

/*
** Global Variables
*/

/*
** Local Variables
*/

/*
** Local Function Prototypes
*/

#endif /* _TELEM_R_PRIVATE_TYPES_H_ */

/*=======================================================================================
** End of file telem_r_private_types.h
**=====================================================================================*/
    
