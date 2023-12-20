#define _GNU_SOURCE
#include "main.h"

int main(void)
{
	char *line = NULL;
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
		if (bytesRead == EOF)
		{
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
		if (args[0] != NULL && strcmp(args[0], "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		exec(args);
		memset(args, 0, sizeof(args));
	}
	free(line);
	return (0);
}
