#include "monty.h"
/**
 * get_command - geT_command
 * @buffer: buffer
 * @fword: fword
 * @line: line
 * Return: void
 */
void get_command(char *buffer, char *fword, int line, stack_t **a)
{
	int pase = 0, command = 0, flag = 0;
	char *token;

	token = strtok(buffer, " \t");
	strcpy(fword, token);
	while ((token || flag == 1) && command == 0)
	{
		pase = 1;
		flag = 0;
		if (belongs(token) == 1)
		{
			if (strcmp("push", token) == 0)
			{
				flag = 1;
				token = strtok(NULL, " \t");
				next_word(token);
				execute("push", a, line);
			}
			else
				execute(token, a, line);
			command = 1;
			}
			token = strtok(NULL, " \t");
	}
	if (command == 0 && pase == 1)
	{
		free(buffer);
		free(fword);
		errounk(line, fword);
	}
}
