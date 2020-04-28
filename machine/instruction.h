#ifndef A_LANG_INSTRUCTION_H
#define A_LANG_INSTRUCTION_H

struct instruction {
	unsigned char code;
	int *operand;
};

#define INSTRUCTION_PUSH 0;
#define INSTRUCTION_POP 1;
#define INSTRUCTION_TOP 2;
#define INSTRUCTION_SUM 3;
#define INSTRUCTION_SUB 4;
#define INSTRUCTION_MUL 5;
#define INSTRUCTION_DIV 6;
#define MACHINE_INSTRUCTION_NO 7

struct machine;

struct instruction *instruction_create(void);
int machine_execute_instruction(struct machine *m, struct instruction *inst);

#endif //A_LANG_INSTRUCTION_H
