#ifndef S_SHELL_H
#define S_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

void prompt_handler(void);
void handle_signal(int signals);
void handle_eof(char *buffer);
void handle_exit(char **input_command);
void execute_child(char **command, char *shell_name, char **envp, int loops);
int dir_changes(const char *path);
void execute_command(char **command, char *name, char **env, int cicles);
void print_env(char **env);
char **_dirsPATH(char **env);
void command_error(char *name, int loops, char **command);
char **tokenize(char *buffer, const char *delim);
void free_memory(char **command);
void freeMem_and_exit(char **command);
int _strcmp(char *str1, char *str2);
unsigned int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strint(char *s);
char *_strcat(char *dest, char *src);
char *_strchr(const char *str, const char c);
int _strspn(const char* s, const char* charset);

char *read_ia(void);
char **parse(char *in_str);
int execute(char **in_arr, char *self, char **env, int cyc);
int count_tokens(const char *str, const char *dlm);
char *search_cmd(char *str, char **env);

#endif
