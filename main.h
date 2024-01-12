#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

extern char **environ;
int _putchar(char n);
int prompt(int argc, char **argv);
int test_main(int argc, char *argv[]);
ssize_t _getline(char **line, size_t *len, FILE *stream);

/***SHELL***/
void execmd(char **argv);
void handle_exit(int status);
void handle_env(void);
void file_cmd(const char *filename);
void shell_cmd(char **cmd);
void handle_cd(const char *dir);
void handle_setenv(char **args);
void handle_unsetenv(char **args);
int handle_ls(const char *dir);

/********UTILS*********/
int _strcmp(const char *s1, const char *s2);
int _strlen(char *s);

#endif
