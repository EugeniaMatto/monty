#include "monty.h"
/**
 * _pall - prints all the elements of list stack_t.
 * @stack: head
 * @line_number: line_number
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	line_number = line_number;
	if (stack && *stack)
	{
		h = *stack;
		while (h->next)
		{
			printf("%d\n", h->n);
			h = h->next;
		}
		if (h)
			printf("%d\n", h->n);
	}
}
