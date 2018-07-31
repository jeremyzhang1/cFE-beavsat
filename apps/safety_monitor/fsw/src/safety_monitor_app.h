/*=======================================================================================
** File Name:  safety_monitor_app.h
**
** Title:  Header File for SAFETY_MONITOR Application
**
** $Author:    AUSTIN COSBY
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  To define SAFETY_MONITOR's internal macros, data types, global variables and
**           function prototypes
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | AUSTIN COSBY | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _SAFETY_MONITOR_APP_H_
#define _SAFETY_MONITOR_APP_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "safety_monitor_platform_cfg.h"
#include "safety_monitor_mission_cfg.h"
#include "safety_monitor_private_ids.h"
#include "safety_monitor_private_types.h"
#include "safety_monitor_perfids.h"
#include "safety_monitor_msgids.h"
#include "safety_monitor_msg.h"



/*
** Local Defines
*/
#define SAFETY_MONITOR_TIMEOUT_MSEC    1000

/*
** Local Structure Declarations
*/
typedef struct
{
    /* CFE Event table */
    CFE_EVS_BinFilter_t  EventTbl[SAFETY_MONITOR_EVT_CNT];

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
       Data structure should be defined in safety_monitor/fsw/src/safety_monitor_private_types.h */
    SAFETY_MONITOR_InData_t   InData;

    /* Output data - to be published at the end of a Wakeup cycle.
       Data structure should be defined in safety_monitor/fsw/src/safety_monitor_private_types.h */
    SAFETY_MONITOR_OutData_t  OutData;

    /* Housekeeping telemetry - for downlink only.
       Data structure should be defined in safety_monitor/fsw/src/safety_monitor_msg.h */
    SAFETY_MONITOR_HkTlm_t  HkTlm;

    /* TODO:  Add declarations for additional private data here */
} SAFETY_MONITOR_AppData_t;

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
int32  SAFETY_MONITOR_InitApp(void);
int32  SAFETY_MONITOR_InitEvent(void);
int32  SAFETY_MONITOR_InitData(void);
int32  SAFETY_MONITOR_InitPipe(void);

void  SAFETY_MONITOR_AppMain(void);

void  SAFETY_MONITOR_CleanupCallback(void);

int32  SAFETY_MONITOR_RcvMsg(int32 iBlocking);

void  SAFETY_MONITOR_ProcessNewData(void);
void  SAFETY_MONITOR_ProcessNewCmds(void);
void  SAFETY_MONITOR_ProcessNewAppCmds(CFE_SB_Msg_t*);

void  SAFETY_MONITOR_ReportHousekeeping(void);
void  SAFETY_MONITOR_SendOutData(void);

boolean  SAFETY_MONITOR_VerifyCmdLength(CFE_SB_Msg_t*, uint16);

#endif /* _SAFETY_MONITOR_APP_H_ */

/*=======================================================================================
** End of file safety_monitor_app.h
**=====================================================================================*/
    