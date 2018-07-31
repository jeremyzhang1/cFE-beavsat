/*=======================================================================================
** File Name:  telem_r_private_ids.h
**
** Title:  ID Header File for TELEM_R Application
**
** $Author:    Austin Cosby
** $Revision: 1.1 $
** $Date:      2018-07-30
**
** Purpose:  This header file contains declarations and definitions of TELEM_R's private IDs.
**
** Modification History:
**   Date | Author | Description
**   ---------------------------
**   2018-07-30 | Austin Cosby | Build #: Code Started
**
**=====================================================================================*/
    
#ifndef _TELEM_R_PRIVATE_IDS_H_
#define _TELEM_R_PRIVATE_IDS_H_

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
#define TELEM_R_RESERVED_EID  0

#define TELEM_R_INF_EID        1
#define TELEM_R_INIT_INF_EID   2
#define TELEM_R_ILOAD_INF_EID  3
#define TELEM_R_CDS_INF_EID    4
#define TELEM_R_CMD_INF_EID    5

#define TELEM_R_ERR_EID         51
#define TELEM_R_INIT_ERR_EID    52
#define TELEM_R_ILOAD_ERR_EID   53
#define TELEM_R_CDS_ERR_EID     54
#define TELEM_R_CMD_ERR_EID     55
#define TELEM_R_PIPE_ERR_EID    56
#define TELEM_R_MSGID_ERR_EID   57
#define TELEM_R_MSGLEN_ERR_EID  58

#define TELEM_R_EVT_CNT  14

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

#endif /* _TELEM_R_PRIVATE_IDS_H_ */

/*=======================================================================================
** End of file telem_r_private_ids.h
**=====================================================================================*/
    