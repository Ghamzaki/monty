#include "monty.h"

/**
 * handle_opcode - Dispatches the appropriate function based on the opcode
 * @opcode: The opcode to be handled
 * @stack: Pointer to the stack
 * @l_no: Line number of the instruction
 */
void handle_opcode(char *opcode, stack_t **stack, unsigned int l_no)
{
	char *value_str;
	int value;

	if (strcmp(opcode, "push") == 0)
	{
		value_str = strtok(NULL, " \t\n");
		if (!value_str)
		{
			fprintf(stderr, "L%u: usage: push integer\n", l_no);
			exit(EXIT_FAILURE);
		}

		value = atoi(value_str);
		push(stack, value);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, l_no);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, l_no);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, l_no);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, l_no);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, l_no);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", l_no, opcode);
		exit(EXIT_FAILURE);
	}
}
