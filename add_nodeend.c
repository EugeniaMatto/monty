#include "monty.h"
/**
 * add_dnodeint_end - adds a new node at the end
 * @head: head
 * @n: value new node
 * Return: new node adress
 */
stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *new = NULL, *aux = *head;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head)
	{
		while (aux->next)
		{
			aux = aux->next;
		}
		aux->next = new;
		new->prev = aux;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
}
