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
 * builtin_cd - Change the current working directory
 * @args: Array of arguments (including the command)
 *
 * Return: 1 on success, 0 on failure
 */
int builtin_cd(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "cd: missing argument\n");
return (0);
}

if (chdir(args[1]) != 0)
{
perror("cd");
return (0);
}

return (1);
}

/**
 * execute - Execute a program
 * @args: The array of arguments
 *
 * Return: 1 to continue running, 0 to exit
 */
int execute(char **args)
{
if (args[0] == NULL)
{
// Empty command, do nothing
return (1);
}

return (0);
}

/**
 * loop - Read and execute commands in a loop
 */
void loop(void)
{
char *line;
char **args;
int status;

do
{
printf("#cisfun$ ");
line = read_line();
args = split_line(line);
status = execute(args);

free(line);
free(args);
} while (status);
}
