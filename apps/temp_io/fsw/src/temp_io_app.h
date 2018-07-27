/*=======================================================================================
** File Name:  temp_io_app.h
**
** Title:  Header File for TEMP_IO Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  To define TEMP_IO's internal macros, data types, global variables and
**           function prototypes
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TEMP_IO_APP_H_
#define _TEMP_IO_APP_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "temp_io_platform_cfg.h"
#include "temp_io_mission_cfg.h"
#include "temp_io_private_ids.h"
#include "temp_io_private_types.h"
#include "temp_io_perfids.h"
#include "temp_io_msgids.h"
#include "temp_io_msg.h"



/*
** Local Defines
*/
#define TEMP_IO_TIMEOUT_MSEC    1000

/*
** Local Structure Declarations
*/
typedef struct
{
    /* CFE Event table */
    CFE_EVS_BinFilter_t  EventTbl[TEMP_IO_EVT_CNT];

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
       Data structure should be defined in temp_io/fsw/src/temp_io_private_types.h */
    TEMP_IO_InData_t   InData;

    /* Output data - to be published at the end of a Wakeup cycle.
       Data structure should be defined in temp_io/fsw/src/temp_io_private_types.h */
    TEMP_IO_OutData_t  OutData;

    /* Housekeeping telemetry - for downlink only.
       Data structure should be defined in temp_io/fsw/src/temp_io_msg.h */
    TEMP_IO_HkTlm_t  HkTlm;

    /* TODO:  Add declarations for additional private data here */
} TEMP_IO_AppData_t;

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
int32  TEMP_IO_InitApp(void);
int32  TEMP_IO_InitEvent(void);
int32  TEMP_IO_InitData(void);
int32  TEMP_IO_InitPipe(void);

void  TEMP_IO_AppMain(void);

void  TEMP_IO_CleanupCallback(void);

int32  TEMP_IO_RcvMsg(int32 iBlocking);

void  TEMP_IO_ProcessNewData(void);
void  TEMP_IO_ProcessNewCmds(void);
void  TEMP_IO_ProcessNewAppCmds(CFE_SB_Msg_t*);

void  TEMP_IO_ReportHousekeeping(void);
void  TEMP_IO_SendOutData(void);

boolean  TEMP_IO_VerifyCmdLength(CFE_SB_Msg_t*, uint16);

#endif /* _TEMP_IO_APP_H_ */

/*=======================================================================================
** End of file temp_io_app.h
**=====================================================================================*/
    