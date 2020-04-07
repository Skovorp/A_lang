#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *data;
    size_t size;
};

struct stack *stack_create(void);
int stack_delete(struct stack *stk);

int stack_push(struct stack *stk, int new_element);
int stack_pop(struct stack *stk);
int stack_top(struct stack *stk, int *top_element);

struct stack *stack_create(void)
{
    return (struct stack *)calloc(1, sizeof(struct stack));
}

int stack_delete(struct stack *stk)
{
    if (!stk->data) {
        free (stk);

        return 0;
    }

    free(stk->data);
    free(stk);

    return 0;
}

int stack_pop(struct stack *stk)
{
    stk->data = realloc(stk->data, (stk->size - 1) * sizeof(int));
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
    stk->data = realloc(stk->data,(stk->size + 1) * sizeof(int));
    stk->size++;

    if (!stk->data) {
        return -1;
    }

    stk->data[stk->size - 1] = new_element;

    return 0;
}

/*
int main(){
    struct stack *s;
    int *d ;
    int real;
    d = &real;
    s = stack_create();

    stack_push(s, 2);
    stack_top(s, d);
    printf("N1 %i \n", *d);

    stack_push(s, 3);
    stack_top(s, d);
    printf("N2 %i \n", *d);

    stack_pop(s);
    stack_top(s, d);
    printf("N3 %i \n", *d);

    stack_delete(s);

    return 0;
}
*/

