#include <stdio.h>

#include "stack.h"
#include "machine.h"


int main()
{
	struct machine *M;
	int *d;
	int real;
	d = &real;
	M = machine_create();

	machine_push(M, 2);
	machine_top(M, d);
	printf("N1 %i \n", *d);

	machine_push(M, 3);
	machine_top(M, d);
	printf("N2 %i \n", *d);

	machine_push(M, 4);
	machine_top(M, d);
	printf("N3 %i \n", *d);

	machine_sum(M);
	machine_top(M, d);
	printf("N4 %i \n", *d);

	machine_div(M);
	machine_top(M, d);
	printf("N5 %i \n", *d);

	machine_delete(M);

	return 0;
}
