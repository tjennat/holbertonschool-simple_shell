#include "main.h"

char *find_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy, *token;
	char *path_buffer;
	struct stat st;

	if (access(command, F_OK) == 0)
	{
		return strdup(command);
	}
	if (path == NULL)
	{
		fprintf(stderr, "PATH variable not set\n");
		return (NULL);
	}

	path_copy = strdup(path);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		path_buffer = malloc(strlen(token) + strlen(command) + 2);
		sprintf(path_buffer, "%s/%s", token, command);

		if (stat(path_buffer, &st) == 0)
		{
			free(path_copy);
			return (path_buffer);
		}

		free(path_buffer);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
