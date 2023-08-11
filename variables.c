#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * set_variable - Set an environment variable
 * @name: The name of the variable
 * @value: The value of the variable
 */
int set_variable(const char *name, const char *value)
{
if (name == NULL || value == NULL)
return (1);

char *new_var = malloc(strlen(name) + strlen(value) + 2);
if (new_var == NULL)
{
perror("malloc");
return (1);
}

sprintf(new_var, "%s=%s", name, value);

if (putenv(new_var) != 0)
{
perror("putenv");
free(new_var);
return (1);
}

return (0);
}

/**
 * print_variables - Print all environment variables
 */
void print_variables(void)
{
extern char **environ;
char **env = environ;

while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
}

/**
 * get_variable - Get the value of an environment variable
 * @name: The name of the variable
 *
 * Return: The value of the variable, or NULL if not found
 */
char *get_variable(const char *name)
{
extern char **environ;
char **env = environ;
size_t name_len = strlen(name);

while (*env != NULL)
{
if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
return (*env + name_len + 1);
env++;
}

return (NULL);
}

/**
 * delete_variable - Delete an environment variable
 * @name: The name of the variable
 */
int delete_variable(const char *name)
{
if (unsetenv(name) != 0)
{
perror("unsetenv");
return (1);
}
return (0);
}
