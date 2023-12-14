#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	bus_t bus = {NULL, NULL, NULL, 0};
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	bus.file = fopen(argv[1], "r");

	if (!bus.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit("EXIT_FAILURE");
	}

	while (getline(&bus.content, &bus.size, bus.file) > 0)
	{
		line_number++;

		if (bus.content)
		{
			execute(bus.content, &stack, counter, bus.file);
		}

		free(bus.content);
	}

	free_stack(stack);
	fclose(bus.file);

	return (0);
}
