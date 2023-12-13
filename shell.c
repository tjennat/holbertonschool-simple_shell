#define _GNU_SOURCE

#include "main.h"

/**
 * main - program that mimic a super simple shell
 * Return: 0
 */

int main(void)
{
	int status;
	char *path = NULL;
	char *args[] = {path, NULL};
	size_t pathSize = 0;
	ssize_t bytesRead;
	pid_t childPid;

	while (1)
	{
		printf("$ ");
		bytesRead = getline(&path, &pathSize, stdin);
		if (bytesRead == -1)
		{
			perror("Error");
			if (feof(stdin))
				break;
		}
		path[bytesRead - 1] = '\0';

		childPid = fork();
		if (childPid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (childPid == 0)
		{
			if (execve(path, args, NULL) == -1)
			{
				perror("execve");
				free(path);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	free(path);
	return (0);
}
