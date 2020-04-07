#include <stdio.h>

#include "stack.h"

struct machine {
	struct stack *stack;
};

struct machine *machine_create(void)
{
	struct machine *X = (struct machine *)calloc(1, sizeof(struct machine));
	X->stack = stack_create();

	return X;
}

int machine_delete(struct machine *m)
{
	if (!m->stack) {
		free(m);

		return 0;
	}

	stack_delete(m->stack);
	free(m);

	return 0;
}

int machine_push(struct machine *m, int new_element)
{
	if (!m->stack) {
		return -1;
	} else {
		return (stack_push(m->stack, new_element));
	}
}

int machine_pop(struct machine *m)
{
	if (!m->stack) {
		return -1;
	} else {
		return (stack_pop(m->stack));
	}
}

int machine_top(struct machine *m, int *top_element)
{
	if (!m->stack) {
		return -1;
	} else {
		return (stack_top(m->stack, top_element));
	}
}

int machine_sum(struct machine *m)
{
	int r = 0;

	int a;
	int b;
	int *pa;
	int *pb;
	pa = &a;
	pb = &b;

	r += machine_top(m, pa);
	r += machine_pop(m);
	r += machine_top(m, pb);
	r += machine_pop(m);

	r += machine_push(m, a + b);

	return r;
}

int machine_mul(struct machine *m)
{
	int r = 0;

	int a;
	int b;
	int *pa;
	int *pb;
	pa = &a;
	pb = &b;

	r += machine_top(m, pa);
	r += machine_pop(m);
	r += machine_top(m, pb);
	r += machine_pop(m);

	r += machine_push(m, a * b);

	return r;
}

int machine_sub(struct machine *m)
{
	int r = 0;

	int a;
	int b;
	int *pa;
	int *pb;
	pa = &a;
	pb = &b;

	r += machine_top(m, pa);
	r += machine_pop(m);
	r += machine_top(m, pb);
	r += machine_pop(m);

	r += machine_push(m, b - a);

	return r;
}

int machine_div(struct machine *m)
{
	int r = 0;

	int a;
	int b;
	int *pa;
	int *pb;
	pa = &a;
	pb = &b;

	r += machine_top(m, pa);
	r += machine_pop(m);
	r += machine_top(m, pb);
	r += machine_pop(m);

	if (a != 0) {
		r += machine_push(m, b / a);
	} else {
		return -1;
	}

	return r;
}

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
