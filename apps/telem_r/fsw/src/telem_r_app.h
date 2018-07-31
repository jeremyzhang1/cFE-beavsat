/*=======================================================================================
** File Name:  telem_r_app.h
**
** Title:  Header File for TELEM_R Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-07-30
**
** Purpose:  To define TELEM_R's internal macros, data types, global variables and
**           function prototypes
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-30 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TELEM_R_APP_H_
#define _TELEM_R_APP_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "telem_r_platform_cfg.h"
#include "telem_r_mission_cfg.h"
#include "telem_r_private_ids.h"
#include "telem_r_private_types.h"
#include "telem_r_perfids.h"
#include "telem_r_msgids.h"
#include "telem_r_msg.h"



/*
** Local Defines
*/
#define TELEM_R_TIMEOUT_MSEC    1000

/*
** Local Structure Declarations
*/
typedef struct
{
    /* CFE Event table */
    CFE_EVS_BinFilter_t  EventTbl[TELEM_R_EVT_CNT];

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
       Data structure should be defined in telem_r/fsw/src/telem_r_private_types.h */
    TELEM_R_InData_t   InData;

    /* Output data - to be published at the end of a Wakeup cycle.
       Data structure should be defined in telem_r/fsw/src/telem_r_private_types.h */
    TELEM_R_OutData_t  OutData;

    /* Housekeeping telemetry - for downlink only.
       Data structure should be defined in telem_r/fsw/src/telem_r_msg.h */
    TELEM_R_HkTlm_t  HkTlm;

    /* TODO:  Add declarations for additional private data here */
} TELEM_R_AppData_t;

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
int32  TELEM_R_InitApp(void);
int32  TELEM_R_InitEvent(void);
int32  TELEM_R_InitData(void);
int32  TELEM_R_InitPipe(void);

void  TELEM_R_AppMain(void);

void  TELEM_R_CleanupCallback(void);

int32  TELEM_R_RcvMsg(int32 iBlocking);

void  TELEM_R_ProcessNewData(void);
void  TELEM_R_ProcessNewCmds(void);
void  TELEM_R_ProcessNewAppCmds(CFE_SB_Msg_t*);

void  TELEM_R_ReportHousekeeping(void);
void  TELEM_R_SendOutData(void);

boolean  TELEM_R_VerifyCmdLength(CFE_SB_Msg_t*, uint16);

#endif /* _TELEM_R_APP_H_ */

/*=======================================================================================
** End of file telem_r_app.h
**=====================================================================================*/
    
