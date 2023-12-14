#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	char *arg;
	int value;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	arg = strtok(NULL, "\t\n");
	if (!arg || (!isdigit(*arg) && *arg != '-'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
