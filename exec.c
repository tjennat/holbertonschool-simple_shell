#include "main.h"

/**
 *
 *
 */

void exec(char **args)
{
	char *line = NULL;
	int status;
	pid_t childPid;

	childPid = fork();
	if (childPid == -1)
		perror("fork");

	else if (childPid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			free(line);
			free(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
