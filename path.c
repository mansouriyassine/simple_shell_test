#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * find_command - Find the full path of a command
 * @cmd: The command to find
 * @path: The PATH environment variable
 *
 * Return: The full path of the command, or NULL if not found
 */
char *find_command(const char *cmd, const char *path)
{
if (cmd == NULL || path == NULL)
return (NULL);

char *full_path = NULL;
char *token = strtok((char *)path, ":");

while (token != NULL)
{
size_t len = strlen(token) + strlen(cmd) + 2;
full_path = malloc(len);
if (full_path == NULL)
{
perror("malloc");
return (NULL);
}

sprintf(full_path, "%s/%s", token, cmd);
if (access(full_path, X_OK) == 0)
return (full_path);

free(full_path);
token = strtok(NULL, ":");
}

return (NULL);
}
