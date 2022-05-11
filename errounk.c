#include "monty.h"
/**
 * errounk - asdi
 * @line: line
 * @aux: aux
 */
void errounk(unsigned int line, char *aux)
{
	dprintf(2, "L%u: unknown instruction %s\n", line, aux);
	free(aux);
	exit(EXIT_FAILURE);
}
