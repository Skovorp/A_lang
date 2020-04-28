#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "machine.h"
#include "instruction.h"

/*
int main1()
{
	struct machine *mach;
	int *dp;
	int d;
	dp = &d;
	mach = machine_create();

	int *kp;
	int k;
	k = &k;
	int *fake;

	struct instruction *instnst = (struct instruction *)calloc(1, sizeof(struct instruction));
	unsigned char *cp;
	unsigned char c;
	cp = &c;
	instnst->operand = cp;
	instnst->operand = k;

	k = 1;
	c = 0;
	machine_execute_instruction(instnst, mach);

	k = 2;
	machine_push(mach, kp);
	machine_top(mach, dp);
	printf("N1 %i \n", *dp);

	k = 3;
	machine_push(mach, kp);
	machine_top(mach, dp);
	printf("N2 %i \n", *dp);

	k = 4;
	machine_push(mach, kp);
	machine_top(mach, dp);
	printf("N3 %i \n", *dp);

	machine_sum(mach, fake);
	machine_top(mach, dp);
	printf("N4 %i \n", *dp);

	machine_div(mach, fake);
	machine_top(mach, dp);
	printf("N5 %i \n", *dp);

	machine_delete(mach);

	return 0;
}
*/

int main()
{
	struct instruction *inst = instruction_create();
	struct machine *mach = machine_create();
	int oper;
	int status;
	inst->operand = &oper;

	inst->code = INSTRUCTION_PUSH;
	oper = 10;
	status = machine_execute_instruction(mach, inst);
	printf("%i \n", status);

	inst->code = INSTRUCTION_PUSH;
	oper = 5;
	status = machine_execute_instruction(mach, inst);
	printf("%i \n", status);

	inst->code = INSTRUCTION_DIV;
	status = machine_execute_instruction(mach, inst);
	printf("%i \n", status);

	inst->code = INSTRUCTION_TOP;
	machine_execute_instruction(mach, inst);

	printf("%i", oper);

	return 0;
}
