#ifndef A_LANG_INSTRUCTION_H
#define A_LANG_INSTRUCTION_H

struct instruction {
	unsigned char code;
	int *operand;
};

int machine_execute_instruction(struct machine *m, struct instruction *inst);

#endif //A_LANG_INSTRUCTION_H