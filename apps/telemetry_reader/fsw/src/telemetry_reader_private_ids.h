/*=======================================================================================
** File Name:  telemetry_reader_private_ids.h
**
** Title:  ID Header File for TELEMETRY_READER Application
**
** $Author:    AUSTIN COSBY
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  This header file contains declarations and definitions of TELEMETRY_READER's private IDs.
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | AUSTIN COSBY | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TELEMETRY_READER_PRIVATE_IDS_H_
#define _TELEMETRY_READER_PRIVATE_IDS_H_

/*
** Pragmas
*/

/*
** Include Files
*/

/*
** Local Defines
*/

/* Event IDs */
#define TELEMETRY_READER_RESERVED_EID  0

#define TELEMETRY_READER_INF_EID        1
#define TELEMETRY_READER_INIT_INF_EID   2
#define TELEMETRY_READER_ILOAD_INF_EID  3
#define TELEMETRY_READER_CDS_INF_EID    4
#define TELEMETRY_READER_CMD_INF_EID    5

#define TELEMETRY_READER_ERR_EID         51
#define TELEMETRY_READER_INIT_ERR_EID    52
#define TELEMETRY_READER_ILOAD_ERR_EID   53
#define TELEMETRY_READER_CDS_ERR_EID     54
#define TELEMETRY_READER_CMD_ERR_EID     55
#define TELEMETRY_READER_PIPE_ERR_EID    56
#define TELEMETRY_READER_MSGID_ERR_EID   57
#define TELEMETRY_READER_MSGLEN_ERR_EID  58

#define TELEMETRY_READER_EVT_CNT  14

/*
** Local Structure Declarations
*/

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

#endif /* _TELEMETRY_READER_PRIVATE_IDS_H_ */

/*=======================================================================================
** End of file telemetry_reader_private_ids.h
**=====================================================================================*/
    