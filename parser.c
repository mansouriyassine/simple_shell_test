#include "shell.h"
#include <string.h>
#include <stdlib.h>

#define TOK_BUFSIZE 64

/**
 * parse_line - Parse input line into tokens
 * @line: The input line to parse
 *
 * Return: Pointer to shell_info struct containing parsed information
 */
shell_info *parse_line(char *line)
{
int bufsize = TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));

if (!tokens)
{
fprintf(stderr, "Allocation error\n");
return (NULL);
}

char *token = strtok(line, " ");
while (token)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += TOK_BUFSIZE;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
fprintf(stderr, "Allocation error\n");
return (NULL);
}
}

token = strtok(NULL, " ");
}

shell_info *info = malloc(sizeof(shell_info));
if (!info)
{
fprintf(stderr, "Allocation error\n");
return (NULL);
}

info->args = tokens;
info->input_file = NULL;   // Initialize input_file
info->output_file = NULL;  // Initialize output_file
info->background = 0;      // Initialize background

return (info);
}
