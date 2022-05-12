#include "monty.h"
global_t gl;
/**
 * next_word - function to set global variable
 * @word: buffer
 * Return: void
 */
void next_word(char *word)
{
	int j = 0, flag = 0, global;

	if (!word)
	{
		gl.n = -255;
		return;
	}

	if (strcmp(word, "0") == 0)
		global = 0;
	else
	{
		if (word[0] == '-')
			j++;
		while (word[j])
		{
			if (word[j] < '0' || word[j] > '9')
				flag = 1;
			j++;
		}
		global = atoi(word);
		if (global == 0 || flag == 1 || word == NULL)
			global = -255;
	}
	gl.n = global;
}
