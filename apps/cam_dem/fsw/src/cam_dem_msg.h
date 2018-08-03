/*=======================================================================================
** File Name:  cam_dem_msg.h
**
** Title:  Message Definition Header File for CAM_DEM Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-08-03
**
** Purpose:  To define CAM_DEM's command and telemetry message defintions 
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-08-03 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _CAM_DEM_MSG_H_
#define _CAM_DEM_MSG_H_

/*
** Pragmas
*/

/*
** Include Files
*/



/*
** Local Defines
*/

/*
** CAM_DEM command codes
*/
#define CAM_DEM_NOOP_CC                 0
#define CAM_DEM_RESET_CC                1

/*
** Local Structure Declarations
*/
typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint8              usCmdCnt;
    uint8              usCmdErrCnt;

    /* TODO:  Add declarations for additional housekeeping data here */

} CAM_DEM_HkTlm_t;


#endif /* _CAM_DEM_MSG_H_ */

/*=======================================================================================
** End of file cam_dem_msg.h
**=====================================================================================*/
    