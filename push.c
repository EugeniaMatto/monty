#include "monty.h"
global_t gl;
/**
 * _push - function to push
 * @stack: stack
 * @line_number: line
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int a = gl.n;

	if (a != -255)
	{
		if (gl.mode == 's')
			add_nodo(stack, a);
		else
			add_dnodeint_end(stack, a);
	}
	else
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * add_nodo - function to push
 * @stack: stack
 * @a: line
 * Return: void
 */
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
