#ifndef A_LANG_MACHINE_H
#define A_LANG_MACHINE_H

struct machine {
	struct stack *stack;
};

struct instruction;

struct machine *machine_create(void);
int machine_delete(struct machine *m);

int machine_push(struct machine *m, struct instruction *Inst);
int machine_pop(struct machine *m, struct instruction *Inst);
int machine_top(struct machine *m, struct instruction *Inst);

int machine_sum(struct machine *m, struct instruction *Inst);
int machine_mul(struct machine *m, struct instruction *Inst);
int machine_sub(struct machine *m, struct instruction *Inst);
int machine_div(struct machine *m, struct instruction *Inst);

#endif //A_LANG_MACHINE_H
