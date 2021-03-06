/*=======================================================================================
** File Name:  temp_mon_app.c
**
** Title:  Function Definitions for TEMP_MON Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  This source file contains all necessary function definitions to run TEMP_MON
**           application.
**
** Functions Defined:
**    Function X - Brief purpose of function X
**    Function Y - Brief purpose of function Y
**    Function Z - Brief purpose of function Z
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to all functions in the file.
**    2. List the external source(s) and event(s) that can cause the funcs in this
**       file to execute.
**    3. List known limitations that apply to the funcs in this file.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/

/*
** Pragmas
*/

/*
** Include Files
*/
#include <string.h>

#include "cfe.h"

#include "temp_mon_platform_cfg.h"
#include "temp_mon_mission_cfg.h"
#include "temp_mon_app.h"

/*
** Local Defines
*/

/*
** Local Structure Declarations
*/

/*
** External Global Variables
*/

/*
** Global Variables
*/
TEMP_MON_AppData_t  g_TEMP_MON_AppData;

/*
** Local Variables
*/

/*
** Local Function Definitions
*/
    
/*=====================================================================================
** Name: TEMP_MON_InitEvent
**
** Purpose: To initialize and register event table for TEMP_MON application
**
** Arguments:
**    None
**
** Returns:
**    int32 iStatus - Status of initialization
**
** Routines Called:
**    CFE_EVS_Register
**    CFE_ES_WriteToSysLog
**
** Called By:
**    TEMP_MON_InitApp
**
** Global Inputs/Reads:
**    TBD
**
** Global Outputs/Writes:
**    g_TEMP_MON_AppData.EventTbl
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
int32 TEMP_MON_InitEvent()
{
    int32  iStatus=CFE_SUCCESS;

    /* Create the event table */
    memset((void*)g_TEMP_MON_AppData.EventTbl, 0x00, sizeof(g_TEMP_MON_AppData.EventTbl));

    g_TEMP_MON_AppData.EventTbl[0].EventID = TEMP_MON_RESERVED_EID;
    g_TEMP_MON_AppData.EventTbl[1].EventID = TEMP_MON_INF_EID;
    g_TEMP_MON_AppData.EventTbl[2].EventID = TEMP_MON_INIT_INF_EID;
    g_TEMP_MON_AppData.EventTbl[3].EventID = TEMP_MON_ILOAD_INF_EID;
    g_TEMP_MON_AppData.EventTbl[4].EventID = TEMP_MON_CDS_INF_EID;
    g_TEMP_MON_AppData.EventTbl[5].EventID = TEMP_MON_CMD_INF_EID;

    g_TEMP_MON_AppData.EventTbl[ 6].EventID = TEMP_MON_ERR_EID;
    g_TEMP_MON_AppData.EventTbl[ 7].EventID = TEMP_MON_INIT_ERR_EID;
    g_TEMP_MON_AppData.EventTbl[ 8].EventID = TEMP_MON_ILOAD_ERR_EID;
    g_TEMP_MON_AppData.EventTbl[ 9].EventID = TEMP_MON_CDS_ERR_EID;
    g_TEMP_MON_AppData.EventTbl[10].EventID = TEMP_MON_CMD_ERR_EID;
    g_TEMP_MON_AppData.EventTbl[11].EventID = TEMP_MON_PIPE_ERR_EID;
    g_TEMP_MON_AppData.EventTbl[12].EventID = TEMP_MON_MSGID_ERR_EID;
    g_TEMP_MON_AppData.EventTbl[13].EventID = TEMP_MON_MSGLEN_ERR_EID;

    /* Register the table with CFE */
    iStatus = CFE_EVS_Register(g_TEMP_MON_AppData.EventTbl,
                               TEMP_MON_EVT_CNT, CFE_EVS_BINARY_FILTER);
    if (iStatus != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("TEMP_MON - Failed to register with EVS (0x%08X)\n", iStatus);
    }

    return (iStatus);
}
    
