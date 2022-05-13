#include "monty.h"

global_t gl;
/**
 * _mul - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line num
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (aux && aux->next)
	{
		aux = aux->next;
		aux->n = aux->n * (*stack)->n;
		_pop(stack, line_number);
	}
	else
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
