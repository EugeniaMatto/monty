#include "monty.h"
/**
 * read_textfile - reads a text file
 * @filename: pointer to name file
 * Return: the buffer with content of the file
 */
char *read_textfile(char *filename)
{
	ssize_t fd, lec;
	char *buffer;

	if (!filename)
		exit(EXIT_FAILURE);

	buffer = malloc(1024 * sizeof(char));
	if (!buffer)
	{
		write(STDERR_FILENO, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		free(buffer);
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	lec = read(fd, buffer, 1024);
	close(fd);
	if (lec == -1)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}

	return (buffer);
}
