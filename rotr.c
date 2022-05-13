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
	/*int i;*/

	if (aux->next)
	{
		while(aux)
		{
			add_nodo(&list, aux->n);
			aux = aux->next;
		}
		/*i = list->n;*/
		printf("\n\n---list--");
		_pall(&list, line_number);
		printf("----\n\n");
		*stack = list;
	}
}
