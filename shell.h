#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Shell info struct */
typedef struct {
char **args;
char *input_file;
char *output_file;
int background;
} shell_info;

/* Function prototypes */
void print_prompt(void);
char *read_line(void);
shell_info *parse_line(char *line);
int execute_command(shell_info *info);
void free_info(shell_info *info);
int builtin_cd(char **args);
int builtin_exit(char **args);
int builtin_env(char **args);
int builtin_history(char **args);

#endif /* SHELL_H */
