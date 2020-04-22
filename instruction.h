#ifndef A_LANG_INSTRUCTION_H
#define A_LANG_INSTRUCTION_H

struct instruction {
	unsigned char code;
	int *operand;
};

struct machine;

struct instruction *instruction_create(void);
int machine_execute_instruction(struct machine *m, struct instruction *inst);

#endif //A_LANG_INSTRUCTION_H
