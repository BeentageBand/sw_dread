#ifndef IPC_USET_H_
#define IPC_USET_H_
 
#define IPC_THREAD_LIST(TASK_ID) \
TASK_ID(DREAD_DC_TID,      "DREAD DATA COLLECTOR") \
TASK_ID(USER_FEEDBACK_TID, "USER FEEDBACK") \
TASK_ID(STDIN_TID, "STD INPUT") \

#endif /*IPC_USET_H_*/