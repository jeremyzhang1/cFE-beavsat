/*=======================================================================================
** File Name:  telemetry_reader_msg.h
**
** Title:  Message Definition Header File for TELEMETRY_READER Application
**
** $Author:    AUSTIN COSBY
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  To define TELEMETRY_READER's command and telemetry message defintions 
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | AUSTIN COSBY | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TELEMETRY_READER_MSG_H_
#define _TELEMETRY_READER_MSG_H_

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
** TELEMETRY_READER command codes
*/
#define TELEMETRY_READER_NOOP_CC                 0
#define TELEMETRY_READER_RESET_CC                1

/*
** Local Structure Declarations
*/
typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint8              usCmdCnt;
    uint8              usCmdErrCnt;

    /* TODO:  Add declarations for additional housekeeping data here */

} TELEMETRY_READER_HkTlm_t;


#endif /* _TELEMETRY_READER_MSG_H_ */

/*=======================================================================================
** End of file telemetry_reader_msg.h
**=====================================================================================*/
    
