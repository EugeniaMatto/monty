#include "monty.h"

/**
 * _pchar - prints the value at the top of the stack, followed by a new line.
 * @stack: stack head
 * @line_number: line num
 * Return: void
 */

void _pchar(stack_t **stack, unsigned int line_number)
{

	if (!(*stack))
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) <= 0 || ((*stack)->n) > 127)
	{
	dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
