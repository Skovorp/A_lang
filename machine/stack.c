#include <stdlib.h>

#include "stack.h"
#include "error.h"

struct stack *stack_create(void)
{
	return (struct stack *)calloc(1, sizeof(struct stack));
}

int stack_delete(struct stack *stk)
{
	if (stk->data) {
		free((void *)stk->data);
	}

	free((void *)stk);
	return SUCCESS;
}

int stack_pop(struct stack *stk)
{
	if ((!stk->data) || (stk->size == 0)) {
		return FAILURE;
	}

	stk->data = realloc((void *)stk->data, (stk->size - 1) * sizeof(int));
	stk->size--;

	return SUCCESS;
}

int stack_top(struct stack *stk, int *top_element)
{
	if ((!top_element) || (stk->size == 0)) {
		return FAILURE;
	}

	*top_element = stk->data[stk->size - 1];

	return SUCCESS;
}

int stack_push(struct stack *stk, int new_element)
{
	stk->data = realloc((void *)stk->data, (stk->size + 1) * sizeof(int));
	stk->size++;

	if (!stk->data) {
		return FAILURE;
	}

	stk->data[stk->size - 1] = new_element;

	return SUCCESS;
}
