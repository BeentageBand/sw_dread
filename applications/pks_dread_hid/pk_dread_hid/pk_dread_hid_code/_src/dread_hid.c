/*=====================================================================================*/
/**
 * dread_hid.cpp
 * author : puch
 * date : Oct 22 2015
 *
 * description : Any comments
 *
 */
/*=====================================================================================*/
#define CLASS_IPLEMENTATION
/*=====================================================================================*
 * Project Includes
 *=====================================================================================*/
#include "dread_hid.h"
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
static void Dr_HID_Ctor(Dr_HID_T * const this, uint8_t const id);
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
void Dr_HID_init(void)
{
   printf("%s \n", __FUNCTION__);
   Dr_HID_Obj.id = 0;

   Dr_HID_Vtbl.Object.rtti = &Dr_HID_Rtti;
   Dr_HID_Vtbl.Object.destroy = Dr_HID_Dtor;
   Dr_HID_Vtbl.ctor = Dr_HID_Ctor;
   Dr_HID_Vtbl.success = NULL;
   Dr_HID_Vtbl.error = NULL;

}
void Dr_HID_shut(void) {}

void Dr_HID_Dtor(Object_T * const obj)
{
}
/*=====================================================================================* 
 * Exported Function Definitions
 *=====================================================================================*/
void Dr_HID_Ctor(Dr_HID_T * const this, uint8_t const id)
{
   this->id = id;
}
/*=====================================================================================* 
 * dread_hid.cpp
 *=====================================================================================*
 * Log History
 *
 *=====================================================================================*/
