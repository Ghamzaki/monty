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
	char *opcode, *value_str;
	int value;


	opcode = strtok(line, " \t\n");
	if (!opcode || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		value_str = strtok(NULL, " \t\n");
		if (!value_str)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		value = atoi(value_str);
		push(stack, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
