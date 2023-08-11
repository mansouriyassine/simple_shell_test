#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HISTORY_SIZE 10

/**
 * struct HistoryNode - Structure to hold history nodes
 * @command: The command string
 * @next: Pointer to the next node in the history
 */
typedef struct HistoryNode
{
char *command;
struct HistoryNode *next;
} HistoryNode;

HistoryNode *history_head = NULL;
HistoryNode *history_tail = NULL;

/**
 * add_to_history - Add a command to the history
 * @command: The command string to add
 */
void add_to_history(const char *command)
{
if (command == NULL || *command == '\0')
return;

// Allocate memory for the new node
HistoryNode *new_node = malloc(sizeof(HistoryNode));
if (new_node == NULL)
{
perror("malloc");
return;
}

// Duplicate the command and add to history
new_node->command = strdup(command);
if (new_node->command == NULL)
{
perror("strdup");
free(new_node);
return;
}

new_node->next = NULL;

// Add the new node to the history
if (history_tail == NULL)
{
history_head = new_node;
history_tail = new_node;
}
else
{
history_tail->next = new_node;
history_tail = new_node;
}

// Remove oldest entry if history size exceeds limit
if (history_size() > HISTORY_SIZE)
{
HistoryNode *temp = history_head;
history_head = history_head->next;
free(temp->command);
free(temp);
}
}

/**
 * print_history - Print the history of commands
 */
void print_history(void)
{
int count = 1;
HistoryNode *current = history_head;
while (current != NULL)
{
printf("%d: %s\n", count, current->command);
current = current->next;
count++;
}
}

/**
 * free_history - Free the memory used by the history
 */
void free_history(void)
{
HistoryNode *current = history_head;
while (current != NULL)
{
HistoryNode *temp = current;
current = current->next;
free(temp->command);
free(temp);
}
history_head = NULL;
history_tail = NULL;
}

/**
 * history_size - Get the number of commands in history
 *
 * Return: The number of commands in history
 */
int history_size(void)
{
int size = 0;
HistoryNode *current = history_head;
while (current != NULL)
{
size++;
current = current->next;
}
return (size);
}
