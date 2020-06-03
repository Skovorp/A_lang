#include <stdlib.h>

#include "instruction.h"
#include "machine.h"
#include "error.h"

struct instruction *instruction_create(void)
{
	return (struct instruction *)calloc(1, sizeof(struct instruction));
}

int instruction_delete(struct instruction *inst)
{
	free(inst);
	return SUCCESS;
}

typedef int (*machine_instruction_executor_t)(struct machine *, struct instruction *);

int machine_execute_instruction(struct machine *m, struct instruction *inst)
{
	const machine_instruction_executor_t machine_instructions[INSTRUCTIONS_NO] = {
		machine_push, 
		machine_pop, 
		machine_top,
		machine_sum, 
		machine_sub, 
		machine_mul, 
		machine_div
	};
	
	if (inst->code >= INSTRUCTIONS_NO) {
		return FAILURE;
	}
	
	return (*machine_functions[inst->code])(m, inst);
}
