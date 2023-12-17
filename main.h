#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void exec(char **args);
extern char **environ;
void tokenize(char *line, char *args[], size_t max_args);

#endif
