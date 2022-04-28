#ifndef TEE_ENTRY_H
#define TEE_ENTRY_H

/*
 * Standard call entry, __weak, overridable. If overridden should call
 * __tee_entry() at the end in order to handle the standard functions.
 *
 * These functions are called in a normal thread context.
 */
uint32_t tee_entry(struct optee_msg_arg *arg, uint32_t num_params);
uint32_t __tee_entry(struct optee_msg_arg *arg, uint32_t num_params);

#endif /* TEE_ENTRY_STD_H */
