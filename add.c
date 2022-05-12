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
	stack_t *aux = *stack, *aux2;

	if (!(*stack) || !stack || (aux && !aux->next))
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux2 = aux->next->next;

	aux->n += aux->next->n;
	free(aux->next);
	aux->next = aux2;
	aux2->prev = aux;
}
