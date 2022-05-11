#include "monty.h"
/**
 * erroargv - asd
 * @aux: aux
 */
void erroargv(char *aux)
{
	free(aux);
	write(STDERR_FILENO, "USAGE: monty file\n", 18);
	exit(EXIT_FAILURE);
}
