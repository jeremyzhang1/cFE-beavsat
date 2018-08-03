/*=======================================================================================
** File Name:  cam_dem_app.h
**
** Title:  Header File for CAM_DEM Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-08-03
**
** Purpose:  To define CAM_DEM's internal macros, data types, global variables and
**           function prototypes
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-08-03 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _CAM_DEM_APP_H_
#define _CAM_DEM_APP_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "cam_dem_platform_cfg.h"
#include "cam_dem_mission_cfg.h"
#include "cam_dem_private_ids.h"
#include "cam_dem_private_types.h"
#include "cam_dem_perfids.h"
#include "cam_dem_msgids.h"
#include "cam_dem_msg.h"



/*
** Local Defines
*/
#define CAM_DEM_TIMEOUT_MSEC    1000

/*
** Local Structure Declarations
*/
typedef struct
{
    /* CFE Event table */
    CFE_EVS_BinFilter_t  EventTbl[CAM_DEM_EVT_CNT];

    /* CFE scheduling pipe */
    CFE_SB_PipeId_t  SchPipeId; 
    uint16           usSchPipeDepth;
    char             cSchPipeName[OS_MAX_API_NAME];

    /* CFE command pipe */
    CFE_SB_PipeId_t  CmdPipeId;
    uint16           usCmdPipeDepth;
    char             cCmdPipeName[OS_MAX_API_NAME];
    
    /* CFE telemetry pipe */
    CFE_SB_PipeId_t  TlmPipeId;
    uint16           usTlmPipeDepth;
    char             cTlmPipeName[OS_MAX_API_NAME];

    /* Task-related */
    uint32  uiRunStatus;
    
    /* Input data - from I/O devices or subscribed from other apps' output data.
       Data structure should be defined in cam_dem/fsw/src/cam_dem_private_types.h */
    CAM_DEM_InData_t   InData;

    /* Output data - to be published at the end of a Wakeup cycle.
       Data structure should be defined in cam_dem/fsw/src/cam_dem_private_types.h */
    CAM_DEM_OutData_t  OutData;

    /* Housekeeping telemetry - for downlink only.
       Data structure should be defined in cam_dem/fsw/src/cam_dem_msg.h */
    CAM_DEM_HkTlm_t  HkTlm;

    /* TODO:  Add declarations for additional private data here */
} CAM_DEM_AppData_t;

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
int32  CAM_DEM_InitApp(void);
int32  CAM_DEM_InitEvent(void);
int32  CAM_DEM_InitData(void);
int32  CAM_DEM_InitPipe(void);

void  CAM_DEM_AppMain(void);

void  CAM_DEM_CleanupCallback(void);

int32  CAM_DEM_RcvMsg(int32 iBlocking);

void  CAM_DEM_ProcessNewData(void);
void  CAM_DEM_ProcessNewCmds(void);
void  CAM_DEM_ProcessNewAppCmds(CFE_SB_Msg_t*);

void  CAM_DEM_ReportHousekeeping(void);
void  CAM_DEM_SendOutData(void);

boolean  CAM_DEM_VerifyCmdLength(CFE_SB_Msg_t*, uint16);

#endif /* _CAM_DEM_APP_H_ */

/*=======================================================================================
** End of file cam_dem_app.h
**=====================================================================================*/
    