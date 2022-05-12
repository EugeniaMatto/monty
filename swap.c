#include "monty.h"

global_t gl;
/**
 * _swap - swaps the top two elements of the stack.
 * @stack: stack head
 * @line_number: line num
 * Return: void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp->next == NULL || !stack || !(*stack))
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->prev = temp->next->next->prev;
	temp->next->next->prev = *stack;
	temp->next = temp->next->next;
	temp->next->next = *stack;
	temp->next->prev = NULL;
	*stack = temp->next;
}
