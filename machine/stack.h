#ifndef ALANG_STACK_H
#define ALANG_STACK_H

struct stack {
	int *data;
	size_t size;
};

struct stack *stack_create(void);
int stack_delete(struct stack *stk);

int stack_push(struct stack *stk, int new_element);
int stack_pop(struct stack *stk);
int stack_top(struct stack *stk, int *top_element);

#endif /* ALANG_STACK_H */
