#include <stdlib.h>

#include "error.h"
#include "instruction.h"
#include "machine.h"
#include "stack.h"

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

		return SUCCESS;
	}

	stack_delete(m->stack);
	free(m);

	return SUCCESS;
}

int machine_push(struct machine *m, struct instruction *Inst)
{
	if (!m->stack) {
		return FAILURE;
	} else {
		return (stack_push(m->stack, *Inst->operand));
	}
}

int machine_pop(struct machine *m, struct instruction *Inst)
{
	if (!m->stack) {
		return FAILURE;
	} else {
		return (stack_pop(m->stack));
	}
}

int machine_top(struct machine *m, struct instruction *Inst)
{
	if (!m->stack) {
		return FAILURE;
	} else {
		return (stack_top(m->stack, Inst->operand));
	}
}

int machine_sum(struct machine *m, struct instruction *Inst)
{
	int operand0, operand1;
	int status;

	status = stack_top(m->stack, &operand0);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_pop(m->stack);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_top(m->stack, &operand1);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_pop(m->stack);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_push(m->stack, operand0 + operand1);
	if (FAILED(status)) {
		return FAILURE;
	}

	return SUCCESS;
}

int machine_mul(struct machine *m, struct instruction *Inst)
{
	int operand0, operand1;
	int status;

	status = stack_top(m->stack, &operand0);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_pop(m->stack);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_top(m->stack, &operand1);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_pop(m->stack);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_push(m->stack, operand0 * operand1);
	if (FAILED(status)) {
		return FAILURE;
	}

	return SUCCESS;
}

int machine_sub(struct machine *m, struct instruction *Inst)
{
	int operand0, operand1;
	int status;

	status = stack_top(m->stack, &operand0);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_pop(m->stack);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_top(m->stack, &operand1);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_pop(m->stack);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_push(m->stack, operand1 - operand0);
	if (FAILED(status)) {
		return FAILURE;
	}

	return SUCCESS;
}

int machine_div(struct machine *m, struct instruction *Inst)
{
	int operand0, operand1;
	int status;

	status = stack_top(m->stack, &operand0);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_pop(m->stack);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_top(m->stack, &operand1);
	if (FAILED(status)) {
		return FAILURE;
	}

	status = stack_pop(m->stack);
	if (FAILED(status)) {
		return FAILURE;
	}

	if (operand1 == 0) {
		return FAILURE;
	}

	status = stack_push(m->stack, operand1 / operand0);
	if (FAILED(status)) {
		return FAILURE;
	}

	return SUCCESS;
}
