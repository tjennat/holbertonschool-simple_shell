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
		}
		bytesRead = getline(&line, &lineSize, stdin);
		if (bytesRead == -1)
		{
			if (feof(stdin))
				exit(EXIT_SUCCESS);
			perror("Error");
			continue;
		}
		line[bytesRead - 1] = '\0';

		token = strtok(line, " ");
		i = 0;
		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		exec(args);
	}
	free(line);
	return (0);
}
