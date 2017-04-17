/*=====================================================================================*/
/**
 * tb_mail_list.h
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#ifndef TB_MAIL_LIST_H_
#define TB_MAIL_LIST_H_
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "dread_stdin_hdr_evs.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Define Macros
 *=====================================================================================*/
#ifdef __cplusplus
extern "C" {
#endif

#define TB_PRIVATE_MAIL_LIST \
   DREAD_STDIN_PRIVATE_MAIL_LIST  \

#define TB_SUBSCRIBABLE_MAIL_LIST \
   DREAD_STDIN_SUBSCRIBABLE_MAIL_LIST  \

#define TB_RETRIEVE_TOUT_MS (500U)
/*=====================================================================================* 
 * Exported Type Declarations
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Object Declarations
 *=====================================================================================*/

/*=====================================================================================* 
 * Exported Function Prototypes
 *=====================================================================================*/
#undef TB_MAIL
#define TB_MAIL(mail, description) mail,

#define PRIVATE_MAIL(mail, desc)      TB_MAIL(mail, desc)
#define SUBSCRIBABLE_MAIL(mail, desc) TB_MAIL(mail, desc)


enum
{
   TB_BEGIN_PRIVATE_MAIL_LIST_ID = 0,
   TB_PRIVATE_MAIL_LIST
   TB_END_PRIVATE_MAIL_LIST_ID,
   TB_BEGIN_SUBSCRIBABLE_MAIL_LIST_ID = TB_END_PRIVATE_MAIL_LIST_ID,
   TB_SUBSCRIBABLE_MAIL_LIST
   TB_END_SUBSCRIBABLE_MAIL_LIST_ID,
   TB_TOTAL_MAIL_LIST_ITEMS
};
/*=====================================================================================* 
 * Exported Function Like Macros
 *=====================================================================================*/
#ifdef __cplusplus
}
#endif
/*=====================================================================================* 
 * tb_mail_list.h
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
#endif /*TB_MAIL_LIST_H_*/