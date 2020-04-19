#include <stdlib.h>

#include "machine.h"
#include "stack.h"
#include "instruction.h"

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

int machine_push(struct machine *m, struct instruction *Inst)
{
	if (!m->stack) {
		return -1;
	} else {
		return (stack_push(m->stack, *Inst->operand));
	}
}

int machine_pop(struct machine *m, struct instruction *Inst)
{
	if (!m->stack) {
		return -1;
	} else {
		return (stack_pop(m->stack));
	}
}

int machine_top(struct machine *m, struct instruction *Inst)
{
	if (!m->stack) {
		return -1;
	} else {
		return (stack_top(m->stack, Inst->operand));
	}
}

int machine_sum(struct machine *m, struct instruction *Inst)
{
	int r = 0;

	int a;
	int b;
	struct instruction Inst1;
	struct instruction Inst2;
	struct instruction *pInst1;
	struct instruction *pInst2;
	pInst1 = &Inst1;
	pInst2 = &Inst2;
	pInst1->operand = &a;
	pInst2->operand = &b;

	r += machine_top(pInst1);
	r += machine_pop(Inst);
	r += machine_top(pInst2);
	r += machine_pop(Inst);

	Inst->operand = *Inst1.operand + *Inst2.operand;
	r += machine_push(Inst);

	return r;
}

int machine_mul(struct machine *m, struct instruction *Inst)
{
	int r = 0;

	int a;
	int b;
	int *pa;
	int *pb;
	pa = &a;
	pb = &b;

	r += machine_top(m, pa);
	r += machine_pop(m, fake);
	r += machine_top(m, pb);
	r += machine_pop(m, fake);

	r += machine_push(m, a * b);

	return r;
}

int machine_sub(struct machine *m, struct instruction *Inst)
{
	int r = 0;

	int a;
	int b;
	int *pa;
	int *pb;
	pa = &a;
	pb = &b;

	r += machine_top(m, pa);
	r += machine_pop(m, fake);
	r += machine_top(m, pb);
	r += machine_pop(m, fake);

	r += machine_push(m, b - a);

	return r;
}

int machine_div(struct machine *m, struct instruction *Inst)
{
	int r = 0;

	int a;
	int b;
	int *pa;
	int *pb;
	pa = &a;
	pb = &b;

	r += machine_top(m, pa);
	r += machine_pop(m, fake);
	r += machine_top(m, pb);
	r += machine_pop(m, fake);

	if (a != 0) {
		r += machine_push(m, b / a);
	} else {
		return -1;
	}

	return r;
}
