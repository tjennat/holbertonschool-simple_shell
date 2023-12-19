#include "main.h"


void exec(char **args)
{
	char *line = NULL;
	int status;
	pid_t childPid;
	char *command_path;

	command_path = find_path(args[0]);
	if (access(args[0], X_OK) != 0)
	{
		if (command_path == NULL)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			return;
		}
	}
	childPid = fork();
	if (childPid == -1)
		perror("fork");

	else if (childPid == 0)
	{
		if (execve(command_path, args, environ) == -1)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			free(line);
			free(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free(command_path);
}
