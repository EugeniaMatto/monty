#include "monty.h"
/**
 * errounk - asdi
 * @line: line
 * @aux: aux
 */
void errounk(unsigned int line, char *aux)
{
	int i = 0;

	while (aux[i])
	{
		if (aux[i] == ' ')
			break;
	i++;
	}
	dprintf(2, "L%u: unknown instruction %s\n", line, aux);
	aux[i] = ' ';
	free(aux);
	exit(EXIT_FAILURE);
}