/*=====================================================================================
** Name: TEMP_MON_InitPipe
**
** Purpose: To initialize all message pipes and subscribe to messages for TEMP_MON application
**
** Arguments:
**    None
**
** Returns:
**    int32 iStatus - Status of initialization
**
** Routines Called:
**    CFE_SB_CreatePipe
**    CFE_SB_Subscribe
**    CFE_ES_WriteToSysLog
**
** Called By:
**    TEMP_MON_InitApp
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    g_TEMP_MON_AppData.usSchPipeDepth
**    g_TEMP_MON_AppData.cSchPipeName
**    g_TEMP_MON_AppData.SchPipeId
**    g_TEMP_MON_AppData.usCmdPipeDepth
**    g_TEMP_MON_AppData.cCmdPipeName
**    g_TEMP_MON_AppData.CmdPipeId
**    g_TEMP_MON_AppData.usTlmPipeDepth
**    g_TEMP_MON_AppData.cTlmPipeName
**    g_TEMP_MON_AppData.TlmPipeId
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
int32 TEMP_MON_InitPipe()
{
    int32  iStatus=CFE_SUCCESS;

    /* Init schedule pipe */
    g_TEMP_MON_AppData.usSchPipeDepth = TEMP_MON_SCH_PIPE_DEPTH;
    memset((void*)g_TEMP_MON_AppData.cSchPipeName, '\0', sizeof(g_TEMP_MON_AppData.cSchPipeName));
    strncpy(g_TEMP_MON_AppData.cSchPipeName, "TEMP_MON_SCH_PIPE", OS_MAX_API_NAME-1);

    /* Subscribe to Wakeup messages */
    iStatus = CFE_SB_CreatePipe(&g_TEMP_MON_AppData.SchPipeId,
                                 g_TEMP_MON_AppData.usSchPipeDepth,
                                 g_TEMP_MON_AppData.cSchPipeName);
    if (iStatus == CFE_SUCCESS)
    {
        iStatus = CFE_SB_SubscribeEx(TEMP_MON_WAKEUP_MID, g_TEMP_MON_AppData.SchPipeId, CFE_SB_Default_Qos, 1);

        if (iStatus != CFE_SUCCESS)
        {
            CFE_ES_WriteToSysLog("TEMP_MON - Sch Pipe failed to subscribe to TEMP_MON_WAKEUP_MID. (0x%08X)\n", iStatus);
            goto TEMP_MON_InitPipe_Exit_Tag;
        }
        
    }
    else
    {
        CFE_ES_WriteToSysLog("TEMP_MON - Failed to create SCH pipe (0x%08X)\n", iStatus);
        goto TEMP_MON_InitPipe_Exit_Tag;
    }

    /* Init command pipe */
    g_TEMP_MON_AppData.usCmdPipeDepth = TEMP_MON_CMD_PIPE_DEPTH ;
    memset((void*)g_TEMP_MON_AppData.cCmdPipeName, '\0', sizeof(g_TEMP_MON_AppData.cCmdPipeName));
    strncpy(g_TEMP_MON_AppData.cCmdPipeName, "TEMP_MON_CMD_PIPE", OS_MAX_API_NAME-1);

    /* Subscribe to command messages */
    iStatus = CFE_SB_CreatePipe(&g_TEMP_MON_AppData.CmdPipeId,
                                 g_TEMP_MON_AppData.usCmdPipeDepth,
                                 g_TEMP_MON_AppData.cCmdPipeName);
    if (iStatus == CFE_SUCCESS)
    {
        /* Subscribe to command messages */
        iStatus = CFE_SB_Subscribe(TEMP_MON_CMD_MID, g_TEMP_MON_AppData.CmdPipeId);

        if (iStatus != CFE_SUCCESS)
        {
            CFE_ES_WriteToSysLog("TEMP_MON - CMD Pipe failed to subscribe to TEMP_MON_CMD_MID. (0x%08X)\n", iStatus);
            goto TEMP_MON_InitPipe_Exit_Tag;
        }

        iStatus = CFE_SB_Subscribe(TEMP_MON_SEND_HK_MID, g_TEMP_MON_AppData.CmdPipeId);

        if (iStatus != CFE_SUCCESS)
        {
            CFE_ES_WriteToSysLog("TEMP_MON - CMD Pipe failed to subscribe to TEMP_MON_SEND_HK_MID. (0x%08X)\n", iStatus);
            goto TEMP_MON_InitPipe_Exit_Tag;
        }
        
    }
    else
    {
        CFE_ES_WriteToSysLog("TEMP_MON - Failed to create CMD pipe (0x%08X)\n", iStatus);
        goto TEMP_MON_InitPipe_Exit_Tag;
    }

    /* Init telemetry pipe */
    g_TEMP_MON_AppData.usTlmPipeDepth = TEMP_MON_TLM_PIPE_DEPTH;
    memset((void*)g_TEMP_MON_AppData.cTlmPipeName, '\0', sizeof(g_TEMP_MON_AppData.cTlmPipeName));
    strncpy(g_TEMP_MON_AppData.cTlmPipeName, "TEMP_MON_TLM_PIPE", OS_MAX_API_NAME-1);

    /* Subscribe to telemetry messages on the telemetry pipe */
    iStatus = CFE_SB_CreatePipe(&g_TEMP_MON_AppData.TlmPipeId,
                                 g_TEMP_MON_AppData.usTlmPipeDepth,
                                 g_TEMP_MON_AppData.cTlmPipeName);
    if (iStatus == CFE_SUCCESS)
    {
        /* TODO:  Add CFE_SB_Subscribe() calls for other apps' output data here.
        **
        ** Examples:
        **     CFE_SB_Subscribe(GNCEXEC_OUT_DATA_MID, g_TEMP_MON_AppData.TlmPipeId);
        */
    }
    else
    {
        CFE_ES_WriteToSysLog("TEMP_MON - Failed to create TLM pipe (0x%08X)\n", iStatus);
        goto TEMP_MON_InitPipe_Exit_Tag;
    }

