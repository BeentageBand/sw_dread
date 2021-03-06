#define COBJECT_IMPLEMENTATION
#undef Dbg_FID
#define Dbg_FID DBG_FID_DEF(DREAD_DC_FID, 0)

#include "data_collector.h"
#include "dbg_log.h"
#include "dread_stdin.h"
#include "ipc.h"


static bool dc_is_valid(uint8_t const * raw, size_t const size);
static void dcfsm_delete(struct Object * const obj);
static void dcfsm_init(union DCFSM * const fsm);
static void dcfsm_done(union DCFSM * const fsm);
static bool dcfsm_req_stdin_data(union FSM * const fsm, union Mail * const mail);
static bool dcfsm_validate_stdin_data(union FSM * const fsm, union Mail * const mail);
static bool dcfsm_handle_stdin_err(union FSM * const fsm, union Mail * const mail);
static bool dcfsm_store_data(union FSM * const fsm, union Mail * const mail);
static bool dcfsm_completed(union FSM * const fsm, union Mail * const mail);

//Declare FSM for Data Collector
FSM_Declare_Chart(DCFSM_FSM, DC_StChart)

static union St_Machine_State DC_States [DC_STATE_MAX] = {0};

DCFSM_Class_T DCFSM_Class = 
{{//FSM
  {dcfsm_delete, &FSM_Class.Class},
  NULL,
  NULL,
  NULL
}};

static DCFSM_T DCFSM = {{/*FSM*/NULL}};


static IPC_MID_T DCFSM_Mailist[] = 
{
   STDIN_PBC_INCOMING_DATA_MID
};

bool dc_is_valid(uint8_t const * raw, size_t const size)
{
   //TODO
   return false;
}

void dcfsm_delete(struct Object * const obj)
{
   DCFSM_T * const this = (DCFSM_T *) Object_Cast(&DCFSM_Class.Class, obj);
   this->vtbl->done(this);
}

void dcfsm_init(union DCFSM * const this)
{
  bool is_subscribed = IPC_Subscribe_Mailist(DCFSM_Mailist, Num_Elems(DCFSM_Mailist));
  Dbg_Info("%s: DCFSM is%s subscribed", __func__, (is_subscribed)? "": " not");

  //TODO proper signaling
  union Mail init_mail = {{NULL}};
  IPC_MID_T init_fsm = 0;
  IPC_Self_Send(init_fsm, NULL, 0);

  if( IPC_Retrieve_From_Mailist(&init_mail, &init_fsm, 1, IPC_RETRIEVE_TOUT_MS))
  {
   this->State_Machine.vtbl->dispatch(this, &init_mail);
  }
  else
  {
     Dbg_Fault("%s:Data Collector FSM is not initiallized", __func__);
  }
}

void dcfsm_done(union DCFSM * const this)
{
  union Mail done_mail = {{NULL}};
  //TODO fix fsm signaling
  IPC_MID_T done_fsm = 0;
  IPC_Self_Send(done_fsm, NULL, 0);
  if(IPC_Retrieve_From_Mailist(&done_mail, &done_fsm, 1, IPC_RETRIEVE_TOUT_MS))
  {
   this->State_Machine.vtbl->dispatch(&this->State_Machine, &done_mail);
  }
  else
  {
     Dbg_Fault("%s:Unable to finish state_machine", __func__);
  }
   IPC_Unsubscribe_Mailist(DCFSM_Mailist, Num_Elems(DCFSM_Mailist));
}

bool dcfsm_req_stdin_data(union FSM * const fsm, union Mail * const mail)
{
//TODO   DC_Timer_Poll_Data.vtbl->stop(&DC_Timer_Poll_Data);
   //TODO DC_Timer_Wait_Data.vtbl->start(&DC_Timer_Wait_Data);
   IPC_Send(STDIN_TID, STDIN_PBC_REQ_DATA_MID, NULL, 0UL);
   return true;
}

bool dcfsm_validate_stdin_data(union FSM * const fsm, union Mail * const mail)
{
   struct STDIN_Reg * stdin_reg = mail->payload;
   if(STDIN_REG_SIZE == mail->pay_size)
   {
      if(dc_is_valid(stdin_reg->raw, STDIN_REG_SIZE))
      {
         IPC_Send_Self(DC_INT_VALID_DATA_MID, stdin_reg->raw, STDIN_REG_SIZE);
      }
   } 

   //TODO
   return true;
}

bool dcfsm_handle_stdin_err(union FSM * const fsm, union Mail * const mail)
{
   DC_ERR_T stdin_err = *((DC_ERR_T *)mail->payload);
   switch(stdin_err)
   {
      case DC_DATA_TIMEOUT_ERR:
      {
         break;
      }
      case DC_INVALID_DATA_ERR:
      {
          IPC_Send(USER_FEEDBACK_TID, UF_PBC_INVALID_STDIN_MID, NULL, 0);
          break;
      }
      default: break;
   }
   //TODO DC_Timer_Poll_Data.vtbl->start(&DC_Timer_Poll_Data);
   return DC_OK == stdin_err;
}

bool dcfsm_store_data(union FSM * const fsm, union Mail * const mail)
{
//TODO  static char datetime[] = {"dd/mm/yyy hh:mm:ss"};
//TODO  sprintf(datetime, "%2d/%2d/%4d %2d:%2d:%2d",
//      DC_Datetime.day, DC_Datetime.month, DC_Datetime.year,
//      DC_Datetime.hour, DC_Datetime.minutes, DC_Datetime.seconds);
   uint32_t rc = 0;
   //TODO uint32_t rc = DStorage_File.vtbl->append(&DStorage_File, mail->payload, mail->pay_size);
   if( 0 != rc)
   {
      IPC_Send_Self(DC_INT_COMPLETED_STORAGE_MID, NULL, 0);
   }
   else
   {
      //TODO IPC_Send_Self(DC_INT_INVALID_DATA_MID, reg->raw, 16U);
   }
   //TODO DC_Timer_Poll_Data.vtbl->start(&DC_Timer_Poll_Data);
   return true;
}

bool dcfsm_completed(union FSM * const fsm, union Mail * const mail)
{
   return true;
}

DCFSM_T * Alloc_Data_Collector(void)
{
   if(NULL == DCFSM.vtbl)
   {
      Populate_FSM(&DCFSM, 
           DC_StChart,
           Num_Elems(DC_StChart),
           DC_States,
           Num_Elems(DC_States));
      Object_Init(&DCFSM.Object, &DCFSM_Class.Class, sizeof(DCFSM_Class));
   }
   return &DCFSM;
}
