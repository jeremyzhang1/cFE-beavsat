/*=======================================================================================
** File Name:  safety_monitor_msg.h
**
** Title:  Message Definition Header File for SAFETY_MONITOR Application
**
** $Author:    AUSTIN COSBY
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  To define SAFETY_MONITOR's command and telemetry message defintions 
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | AUSTIN COSBY | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _SAFETY_MONITOR_MSG_H_
#define _SAFETY_MONITOR_MSG_H_

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
** SAFETY_MONITOR command codes
*/
#define SAFETY_MONITOR_NOOP_CC                 0
#define SAFETY_MONITOR_RESET_CC                1

/*
** Local Structure Declarations
*/
typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint8              usCmdCnt;
    uint8              usCmdErrCnt;

    /* TODO:  Add declarations for additional housekeeping data here */

} SAFETY_MONITOR_HkTlm_t;


#endif /* _SAFETY_MONITOR_MSG_H_ */

/*=======================================================================================
** End of file safety_monitor_msg.h
**=====================================================================================*/
    