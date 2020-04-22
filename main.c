#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "machine.h"
#include "instruction.h"

/*
int main1()
{
	struct machine *M;
	int *dp;
	int d;
	dp = &d;
	M = machine_create();

	int *kp;
	int k;
	k = &k;
	int *fake;

	struct instruction *Inst = (struct instruction *)calloc(1, sizeof(struct instruction));
	unsigned char *cp;
	unsigned char c;
	cp = &c;
	Inst->operand = cp;
	Inst->operand = k;

	k = 1;
	c = 0;
	machine_execute_instruction(Inst, M);

	k = 2;
	machine_push(M, kp);
	machine_top(M, dp);
	printf("N1 %i \n", *dp);

	k = 3;
	machine_push(M, kp);
	machine_top(M, dp);
	printf("N2 %i \n", *dp);

	k = 4;
	machine_push(M, kp);
	machine_top(M, dp);
	printf("N3 %i \n", *dp);

	machine_sum(M, fake);
	machine_top(M, dp);
	printf("N4 %i \n", *dp);

	machine_div(M, fake);
	machine_top(M, dp);
	printf("N5 %i \n", *dp);

	machine_delete(M);

	return 0;
}
*/

int main()
{
	struct instruction *I = instruction_create();
	struct machine *M = machine_create();
	int oper;
	int status;
	I->operand = &oper;

	I->code = 0;
	oper = 10;
	status = machine_execute_instruction(M, I);
	printf("%i \n", status);

	I->code = 0;
	oper = 5;
	status = machine_execute_instruction(M, I);
	printf("%i \n", status);

	I->code = 6;
	status = machine_execute_instruction(M, I);
	printf("%i \n", status);

	I->code = 2;
	machine_execute_instruction(M, I);

	printf("%i", oper);

	return 0;
}
