#include "monty.h"

global_t gl;
/**
 * _div - div the top two elements of the stack.
 * @stack: stack head
 * @line_number: line num
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (aux && aux->next)
	{
		aux = aux->next;
		if ((*stack)->n == 0)
		{
			free(gl.buffer), free_list(*stack), fclose(gl.fd);
			dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		aux->n = aux->n / (*stack)->n;
		_pop(stack, line_number);
	}
	else
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
