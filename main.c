#include "monty.h"
/**
 * main - main function to create an interpreter Monty ByteCodes files
 * @argc: arg count
 * @argv: args
 */
int main(int argc, char **argv){

	char *buffer, *aux = malloc(1024);
	unsigned int line = 1, i = 0, j = 0;
/*	instruction_t ins[] = {
		{"push", _push},
		{"pop", _pop},
		{"pall", _pall},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop}
	};*/

	if (argc != 2)
	{
		free(aux);
		write(STDERR_FILENO ,"USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	buffer = read_textfile(argv[1]);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			line++;
		}
		else if (buffer[i] != ' ')
		{
			j = 0;
			while(buffer[i + 1] != ' ' && buffer[i + 1] != '\n')
			{
				aux[j] = buffer[i];
				j++;
				i++;
			}
			aux[j] = buffer[i];
			aux[j + 1] = '\0';
			printf("aux : %s\n", aux);
			if (strcmp(aux, "push") == 0)
				next_word(buffer, i + 1);
		}
		i++;
	}
}

void next_word(char *buffer, unsigned int i)
{
	char *global, *aux = malloc(256 * sizeof(char));
	int j = 0, flag = 0;

	while(buffer[i] != '\n' && buffer[i])
	{
		while(buffer[i] == ' ')
			i++;
		if (flag == 1)
			break;
		flag = 1;
		aux[j] = buffer[i];
		i++;
		j++;

	}

	aux[j] = '\0';
	printf("NEXT: %s\n", aux);
	free(aux);
}
