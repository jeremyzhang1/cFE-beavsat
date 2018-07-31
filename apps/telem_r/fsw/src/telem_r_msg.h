/*=======================================================================================
** File Name:  telem_r_msg.h
**
** Title:  Message Definition Header File for TELEM_R Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-07-30
**
** Purpose:  To define TELEM_R's command and telemetry message defintions 
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-30 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TELEM_R_MSG_H_
#define _TELEM_R_MSG_H_

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
** TELEM_R command codes
*/
#define TELEM_R_NOOP_CC                 0
#define TELEM_R_RESET_CC                1

/*
** Local Structure Declarations
*/
typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint8              usCmdCnt;
    uint8              usCmdErrCnt;

    /* TODO:  Add declarations for additional housekeeping data here */

} TELEM_R_HkTlm_t;


#endif /* _TELEM_R_MSG_H_ */

/*=======================================================================================
** End of file telem_r_msg.h
**=====================================================================================*/
    
