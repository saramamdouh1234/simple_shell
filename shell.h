#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>

#define BUFFER_LEN 1024

/* GLOBAL VAR*/
char *_strcat(char *des, const char *sorc);
char *_strcpy(char *des, const char *sorc);
char *to_str(int num, int base);
int _strlen(char *s);
void print_not_found(char *shell, int counter, char *cmd);
char *duplicate_str(char *src);
char *_getpath(char *env[]);
char *is_in_path(char *command, char **env);
int is_exit(char *tokens, char *exitcode, int lasterror,
char *freeme1, char *s, int c);
int execute_command(char *command, char **argv,
char **envp, int lasterorr, int counter);
int main(int argc, char *argv[], char *envp[]);
int _atoi(char *s);
int is_adigit(char *s);
int is_env(char *cmd, char **envp);
void print_illigal(char *s, char *exitcode, int c);
int mypart(char *firstcmd, char *command, char *fullpath,
char **argv, char **envp, int counter, char *tokens);









#endif
