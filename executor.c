#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

/**
 * execute - Execute commands in child process
 * @info: Pointer to shell_info struct containing command information
 *
 * Return: 0 on success, 1 on failure
 */
int execute(shell_info *info)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork");
return (1);
}
else if (pid == 0)
{
if (info->input_file)
{
freopen(info->input_file, "r", stdin);
}
if (info->output_file)
{
freopen(info->output_file, "w", stdout);
}

execvp(info->args[0], info->args);
perror("execvp");
exit(1);
}
else
{
int status;
waitpid(pid, &status, 0);
}

return (0);
}
