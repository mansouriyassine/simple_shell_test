#include "shell.h"

/**
 * parse_input - Tokenizes the input line into separate words
 * @info: Pointer to the parameter struct
 *
 * Return: Array of arguments (words)
 */
char **parse_input(info_t *info)
{
size_t i;
char *token;
char **args;

/* Count the number of tokens in the input */
size_t num_tokens = count_tokens(info->cmd_buf, ' ');

/* Allocate memory for the arguments array */
args = malloc((num_tokens + 1) * sizeof(char *));
if (!args)
{
perror("malloc");
return (NULL);
}

/* Tokenize the input and store tokens in the arguments array */
for (i = 0; i < num_tokens; i++)
{
token = _strsep(&(info->cmd_buf), " ");
args[i] = _strdup(token);
if (!args[i])
{
perror("malloc");
free_args(args);
return (NULL);
}
}

/* Set the last element of the arguments array to NULL */
args[i] = NULL;

return (args);
}
