/*=======================================================================================
** File Name:  temp_io_private_ids.h
**
** Title:  ID Header File for TEMP_IO Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-07-27
**
** Purpose:  This header file contains declarations and definitions of TEMP_IO's private IDs.
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-27 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TEMP_IO_PRIVATE_IDS_H_
#define _TEMP_IO_PRIVATE_IDS_H_

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
#define TEMP_IO_RESERVED_EID  0

#define TEMP_IO_INF_EID        1
#define TEMP_IO_INIT_INF_EID   2
#define TEMP_IO_ILOAD_INF_EID  3
#define TEMP_IO_CDS_INF_EID    4
#define TEMP_IO_CMD_INF_EID    5

#define TEMP_IO_ERR_EID         51
#define TEMP_IO_INIT_ERR_EID    52
#define TEMP_IO_ILOAD_ERR_EID   53
#define TEMP_IO_CDS_ERR_EID     54
#define TEMP_IO_CMD_ERR_EID     55
#define TEMP_IO_PIPE_ERR_EID    56
#define TEMP_IO_MSGID_ERR_EID   57
#define TEMP_IO_MSGLEN_ERR_EID  58

#define TEMP_IO_EVT_CNT  14

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

#endif /* _TEMP_IO_PRIVATE_IDS_H_ */

/*=======================================================================================
** End of file temp_io_private_ids.h
**=====================================================================================*/
    