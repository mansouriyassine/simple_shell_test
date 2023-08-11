#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/**
 * handle_signal - Handle a signal
 * @sig: The signal to handle
 */
void handle_signal(int sig)
{
if (sig == SIGINT)
{
putchar('\n');
print_prompt();
}
}

/**
 * setup_signals - Set up signal handlers
 */
void setup_signals(void)
{
struct sigaction sa;

sa.sa_handler = handle_signal;
sa.sa_flags = SA_RESTART;
sigaction(SIGINT, &sa, NULL);
}
