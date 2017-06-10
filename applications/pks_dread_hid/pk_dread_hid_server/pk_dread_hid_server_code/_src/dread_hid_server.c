/*=====================================================================================*/
/**
 * dread_hid_server.c
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#define CLASS_IMPLEMENTATION
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "dread_hid_server.h"
/*=====================================================================================* 
 * Standard Includes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local X-Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Define Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Type Definitions
 *=====================================================================================*/
 
/*=====================================================================================* 
 * Local Function Prototypes
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Object Definitions
 *=====================================================================================*/
static void Dr_HID_Server_Ctor(Dr_HID_Server_T * const this, uint8_t const id);
static void Dr_HID_Server_success(Dr_HID_T * const super, Dr_HID_Success_T const success_type);
static void Dr_HID_Server_error(Dr_HID_T * const super, Dr_HID_Error_T const error_type);
/*=====================================================================================*
 * Local Object Definitions
 *=====================================================================================*/
CLASS_DEFINITION
/*=====================================================================================* 
 * Exported Object Definitions
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Inline-Function Like Macros
 *=====================================================================================*/

/*=====================================================================================* 
 * Local Function Definitions
 *=====================================================================================*/
void Dr_HID_Server_init(void)
{
   printf("%s \n", __FUNCTION__);

   Dr_HID_Server_Obj.Dr_HID = Dr_HID();

   memcpy(&Dr_HID_Server_Vtbl.Dr_HID, Dr_HID_Server_Obj.vtbl,
         sizeof(Dr_HID_Server_Vtbl.Dr_HID));

   Dr_HID_Server_Vtbl.Dr_HID.Object.rtti = &Dr_HID_Server_Rtti;
   Dr_HID_Server_Vtbl.Dr_HID.Object.destroy = Dr_HID_Server_Dtor;

   Dr_HID_Server_Vtbl.Dr_HID.success = Dr_HID_Server_success;
   Dr_HID_Server_Vtbl.Dr_HID.error = Dr_HID_Server_error;

   Dr_HID_Server_Vtbl.ctor = Dr_HID_Server_Ctor;

   Dr_HID_Server_Obj.vtbl = &Dr_HID_Server_Vtbl;
   Object_update_info(&Dr_HID_Server_Obj.Dr_HID.Object, Dr_HID().rtti->rtti);

}
void Dr_HID_Server_shut(void) {}

void Dr_HID_Server_Dtor(Object_T * const obj)
{
}

/*=====================================================================================*
 * Exported Function Definitions
 *=====================================================================================*/
void Dr_HID_Server_Ctor(Dr_HID_Server_T * const this, uint8_t const id)
{
   this->Dr_HID.vtbl->ctor(&this->Dr_HID, id);
}

void Dr_HID_Server_success(Dr_HID_T * const super, Dr_HID_Success_T const success_type)
{
   Dr_HID_HSM_Signal_T signal = {DREAD_HID_SUCCESS, success_type};
   Dr_HID_Server_T * this = _dynamic_cast(Dr_HID_Server, super);
   this->hsm.vtbl->dispatch(&this->hsm, this, &signal);
}

void Dr_HID_Server_error(Dr_HID_T * const super, Dr_HID_Error_T const error_type)
{
   Dr_HID_HSM_Signal_T signal = {DREAD_HID_ERROR, error_type};
   Dr_HID_Server_T * this = _dynamic_cast(Dr_HID_Server, super);
   this->hsm.vtbl->dispatch(&this->hsm, this, &signal);
}
/*=====================================================================================* 
 * dread_hid_server.c
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
