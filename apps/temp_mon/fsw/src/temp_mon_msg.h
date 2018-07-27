/*=======================================================================================
** File Name:  temp_mon_msg.h
**
** Title:  Message Definition Header File for TEMP_MON Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  To define TEMP_MON's command and telemetry message defintions 
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TEMP_MON_MSG_H_
#define _TEMP_MON_MSG_H_

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
** TEMP_MON command codes
*/
#define TEMP_MON_NOOP_CC                 0
#define TEMP_MON_RESET_CC                1

/*
** Local Structure Declarations
*/
typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint8              usCmdCnt;
    uint8              usCmdErrCnt;

    /* TODO:  Add declarations for additional housekeeping data here */

} TEMP_MON_HkTlm_t;


#endif /* _TEMP_MON_MSG_H_ */

/*=======================================================================================
** End of file temp_mon_msg.h
**=====================================================================================*/
    