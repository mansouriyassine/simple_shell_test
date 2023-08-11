#include "shell.h"

/**
 * execute_command - Execute a command in the shell.
 * @command: The command to execute.
 *
 * Return: Always 0.
 */
int execute_command(char **command)
{
pid_t child_pid;
int status;

child_pid = fork();
if (child_pid == -1)
{
perror("fork");
return (EXIT_FAILURE);
}
if (child_pid == 0)
{
/* Child process */
if (execve(command[0], command, environ) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
/* Parent process */
waitpid(child_pid, &status, WUNTRACED);
}

return (0);
}
