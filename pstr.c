#include "monty.h"

/**
 * _pstr - prints the string starting at
 * the top of the stack, followed by a new line.
 * @stack: stack head
 * @line_number: line num
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	line_number = line_number;

	if (*stack || stack)
	{
		while (temp && temp->n != 0)
		{
			if ((temp->n <= 0 || temp->n > 127))
			{
				break;
			}
			putchar(temp->n);
			temp = temp->next;
		}
		printf("\n");
	}
	else
	printf("\n");
}
