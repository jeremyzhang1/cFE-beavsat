/*=======================================================================================
** File Name:  cam_dem_private_types.h
**
** Title:  Type Header File for CAM_DEM Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-08-03
**
** Purpose:  This header file contains declarations and definitions of all CAM_DEM's private
**           data structures and data types.
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-08-03 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _CAM_DEM_PRIVATE_TYPES_H_
#define _CAM_DEM_PRIVATE_TYPES_H_

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
} CAM_DEM_NoArgCmd_t;


typedef struct
{
    uint32  counter;

    /* TODO:  Add input data to this application here, such as raw data read from I/O
    **        devices or data subscribed from other apps' output data.
    */

} CAM_DEM_InData_t;

typedef struct
{
    uint8   ucTlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint32  uiCounter;
} CAM_DEM_OutData_t;

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

#endif /* _CAM_DEM_PRIVATE_TYPES_H_ */

/*=======================================================================================
** End of file cam_dem_private_types.h
**=====================================================================================*/
    