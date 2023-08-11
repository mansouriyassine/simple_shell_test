#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * error_message - Print an error message to stderr
 * @format: The format string
 * @...: The arguments to format
 */
void error_message(const char *format, ...)
{
va_list args;

va_start(args, format);
vfprintf(stderr, format, args);
va_end(args);
}

/**
 * exit_error - Print an error message to stderr and exit
 * @format: The format string
 * @...: The arguments to format
 */
void exit_error(const char *format, ...)
{
va_list args;

va_start(args, format);
vfprintf(stderr, format, args);
va_end(args);

exit(EXIT_FAILURE);
}
