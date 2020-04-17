#include <stdlib.h>

#include "instruction.h"
#include "machine.h"

int machine_execute_instruction(struct machine *m, struct instruction *inst)
{
	 void (*machine_functions[7])(struct machine*, int*) = {
			machine_push, machine_pop, machine_top,
			machine_sum, machine_sub, machine_mul, machine_div
	};
	(*machine_functions[inst->code])(m, inst->operand);

	return 0;
}