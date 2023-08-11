#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
char *line;
info_t *info;

while (1)
{
print_prompt();
line = read_line();
if (line == NULL)
break;
info = parse_line(line);
if (info == NULL)
{
free(line);
continue;
}
execute_command(info);
free_info(info);
free(line);
}

return (0);
}
