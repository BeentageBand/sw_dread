/*=====================================================================================*/
/**
 * dread_stdin_hdr_server.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#ifndef DREAD_STDIN_HDR_SERVER_H_
#define DREAD_STDIN_HDR_SERVER_H_
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "dread_stdin_hdr.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Define Macros
 *=====================================================================================*/
#ifdef __cplusplus
extern "C" {
#endif
#define DREAD_STDIN_HDR_SERVER_CTOR(PARAM) PARAM(uint8_t const, id)
/*=====================================================================================* 
 * Exported Type Declarations
 *=====================================================================================*/
Declare_Class_Inherits (
      Dr_Stdin_Hdr_Server, Dr_Stdin_Hdr,
      DREAD_STDIN_HDR_SERVER_CTOR,
      bool_t is_connection_ready;
      ,
      );
/*=====================================================================================* 
 * Exported Object Declarations
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Function Prototypes
 *=====================================================================================*/
extern void Dr_Stdin_Hdr_Server_send_info(Dr_Stdin_Hdr_Server obj, uint8_t const * info, size_t const info_size);
extern bool_t Dr_Stdin_Hdr_Server_is_connection_ready(Dr_Stdin_Hdr_Server obj);
/*=====================================================================================* 
 * Exported Function Like Macros
 *=====================================================================================*/
#ifdef __cplusplus
}
#endif
/*=====================================================================================* 
 * dread_stdin_hdr_server.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*DREAD_STDIN_HDR_SERVER_H_*/