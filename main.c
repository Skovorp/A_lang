#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "machine.h"
#include "instruction.h"

int main()
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