TEMP_MON_InitPipe_Exit_Tag:
    return (iStatus);
}
    
/*=====================================================================================
** Name: TEMP_MON_InitData
**
** Purpose: To initialize global variables used by TEMP_MON application
**
** Arguments:
**    None
**
** Returns:
**    int32 iStatus - Status of initialization
**
** Routines Called:
**    CFE_SB_InitMsg
**
** Called By:
**    TEMP_MON_InitApp
**
** Global Inputs/Reads:
**    TBD
**
** Global Outputs/Writes:
**    g_TEMP_MON_AppData.InData
**    g_TEMP_MON_AppData.OutData
**    g_TEMP_MON_AppData.HkTlm
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
int32 TEMP_MON_InitData()
{
    int32  iStatus=CFE_SUCCESS;

    /* Init input data */
    memset((void*)&g_TEMP_MON_AppData.InData, 0x00, sizeof(g_TEMP_MON_AppData.InData));

    /* Init output data */
    memset((void*)&g_TEMP_MON_AppData.OutData, 0x00, sizeof(g_TEMP_MON_AppData.OutData));
    CFE_SB_InitMsg(&g_TEMP_MON_AppData.OutData,
                   TEMP_MON_OUT_DATA_MID, sizeof(g_TEMP_MON_AppData.OutData), TRUE);

    /* Init housekeeping packet */
    memset((void*)&g_TEMP_MON_AppData.HkTlm, 0x00, sizeof(g_TEMP_MON_AppData.HkTlm));
    CFE_SB_InitMsg(&g_TEMP_MON_AppData.HkTlm,
                   TEMP_MON_HK_TLM_MID, sizeof(g_TEMP_MON_AppData.HkTlm), TRUE);

    return (iStatus);
}
    
