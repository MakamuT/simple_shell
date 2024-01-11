#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

extern char **environ;
int _putchar(char n);
int prompt(int argc, char **argv);
void execmd(char **argv);
void handle_exit(void);
void handle_env(void);

#endif
