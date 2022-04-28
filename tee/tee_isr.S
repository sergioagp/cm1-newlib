# Copyright(C) 2018 Hex Five Security, Inc. - All Rights Reserved

//#include "platform.h"
//#include "common.h"

#include "tee_defines.h"

# Make sure that the GNU assembler is using a modern syntax for Arm THUMB.
.syntax unified
.extern __tee_entry


# -------------------------------------------------------------
.section        .data.tee_isr
# -------------------------------------------------------------

# -------------------------------------------------------------
.section        .text.tee_isr
# -------------------------------------------------------------

# -------------------------------------------------------------
.align 2
.global         tee_interrupt_handler
.type           tee_interrupt_handler, %function
tee_interrupt_handler:
    //  clear interrupt
	push    {lr}
    ldr     r0, =ASM_TEE_MSG_ARG_INTCLR_ADDR
    ldr     r1, =0
    str     r1, [r0]      
    bl      __tee_entry
    // validate DONE before go back to idle
    ldr     r0, =ASM_TEE_MSG_ARG_DONE_ADDR
    ldr     r1, =1
    str     r1, [r0]         
    pop     {pc}
