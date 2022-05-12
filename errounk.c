#include "monty.h"
/**
 * errounk - asdi
 * @line: line
 * @aux: aux
 */
void errounk(unsigned int line, char *aux)
{
	dprintf(2, "L%u: unknown instruction %s\n", line, aux);
	exit(EXIT_FAILURE);
}
