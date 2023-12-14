#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>

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
	char *opcode, *value_str;
	int value;
	stack_t *stack = NULL;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		opcode = strtok(line, " \t\n");
		if (!opcode || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			value_str = strtok(NULL, " \t\n");
			if (!value_str)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}

			value = atoi(value_str);
			push(&stack, value, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
}
