#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_to_history - Add a command to the history
 * @command: The command to add
 * @history: Array to store command history
 * @size: Size of the history array
 * @index: Current index in the history array
 */
void add_to_history(char *command, char **history, int size, int *index) {
// Implementation to add a command to history
if (*index < size) {
history[*index] = strdup(command);
(*index)++;
} else {
free(history[0]);
for (int i = 0; i < size - 1; i++) {
history[i] = history[i + 1];
}
history[size - 1] = strdup(command);
}
}

/**
 * print_history - Print the command history
 * @history: Array containing command history
 * @size: Size of the history array
 */
void print_history(char **history, int size) {
// Implementation to print command history
for (int i = 0; i < size; i++) {
if (history[i] != NULL) {
printf("%s\n", history[i]);
}
}
}

/**
 * free_history - Free memory used for history
 * @history: Array containing command history
 * @size: Size of the history array
 */
void free_history(char **history, int size) {
// Implementation to free memory used for history
for (int i = 0; i < size; i++) {
free(history[i]);
}
free(history);
}
