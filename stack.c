#include <stdio.h>
#include <stdlib.h>

struct stack *stack_create(void)
{
	return (struct stack *)calloc(1, sizeof(struct stack));
}

int stack_delete(struct stack *stk)
{
	if (stk) {
		free((void *)stk->data);
	}

	free((void *)stk);
	return 0;
}

int stack_pop(struct stack *stk)
{
	stk->data = realloc((void *)stk->data, (stk->size - 1) * sizeof(int));
	stk->size--;

	if ((!stk->data) || (stk->size == 0)) {
		return -1;
	}

	return 0;
}

int stack_top(struct stack *stk, int *top_element)
{
	if ((!top_element) || (stk->size == 0)) {
		return -1;
	}

	*top_element = stk->data[stk->size - 1];

	return 0;
}

int stack_push(struct stack *stk, int new_element)
{
	stk->data = realloc((void *)stk->data, (stk->size + 1) * sizeof(int));
	stk->size++;

	if (!stk->data) {
		return -1;
	}

	stk->data[stk->size - 1] = new_element;

	return 0;
}
