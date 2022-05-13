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
	stack_t *node = *stack, *next_node;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		next_node = node->next;
		node->prev = *stack;
		node->next = next_node->next;
		next_node->prev = NULL;
		next_node->next = node;
		(*stack) = next_node;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
