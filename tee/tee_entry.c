
#include <stdint.h>
#include "tee_defines.h"
#include <stdio.h>

/*
 * If tee_entry_std() is overridden, it's still supposed to call this
 * function.
 */
uint32_t __tee_entry()
{
	uint32_t rv;// = TEE_SMC_RETURN_OK;

	printf("_tee_entry_std\n\r");

	/* Enable foreign interrupts for STD calls */
	//thread_set_foreign_intr(true);
	// switch (arg->cmd) {
	// case TEE_MSG_CMD_OPEN_SESSION:
	// 	entry_open_session(arg, num_params);
	// 	break;
	// case TEE_MSG_CMD_CLOSE_SESSION:
	// 	entry_close_session(arg, num_params);
	// 	break;
	// case TEE_MSG_CMD_INVOKE_COMMAND:
	// 	entry_invoke_command(arg, num_params);
	// 	break;
	// case TEE_MSG_CMD_CANCEL:
	// 	entry_cancel(arg, num_params);
	// 	break;
	// default:
	// 	break;
	// 	//EMSG("Unknown cmd 0x%x", arg->cmd);
	// }

	return 0;
}