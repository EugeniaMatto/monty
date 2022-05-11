#include "monty.h"
/**
 * execute - execute function that belongs to a opcode
 * @aux: opcode
 * @stack: stack
 * Return: void
 */
void execute(char *aux, stack_t **stack, unsigned int line)
{
	int i = 0;
	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	while (ins[i].opcode)
	{
		if (strcmp(aux, ins[i].opcode) == 0)
			ins[i].f(stack, line);
		i++;
	}
}
