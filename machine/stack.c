#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "error.h"

struct stack *stack_create(void)
{
	return (struct stack *)calloc(1, sizeof(struct stack));
}

int stack_delete(struct stack *stk)
{
	if (!stk) {
		return SUCCESS;
	}
	
	free((void *)stk->data);
	free((void *)stk);
	
	return SUCCESS;
}

int stack_pop(struct stack *stk)
{
	assert(stk);
	
	if (!stk->data || !stk->size) {
		return FAILURE;
	}

	stk->size--;
	stk->data = realloc((void *)stk->data, stk->size * sizeof(int));

	return SUCCESS;
}

int stack_top(struct stack *stk, int *top_element)
{
	assert(stk);
	assert(top_element);
	
	if (!stk->data || !stk->size) {
		return FAILURE;
	}

	*top_element = stk->data[stk->size - 1];

	return SUCCESS;
}

int stack_push(struct stack *stk, int new_element)
{
	assert(stk);
	
	stk->size++;
	stk->data = realloc((void *)stk->data, stk->size * sizeof(int));

	if (!stk->data) {
		return FAILURE;
	}

	stk->data[stk->size - 1] = new_element;

	return SUCCESS;
}