/*=====================================================================================
** Name: TEMP_MON_InitApp
**
** Purpose: To initialize all data local to and used by TEMP_MON application
**
** Arguments:
**    None
**
** Returns:
**    int32 iStatus - Status of initialization
**
** Routines Called:
**    CFE_ES_RegisterApp
**    CFE_ES_WriteToSysLog
**    CFE_EVS_SendEvent
**    OS_TaskInstallDeleteHandler
**    TEMP_MON_InitEvent
**    TEMP_MON_InitPipe
**    TEMP_MON_InitData
**
** Called By:
**    TEMP_MON_AppMain
**
** Global Inputs/Reads:
**    TBD
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
int32 TEMP_MON_InitApp()
{
    int32  iStatus=CFE_SUCCESS;

    g_TEMP_MON_AppData.uiRunStatus = CFE_ES_APP_RUN;

    iStatus = CFE_ES_RegisterApp();
    if (iStatus != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("TEMP_MON - Failed to register the app (0x%08X)\n", iStatus);
        goto TEMP_MON_InitApp_Exit_Tag;
    }

    if ((TEMP_MON_InitEvent() != CFE_SUCCESS) || 
        (TEMP_MON_InitPipe() != CFE_SUCCESS) || 
        (TEMP_MON_InitData() != CFE_SUCCESS))
    {
        iStatus = -1;
        goto TEMP_MON_InitApp_Exit_Tag;
    }

    /* Install the cleanup callback */
    OS_TaskInstallDeleteHandler((void*)&TEMP_MON_CleanupCallback);

TEMP_MON_InitApp_Exit_Tag:
    if (iStatus == CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(TEMP_MON_INIT_INF_EID, CFE_EVS_INFORMATION,
                          "TEMP_MON - Application initialized");
    }
    else
    {
        CFE_ES_WriteToSysLog("TEMP_MON - Application failed to initialize\n");
    }

    return (iStatus);
}
    
/*=====================================================================================
** Name: TEMP_MON_CleanupCallback
**
** Purpose: To handle any neccesary cleanup prior to application exit
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    TBD
**
** Called By:
**    TBD
**
** Global Inputs/Reads:
**    TBD
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void TEMP_MON_CleanupCallback()
{
    /* TODO:  Add code to cleanup memory and other cleanup here */
}
    
/*=====================================================================================
** Name: TEMP_MON_RcvMsg
**
** Purpose: To receive and process messages for TEMP_MON application
**
** Arguments:
**    None
**
** Returns:
**    int32 iStatus - Status of initialization 
**
** Routines Called:
**    CFE_SB_RcvMsg
**    CFE_SB_GetMsgId
**    CFE_EVS_SendEvent
**    CFE_ES_PerfLogEntry
**    CFE_ES_PerfLogExit
**    TEMP_MON_ProcessNewCmds
**    TEMP_MON_ProcessNewData
**    TEMP_MON_SendOutData
**
** Called By:
**    TEMP_MON_Main
**
** Global Inputs/Reads:
**    g_TEMP_MON_AppData.SchPipeId
**
** Global Outputs/Writes:
**    g_TEMP_MON_AppData.uiRunStatus
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
int32 TEMP_MON_RcvMsg(int32 iBlocking)
{
    int32           iStatus=CFE_SUCCESS;
    CFE_SB_Msg_t*   MsgPtr=NULL;
    CFE_SB_MsgId_t  MsgId;

    /* Stop Performance Log entry */
    CFE_ES_PerfLogExit(TEMP_MON_MAIN_TASK_PERF_ID);

    /* Wait for WakeUp messages from scheduler */
    iStatus = CFE_SB_RcvMsg(&MsgPtr, g_TEMP_MON_AppData.SchPipeId, iBlocking);

    /* Start Performance Log entry */
    CFE_ES_PerfLogEntry(TEMP_MON_MAIN_TASK_PERF_ID);

    if (iStatus == CFE_SUCCESS)
    {
        MsgId = CFE_SB_GetMsgId(MsgPtr);
        switch (MsgId)
	{
            case TEMP_MON_WAKEUP_MID:
                TEMP_MON_ProcessNewCmds();
                TEMP_MON_ProcessNewData();

                /* TODO:  Add more code here to handle other things when app wakes up */

                /* The last thing to do at the end of this Wakeup cycle should be to
                   automatically publish new output. */
                TEMP_MON_SendOutData();
                break;

            default:
                CFE_EVS_SendEvent(TEMP_MON_MSGID_ERR_EID, CFE_EVS_ERROR,
                                  "TEMP_MON - Recvd invalid SCH msgId (0x%08X)", MsgId);
        }
    }
    else if (iStatus == CFE_SB_NO_MESSAGE)
    {
        /* If there's no incoming message, you can do something here, or nothing */
    }
    else
    {
        /* This is an example of exiting on an error.
        ** Note that a SB read error is not always going to result in an app quitting.
        */
        CFE_EVS_SendEvent(TEMP_MON_PIPE_ERR_EID, CFE_EVS_ERROR,
			  "TEMP_MON: SB pipe read error (0x%08X), app will exit", iStatus);
        g_TEMP_MON_AppData.uiRunStatus= CFE_ES_APP_ERROR;
    }

    return (iStatus);
}
    
