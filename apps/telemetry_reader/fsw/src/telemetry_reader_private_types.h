/*=======================================================================================
** File Name:  telemetry_reader_private_types.h
**
** Title:  Type Header File for TELEMETRY_READER Application
**
** $Author:    AUSTIN COSBY
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  This header file contains declarations and definitions of all TELEMETRY_READER's private
**           data structures and data types.
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | AUSTIN COSBY | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TELEMETRY_READER_PRIVATE_TYPES_H_
#define _TELEMETRY_READER_PRIVATE_TYPES_H_

/*
** Pragmas
*/

/*
** Include Files
*/
#include "cfe.h"

/*
** Local Defines
*/

/*
** Local Structure Declarations
*/

typedef struct
{
    uint8  ucCmdHeader[CFE_SB_CMD_HDR_SIZE];
} TELEMETRY_READER_NoArgCmd_t;


typedef struct
{
    uint32  counter;

    /* TODO:  Add input data to this application here, such as raw data read from I/O
    **        devices or data subscribed from other apps' output data.
    */

} TELEMETRY_READER_InData_t;

typedef struct
{
    uint8   ucTlmHeader[CFE_SB_TLM_HDR_SIZE];
    uint32  uiCounter;
} TELEMETRY_READER_OutData_t;

/* TODO:  Add more private structure definitions here, if necessary. */

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

#endif /* _TELEMETRY_READER_PRIVATE_TYPES_H_ */

/*=======================================================================================
** End of file telemetry_reader_private_types.h
**=====================================================================================*/
    