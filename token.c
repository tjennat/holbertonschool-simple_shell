#include "main.h"

/**
 * tokenize - tokenizes a string
 * @line: string to tokenize
 * @args: array of strings to store tokens
 * @max_args: max number of tokens to store
 *
 * Return: void
 */

void tokenize(char *line, char *args[], size_t max_args)
{
	char *token;
	unsigned int i = 0;

	token = strtok(line, " ");
	while (token != NULL && i < max_args - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