/*=====================================================================================
** Name: TEMP_MON_ProcessNewData
**
** Purpose: To process incoming data subscribed by TEMP_MON application
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    CFE_SB_RcvMsg
**    CFE_SB_GetMsgId
**    CFE_EVS_SendEvent
**
** Called By:
**    TEMP_MON_RcvMsg
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    None
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void TEMP_MON_ProcessNewData()
{
    int iStatus = CFE_SUCCESS;
    CFE_SB_Msg_t*   TlmMsgPtr=NULL;
    CFE_SB_MsgId_t  TlmMsgId;

    /* Process telemetry messages till the pipe is empty */
    while (1)
    {
        iStatus = CFE_SB_RcvMsg(&TlmMsgPtr, g_TEMP_MON_AppData.TlmPipeId, CFE_SB_POLL);
        if (iStatus == CFE_SUCCESS)
        {
            TlmMsgId = CFE_SB_GetMsgId(TlmMsgPtr);
            switch (TlmMsgId)
            {
                /* TODO:  Add code to process all subscribed data here 
                **
                ** Example:
                **     case NAV_OUT_DATA_MID:
                **         TEMP_MON_ProcessNavData(TlmMsgPtr);
                **         break;
                */

                default:
                    CFE_EVS_SendEvent(TEMP_MON_MSGID_ERR_EID, CFE_EVS_ERROR,
                                      "TEMP_MON - Recvd invalid TLM msgId (0x%08X)", TlmMsgId);
                    break;
            }
        }
        else if (iStatus == CFE_SB_NO_MESSAGE)
        {
            break;
        }
        else
        {
            CFE_EVS_SendEvent(TEMP_MON_PIPE_ERR_EID, CFE_EVS_ERROR,
                  "TEMP_MON: CMD pipe read error (0x%08X)", iStatus);
            g_TEMP_MON_AppData.uiRunStatus = CFE_ES_APP_ERROR;
            break;
        }
    }
}
    
/*=====================================================================================
** Name: TEMP_MON_ProcessNewCmds
**
** Purpose: To process incoming command messages for TEMP_MON application
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    CFE_SB_RcvMsg
**    CFE_SB_GetMsgId
**    CFE_EVS_SendEvent
**    TEMP_MON_ProcessNewAppCmds
**    TEMP_MON_ReportHousekeeping
**
** Called By:
**    TEMP_MON_RcvMsg
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    None
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void TEMP_MON_ProcessNewCmds()
{
    int iStatus = CFE_SUCCESS;
    CFE_SB_Msg_t*   CmdMsgPtr=NULL;
    CFE_SB_MsgId_t  CmdMsgId;

    /* Process command messages till the pipe is empty */
    while (1)
    {
        iStatus = CFE_SB_RcvMsg(&CmdMsgPtr, g_TEMP_MON_AppData.CmdPipeId, CFE_SB_POLL);
        if(iStatus == CFE_SUCCESS)
        {
            CmdMsgId = CFE_SB_GetMsgId(CmdMsgPtr);
            switch (CmdMsgId)
            {
                case TEMP_MON_CMD_MID:
                    TEMP_MON_ProcessNewAppCmds(CmdMsgPtr);
                    break;

                case TEMP_MON_SEND_HK_MID:
                    TEMP_MON_ReportHousekeeping();
                    break;

                /* TODO:  Add code to process other subscribed commands here
                **
                ** Example:
                **     case CFE_TIME_DATA_CMD_MID:
                **         TEMP_MON_ProcessTimeDataCmd(CmdMsgPtr);
                **         break;
                */

                default:
                    CFE_EVS_SendEvent(TEMP_MON_MSGID_ERR_EID, CFE_EVS_ERROR,
                                      "TEMP_MON - Recvd invalid CMD msgId (0x%08X)", CmdMsgId);
                    break;
            }
        }
        else if (iStatus == CFE_SB_NO_MESSAGE)
        {
            break;
        }
        else
        {
            CFE_EVS_SendEvent(TEMP_MON_PIPE_ERR_EID, CFE_EVS_ERROR,
                  "TEMP_MON: CMD pipe read error (0x%08X)", iStatus);
            g_TEMP_MON_AppData.uiRunStatus = CFE_ES_APP_ERROR;
            break;
        }
    }
}
    
