#include "shell.h"

/**
 * save_history - Saves a command to the history file
 * @cmd: The command to save
 *
 * Return: 1 on success, 0 on failure
 */
int save_history(char *cmd)
{
FILE *file;

/* Open the history file in append mode */
file = fopen(HISTORY_FILE, "a");
if (!file)
{
perror("fopen");
return (0);
}

/* Write the command to the history file */
fprintf(file, "%s\n", cmd);

/* Close the history file */
fclose(file);

return (1);
}
