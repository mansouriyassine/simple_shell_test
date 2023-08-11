#include "shell.h"

/**
 * num_builtins - Get the number of built-in commands
 *
 * Return: The number of built-in commands
 */
int num_builtins(void)
{
return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * launch - Launch a program and execute it
 * @args: The array of arguments
 *
 * Return: 1 to continue running, 0 to exit
 */
int launch(char **args)
{
return (0);
}

/**
 * execute - Execute a program
 * @args: The array of arguments
 *
 * Return: 1 to continue running, 0 to exit
 */
int execute(char **args)
{
return (launch(args));
}

/**
 * loop - Read and execute commands in a loop
 */
void loop(void)
{
char *line;
char **args;
int status;

do {
printf("#cisfun$ ");
line = read_line();
args = split_line(line);
status = execute(args);

free(line);
free(args);
} while (status);
}
