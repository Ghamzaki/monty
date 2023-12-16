#include "monty.h"

/**
 * pop - Remove the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
