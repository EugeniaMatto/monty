#include "monty.h"
/**
 * _rotl - function to push
 * @stack: stack
 * @line_number: line
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack, *new;
	int i;

	if (*stack && aux->next)
	{
		i = (*stack)->n;
		_pop(stack, line_number);
		while (aux->next)
			aux = aux->next;
		new = malloc(sizeof(stack_t));
		new->next = NULL;
		new->n = i;
		new->prev = aux;
		aux->next = new;
	}
}
