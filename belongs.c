#include "monty.h"
/**
 * belongs - check if aux belongs to words admited
 * @aux: word
 * Return: 1 if belongs, else 0
 */
int belongs(char *aux)
{
	int r = 0, i = 0;
	char words[][13] = {"push", "pop", "pall", "pint", "swap", "add", "nop",
		"sub", "div", "mul", "mod", "pchar", "rotl"};

	while (i < 13)
	{
		if (strcmp(aux, words[i]) == 0)
			return (1);
		i++;
	}

	return (r);
}