/*=====================================================================================
** Name: TEMP_MON_ProcessNewAppCmds
**
** Purpose: To process command messages targeting TEMP_MON application
**
** Arguments:
**    CFE_SB_Msg_t*  MsgPtr - new command message pointer
**
** Returns:
**    None
**
** Routines Called:
**    CFE_SB_GetCmdCode
**    CFE_EVS_SendEvent
**
** Called By:
**    TEMP_MON_ProcessNewCmds
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    g_TEMP_MON_AppData.HkTlm.usCmdCnt
**    g_TEMP_MON_AppData.HkTlm.usCmdErrCnt
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void TEMP_MON_ProcessNewAppCmds(CFE_SB_Msg_t* MsgPtr)
{
    uint32  uiCmdCode=0;

    if (MsgPtr != NULL)
    {
        uiCmdCode = CFE_SB_GetCmdCode(MsgPtr);
        switch (uiCmdCode)
        {
            case TEMP_MON_NOOP_CC:
                g_TEMP_MON_AppData.HkTlm.usCmdCnt++;
                CFE_EVS_SendEvent(TEMP_MON_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "TEMP_MON - Recvd NOOP cmd (%d)", uiCmdCode);
                break;

            case TEMP_MON_RESET_CC:
                g_TEMP_MON_AppData.HkTlm.usCmdCnt = 0;
                g_TEMP_MON_AppData.HkTlm.usCmdErrCnt = 0;
                CFE_EVS_SendEvent(TEMP_MON_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "TEMP_MON - Recvd RESET cmd (%d)", uiCmdCode);
                break;

            /* TODO:  Add code to process the rest of the TEMP_MON commands here */

            default:
                g_TEMP_MON_AppData.HkTlm.usCmdErrCnt++;
                CFE_EVS_SendEvent(TEMP_MON_MSGID_ERR_EID, CFE_EVS_ERROR,
                                  "TEMP_MON - Recvd invalid cmdId (%d)", uiCmdCode);
                break;
        }
    }
}
    
/*=====================================================================================
** Name: TEMP_MON_ReportHousekeeping
**
** Purpose: To send housekeeping message
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    TBD
**
** Called By:
**    TEMP_MON_ProcessNewCmds
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  GSFC, Austin Cosby
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void TEMP_MON_ReportHousekeeping()
{
    /* TODO:  Add code to update housekeeping data, if needed, here.  */

    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&g_TEMP_MON_AppData.HkTlm);
    CFE_SB_SendMsg((CFE_SB_Msg_t*)&g_TEMP_MON_AppData.HkTlm);
}
    
/*=====================================================================================
** Name: TEMP_MON_SendOutData
**
** Purpose: To publish 1-Wakeup cycle output data
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    TBD
**
** Called By:
**    TEMP_MON_RcvMsg
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void TEMP_MON_SendOutData()
{
    /* TODO:  Add code to update output data, if needed, here.  */

    CFE_SB_TimeStampMsg((CFE_SB_Msg_t*)&g_TEMP_MON_AppData.OutData);
    CFE_SB_SendMsg((CFE_SB_Msg_t*)&g_TEMP_MON_AppData.OutData);
}
    
