#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * interpret - Interpret Monty bytecode from a file
 * @file: Pointer to the opened file containing Monty bytecode
 */
void interpret(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		process_instruction(line, &stack, line_number);
	}

	free(line);
}

/**
 * process_instruction - Process a single Monty bytecode instruction
 * @line: The instruction string
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void process_instruction(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (!opcode || opcode[0] == '#')
		return;

	handle_opcode(opcode, stack, line_number);
}
