/*=======================================================================================
** File Name:  telemetry_reader_app.h
**
** Title:  Header File for TELEMETRY_READER Application
**
** $Author:    AUSTIN COSBY
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  To define TELEMETRY_READER's internal macros, data types, global variables and
**           function prototypes
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | AUSTIN COSBY | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TELEMETRY_READER_APP_H_
#define _TELEMETRY_READER_APP_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "telemetry_reader_platform_cfg.h"
#include "telemetry_reader_mission_cfg.h"
#include "telemetry_reader_private_ids.h"
#include "telemetry_reader_private_types.h"
#include "telemetry_reader_perfids.h"
#include "telemetry_reader_msgids.h"
#include "telemetry_reader_msg.h"



/*
** Local Defines
*/
#define TELEMETRY_READER_TIMEOUT_MSEC    1000

/*
** Local Structure Declarations
*/
typedef struct
{
    /* CFE Event table */
    CFE_EVS_BinFilter_t  EventTbl[TELEMETRY_READER_EVT_CNT];

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
       Data structure should be defined in telemetry_reader/fsw/src/telemetry_reader_private_types.h */
    TELEMETRY_READER_InData_t   InData;

    /* Output data - to be published at the end of a Wakeup cycle.
       Data structure should be defined in telemetry_reader/fsw/src/telemetry_reader_private_types.h */
    TELEMETRY_READER_OutData_t  OutData;

    /* Housekeeping telemetry - for downlink only.
       Data structure should be defined in telemetry_reader/fsw/src/telemetry_reader_msg.h */
    TELEMETRY_READER_HkTlm_t  HkTlm;

    /* TODO:  Add declarations for additional private data here */
} TELEMETRY_READER_AppData_t;

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
int32  TELEMETRY_READER_InitApp(void);
int32  TELEMETRY_READER_InitEvent(void);
int32  TELEMETRY_READER_InitData(void);
int32  TELEMETRY_READER_InitPipe(void);

void  TELEMETRY_READER_AppMain(void);

void  TELEMETRY_READER_CleanupCallback(void);

int32  TELEMETRY_READER_RcvMsg(int32 iBlocking);

void  TELEMETRY_READER_ProcessNewData(void);
void  TELEMETRY_READER_ProcessNewCmds(void);
void  TELEMETRY_READER_ProcessNewAppCmds(CFE_SB_Msg_t*);

void  TELEMETRY_READER_ReportHousekeeping(void);
void  TELEMETRY_READER_SendOutData(void);

boolean  TELEMETRY_READER_VerifyCmdLength(CFE_SB_Msg_t*, uint16);

#endif /* _TELEMETRY_READER_APP_H_ */

/*=======================================================================================
** End of file telemetry_reader_app.h
**=====================================================================================*/
    