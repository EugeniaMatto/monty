#include "monty.h"

global_t gl;
/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: stack head
 * @line_number: line num
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !stack)
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
