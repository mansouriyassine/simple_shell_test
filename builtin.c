#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
if (!args[1])
{
fprintf(stderr, "cd: expected argument\n");
return (1);
}

if (chdir(args[1]) != 0)
{
perror("cd");
return (0);
}

return (1);
}

/**
 * builtin_exit - Exit the shell
 * @args: Array of arguments (including the command)
 *
 * Return: 0 on success, -1 on failure
 */
int builtin_exit(char **args)
{
if (args[1])
{
int status = atoi(args[1]);
exit(status);
}
exit(0);
}

/**
 * execute_builtin - Execute a built-in command
 * @args: Array of arguments (including the command)
 *
 * Return: 1 if a built-in was executed, 0 otherwise
 */
int execute_builtin(char **args)
{
int i, num_builtins;
builtin_func builtin_functions[] = {
{"cd", builtin_cd},
{"exit", builtin_exit},
};

num_builtins = sizeof(builtin_functions) / sizeof(builtin_func);

for (i = 0; i < num_builtins; i++)
{
if (strcmp(args[0], builtin_functions[i].cmd) == 0)
{
return (builtin_functions[i].func(args));
}
}

return (0);
}
