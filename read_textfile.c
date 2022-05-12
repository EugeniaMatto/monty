#include "monty.h"
/**
 * read_textfile - reads a text file
 * @filename: pointer to name file
 * Return: the buffer with content of the file
 */
FILE *read_textfile(char *filename)
{
	FILE *fd;

	fd = fopen(filename, "r");

	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
