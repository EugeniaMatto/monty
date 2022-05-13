#include "monty.h"
global_t gl;
/**
 * main - main function to create an interpreter Monty ByteCodes files
 * @argc: arg count
 * @argv: args
 * Return: always 0
 */
int main(int argc, char **argv)
{
	char *buffer;
	FILE *fd;
	int line = 0;
	size_t l = 1024, gt = 0;
	stack_t *a = NULL;

	gl.mode = 's';
	if (argc != 2)
		erroargv();
	fd = read_textfile(argv[1]);
	buffer = malloc(1024);
	while (1)
	{
		gt = getline(&buffer, &l, fd);
		if (gt == (size_t) -1)
			break;
		line++;
		buffer[gt - 1] = '\0';
		if (isEmpty(buffer) == 0 && buffer[0] != '\0')
			get_command(buffer, line, &a, fd);
	}
	free(buffer), free_list(a), fclose(fd);
	return (0);
}
