/*=======================================================================================
** File Name:  temp_mon_app.h
**
** Title:  Header File for TEMP_MON Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  To define TEMP_MON's internal macros, data types, global variables and
**           function prototypes
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TEMP_MON_APP_H_
#define _TEMP_MON_APP_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "temp_mon_platform_cfg.h"
#include "temp_mon_mission_cfg.h"
#include "temp_mon_private_ids.h"
#include "temp_mon_private_types.h"
#include "temp_mon_perfids.h"
#include "temp_mon_msgids.h"
#include "temp_mon_msg.h"



/*
** Local Defines
*/
#define TEMP_MON_TIMEOUT_MSEC    1000

/*
** Local Structure Declarations
*/
typedef struct
{
    /* CFE Event table */
    CFE_EVS_BinFilter_t  EventTbl[TEMP_MON_EVT_CNT];

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
       Data structure should be defined in temp_mon/fsw/src/temp_mon_private_types.h */
    TEMP_MON_InData_t   InData;

    /* Output data - to be published at the end of a Wakeup cycle.
       Data structure should be defined in temp_mon/fsw/src/temp_mon_private_types.h */
    TEMP_MON_OutData_t  OutData;

    /* Housekeeping telemetry - for downlink only.
       Data structure should be defined in temp_mon/fsw/src/temp_mon_msg.h */
    TEMP_MON_HkTlm_t  HkTlm;

    /* TODO:  Add declarations for additional private data here */
} TEMP_MON_AppData_t;

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
int32  TEMP_MON_InitApp(void);
int32  TEMP_MON_InitEvent(void);
int32  TEMP_MON_InitData(void);
int32  TEMP_MON_InitPipe(void);

void  TEMP_MON_AppMain(void);

void  TEMP_MON_CleanupCallback(void);

int32  TEMP_MON_RcvMsg(int32 iBlocking);

void  TEMP_MON_ProcessNewData(void);
void  TEMP_MON_ProcessNewCmds(void);
void  TEMP_MON_ProcessNewAppCmds(CFE_SB_Msg_t*);

void  TEMP_MON_ReportHousekeeping(void);
void  TEMP_MON_SendOutData(void);

boolean  TEMP_MON_VerifyCmdLength(CFE_SB_Msg_t*, uint16);

#endif /* _TEMP_MON_APP_H_ */

/*=======================================================================================
** End of file temp_mon_app.h
**=====================================================================================*/
    