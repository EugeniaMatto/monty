#include "monty.h"
int global;
/**
 * _push - function to push
 * @stack: stack
 * @line_number: line
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int a = global;

	if (a != -255)
	{
		add_nodo(stack, a);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction\n", line_number);
		exit(EXIT_FAILURE);
	}
}

void add_nodo(stack_t **stack, int a)
{
	stack_t *new = malloc(sizeof(stack_t)), *aux;

	new->n = a;
	new->prev = NULL;
	if (!stack || !(*stack))
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		aux = *stack;
		aux->prev = new;
		new->next = aux;
		*stack = new;
	}
}
