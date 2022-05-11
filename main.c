#include "monty.h"
int global;
/**
 * main - main function to create an interpreter Monty ByteCodes files
 * @argc: arg count
 * @argv: args
 * Return: always 0
 */
int main(int argc, char **argv)
{

	char *buffer, *aux = malloc(1024);
	stack_t *stack = NULL;
	unsigned int line = 1, i = 0, j = 0;

	if (argc != 2)
	{
		free(aux);
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	buffer = read_textfile(argv[1]);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			line++;
		else if (buffer[i] != ' ' && buffer[i] != 9)
		{
			j = 0;
			while (buffer[i + 1] != ' ' && buffer[i + 1] != '\n'
					&& buffer[i + 1] != '\0' && buffer[i + 1] != 9)
			{
				aux[j] = buffer[i];
				j++;
				i++;
			}
			aux[j] = buffer[i];
			aux[j + 1] = '\0';
			if (strcmp(aux, "push") == 0)
				i = next_word(buffer, i + 1);
			if (belongs(aux) == 1)
				execute(aux, &stack, line);
		}
		i++;
	}
	free(buffer);
	free(aux);
	return (0);
}

/**
 * next_word - function to set global variable
 * @buffer: buffer
 * @i: i position
 * Return: i
 */
int next_word(char *buffer, unsigned int i)
{
	char *aux = malloc(256 * sizeof(char));
	int j = 0, flag = 0;

	aux[0] = '\0';
	while (buffer[i] != '\n' && buffer[i] && flag == 0)
	{
		while (buffer[i] == ' ' || buffer[i] == 9)
		{
			if (aux[0])
				flag = 1;
			i++;
		}	
		aux[j] = buffer[i];
		i++;
		j++;

	}

	aux[j] = '\0';
	if (strcmp(aux, "0") == 0)
		global = 0;
	else
	{
		j = 0;
		flag = 0;
		while(aux[j])
		{
			if (aux[j] < '0' || aux[j] > '9')
				flag = 1;
			j++;
		}
		global = atoi(aux);
		if (global == 0 || flag == 1)
			global = -255;
	}
	free(aux);
	if (buffer[i] == '\n')
		i--;
	return (i);
}
