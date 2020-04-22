#include <stdlib.h>

#include "instruction.h"
#include "machine.h"

struct instruction *instruction_create(void)
{
	return (struct instruction *)calloc(1, sizeof(struct instruction));
}

int machine_execute_instruction(struct machine *m, struct instruction *inst)
{
	 int (*machine_functions[7])(struct machine*, struct instruction*) = {
			machine_push, machine_pop, machine_top,
			machine_sum, machine_sub, machine_mul, machine_div
	};
	return (*machine_functions[inst->code])(m, inst);
}