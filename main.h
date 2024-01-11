#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

extern char **environ;

int _putchar(char n);
int prompt(int argc, char **argv);
int test_main(int argc, char *argv[]);

void execmd(char **argv);
void handle_exit(void);
void handle_env(void);
void file_cmd(const char *filename);
void shell_cmd(char **cmd);
void handle_cd(const char *dir);

/********UTILS*********/
int _strcmp(const char *s1, const char *s2);

#endif
