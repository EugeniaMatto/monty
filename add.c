#include "monty.h"

global_t gl;
/**
 * _add - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line num
 * Return: void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (!*stack || !aux->next)
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = aux->next;
	aux->n = aux->n + (*stack)->n;
	_pop(stack, line_number);
}
