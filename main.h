#ifndef MAIN_H
#define MAIN_H

#define MAX_ARGS 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

void exec(char **args);
extern char **environ;
void tokenize(char *line, char *args[], size_t max_args);
char *find_path(char *command);

#endif
