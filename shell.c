#define _GNU_SOURCE

#include "main.h"

#define MAX_ARGS 64


int main(void)
{
	int i;
	char *line = NULL, *token;
	char *args[MAX_ARGS];
	size_t lineSize = 0;
	ssize_t bytesRead;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		bytesRead = getline(&line, &lineSize, stdin);
		if (bytesRead == -1)
		{
			if (feof(stdin))
			{
				free(line);
				exit(EXIT_SUCCESS);
			}	
			free(line);	
			perror("Error");
			continue;

		}
		line[bytesRead - 1] = '\0';

		tokenize(line, args, MAX_ARGS);
		exec(args);
	}
	free(line);
	return (0);
}
