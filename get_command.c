#include "monty.h"
global_t gl;
/**
 * get_command - geT_command
 * @buffer: buffer
 * @line: line
 * @a: stack
 * @fd: file descriptor
 * Return: void
 */
void get_command(char *buffer, int line, stack_t **a, FILE *fd)
{
	int pase = 0, command = 0, flag = 0;
	char *token;

	token = strtok(buffer, " \t");
	gl.buffer = buffer;
	gl.fd = fd;
	while ((token || flag == 1) && command == 0)
	{
		if (token[0] == '#')
			return;
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
		fclose(fd);
		free_list(*a);
		errounk(line, buffer);
	}
}
