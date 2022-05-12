#include "monty.h"
/**
 * main - main function to create an interpreter Monty ByteCodes files
 * @argc: arg count
 * @argv: args
 * Return: always 0
 */
int main(int argc, char **argv)
{
	char *buffer, *fword;
	FILE *fd;
	int line = 0;
	size_t l = 1024, gt = 0;
	stack_t *a = NULL;

	if (argc != 2)
		erroargv();
	fd = read_textfile(argv[1]);
	buffer = malloc(1024);
	fword = malloc(256);
	while (1)
	{
		gt = getline(&buffer, &l, fd);
		if (gt == (size_t) -1)
			break;
		line++;
		buffer[gt - 1] = '\0';
		if (isEmpty(buffer) == 0 && buffer[0] != '\0')
			get_command(buffer, fword, line, &a);
	}
	free(fword);
	free(buffer);
	return (0);
}
