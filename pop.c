#include "monty.h"

global_t gl;

/**
 * _pop - removes the top element of the stack.
 * @stack: stack head
 * @line_number: line num
 * Return: void
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (!(*stack) || !stack)
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->next == NULL)
	{
		*stack = NULL;
	}
	else
	{
		*stack = temp->next;
		temp->next->prev = NULL;
	}
	free(temp);
}
