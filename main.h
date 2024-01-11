#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
<<<<<<< HEAD
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
=======
#include <fcntl.h>
>>>>>>> e39923efb09d1203883d5db97b9837c7d04e7b79

extern char **environ;
int _putchar(char n);
int prompt(int argc, char **argv);
int test_main(int argc, char *argv[]);

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
