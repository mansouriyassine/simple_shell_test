#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024

/* Struct to store shell information */
typedef struct info_struct
{
char **args;           /* Array of arguments */
char *command;         /* Full command string */
char *input_file;      /* Input file for redirection */
char *output_file;     /* Output file for redirection */
int background;        /* Background flag */
} info_t;

/* Function prototypes */
void print_prompt(void);
char *read_line(void);
info_t *parse_line(char *line);
int execute_command(info_t *info);
void free_info(info_t *info);

#endif /* SHELL_H */
