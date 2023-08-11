#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>

/**
 * struct builtin_func - Struct for built-in commands
 * and their functions
 * @cmd: The command name
 * @func: The corresponding function to execute the command
 */
typedef struct builtin_func
{
char *cmd;
int (*func)(char **);
} builtin_func;

/* Function prototypes */
void loop(void);
char *read_line(void);
char **split_line(char *line);
int launch(char **args);
int execute(char **args);

#endif /* SHELL_H */
