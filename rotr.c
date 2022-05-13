#include "monty.h"
/**
 * _push - function to push
 * @stack: stack
 * @line_number: line
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *list = NULL, *aux = *stack;

	line_number = line_number;
	if (aux->next)
	{
		while(aux)
		{
			add_nodo(&list, aux->n);
			aux = aux->next;
		}
		free(*stack);
		*stack = list;
	}
}
