#include "monty.h"

/**
 * swap - Swap the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	temp->prev = NULL;

	if ((*stack)->next)
		(*stack)->next->prev = *stack;

	*stack = temp;
}
