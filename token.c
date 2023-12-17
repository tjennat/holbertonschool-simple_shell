#include "main.h"

void tokenize(char *line, char *args[], size_t max_args)
{
    char *token;
    int i = 0;

    token = strtok(line, " ");
    while (token != NULL && i < max_args - 1)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

