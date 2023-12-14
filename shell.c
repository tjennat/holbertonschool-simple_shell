#define _GNU_SOURCE

#include "main.h"

#define MAX_ARGS 64

extern char **environ;

int main(void)
{
	int status, i;
	char *line = NULL, *token;
	char *args[MAX_ARGS];
	size_t lineSize = 0;
	ssize_t bytesRead;
	pid_t childPid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			bytesRead = getline(&line, &lineSize, stdin);
		}
		if (bytesRead == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			}
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

		childPid = fork();
		if (childPid == -1)
		{
			perror("fork");
			continue;
		}
		else if (childPid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				continue;
		}
		free(line);
		return (0);
	}
}
