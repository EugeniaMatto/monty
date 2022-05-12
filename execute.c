#include "monty.h"
/**
 * execute - execute function that belongs to a opcode
 * @aux: opcode
 * @stack: stack
 * @line: line
 * Return: int always 1
 */
int execute(char *aux, stack_t **stack, unsigned int line)
{
	int i = 0;
	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{NULL, NULL}
	};

	while (ins[i].opcode)
	{
		if (strcmp(aux, ins[i].opcode) == 0)
		{
			ins[i].f(stack, line);
			break;
		}
		i++;
	}
	return (1);
}