/*=====================================================================================
** Name: TEMP_MON_VerifyCmdLength
**
** Purpose: To verify command length for a particular command message
**
** Arguments:
**    CFE_SB_Msg_t*  MsgPtr      - command message pointer
**    uint16         usExpLength - expected command length
**
** Returns:
**    boolean bResult - result of verification
**
** Routines Called:
**    TBD
**
** Called By:
**    TEMP_MON_ProcessNewCmds
**
** Global Inputs/Reads:
**    None
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
boolean TEMP_MON_VerifyCmdLength(CFE_SB_Msg_t* MsgPtr,
                           uint16 usExpectedLen)
{
    boolean bResult=FALSE;
    uint16  usMsgLen=0;

    if (MsgPtr != NULL)
    {
        usMsgLen = CFE_SB_GetTotalMsgLength(MsgPtr);

        if (usExpectedLen != usMsgLen)
        {
            CFE_SB_MsgId_t MsgId = CFE_SB_GetMsgId(MsgPtr);
            uint16 usCmdCode = CFE_SB_GetCmdCode(MsgPtr);

            CFE_EVS_SendEvent(TEMP_MON_MSGLEN_ERR_EID, CFE_EVS_ERROR,
                              "TEMP_MON - Rcvd invalid msgLen: msgId=0x%08X, cmdCode=%d, "
                              "msgLen=%d, expectedLen=%d",
                              MsgId, usCmdCode, usMsgLen, usExpectedLen);
            g_TEMP_MON_AppData.HkTlm.usCmdErrCnt++;
        }
    }

    return (bResult);
}
    
/*=====================================================================================
** Name: TEMP_MON_AppMain
**
** Purpose: To define TEMP_MON application's entry point and main process loop
**
** Arguments:
**    None
**
** Returns:
**    None
**
** Routines Called:
**    CFE_ES_RegisterApp
**    CFE_ES_RunLoop
**    CFE_ES_PerfLogEntry
**    CFE_ES_PerfLogExit
**    CFE_ES_ExitApp
**    CFE_ES_WaitForStartupSync
**    TEMP_MON_InitApp
**    TEMP_MON_RcvMsg
**
** Called By:
**    TBD
**
** Global Inputs/Reads:
**    TBD
**
** Global Outputs/Writes:
**    TBD
**
** Limitations, Assumptions, External Events, and Notes:
**    1. List assumptions that are made that apply to this function.
**    2. List the external source(s) and event(s) that can cause this function to execute.
**    3. List known limitations that apply to this function.
**    4. If there are no assumptions, external events, or notes then enter NONE.
**       Do not omit the section.
**
** Algorithm:
**    Psuedo-code or description of basic algorithm
**
** Author(s):  Austin Cosby 
**
** History:  Date Written  2018-07-27
**           Unit Tested   yyyy-mm-dd
**=====================================================================================*/
void TEMP_MON_AppMain()
{
    /* Register the application with Executive Services */
    CFE_ES_RegisterApp();

    /* Start Performance Log entry */
    CFE_ES_PerfLogEntry(TEMP_MON_MAIN_TASK_PERF_ID);

    /* Perform application initializations */
    if (TEMP_MON_InitApp() != CFE_SUCCESS)
    {
        g_TEMP_MON_AppData.uiRunStatus = CFE_ES_APP_ERROR;
    } else {
        /* Do not perform performance monitoring on startup sync */
        CFE_ES_PerfLogExit(TEMP_MON_MAIN_TASK_PERF_ID);
        CFE_ES_WaitForStartupSync(TEMP_MON_TIMEOUT_MSEC);
        CFE_ES_PerfLogEntry(TEMP_MON_MAIN_TASK_PERF_ID);
    }

    /* Application main loop */
    while (CFE_ES_RunLoop(&g_TEMP_MON_AppData.uiRunStatus) == TRUE)
    {
        TEMP_MON_RcvMsg(CFE_SB_PEND_FOREVER);
    }

    /* Stop Performance Log entry */
    CFE_ES_PerfLogExit(TEMP_MON_MAIN_TASK_PERF_ID);

    /* Exit the application */
    CFE_ES_ExitApp(g_TEMP_MON_AppData.uiRunStatus);
} 
    
/*=======================================================================================
** End of file temp_mon_app.c
**=====================================================================================*/
    