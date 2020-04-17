#ifndef A_LANG_MACHINE_H
#define A_LANG_MACHINE_H

struct machine {
	struct stack *stack;
};


struct machine *machine_create(void);
int machine_delete(struct machine *m);

int machine_push(struct machine *m, int *new_element);
int machine_pop(struct machine *m, int *fake);
int machine_top(struct machine *m, int *top_element);

int machine_sum(struct machine *m, int *fake);
int machine_mul(struct machine *m, int *fake);
int machine_sub(struct machine *m, int *fake);
int machine_div(struct machine *m, int *fake);


#endif //A_LANG_MACHINE_H
