#include "main.h"

/**
 * exec - executes the input received
 * @args: arguments to execute
 * Return: void
 */
void exec(char **args)
{
	char *line = NULL;
	int status, statusExit;
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
	if (WIFEXITED(status))
	{
		statusExit = WEXITSTATUS(status);
		if (statusExit != 0)

			free(command_path);
	}
}
