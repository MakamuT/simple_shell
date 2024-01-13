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

#define MAX_ALIASES 100

/**
 * struct Alias - stores alias mapping
 * @name: alias name
 * @value: alias value
 *
 * Description: struct called "Alias" that stores
 * the mapping of an alias
 */
struct Alias
{
	char *name;
	char *value;
};

/**
 * struct Envar - stores environment variables
 * @name: name
 * @value: value
 *
 * Description: struct called "Envar" that stores
 * environment variables
 */
struct Envar
{
	char *name;
	char *value;
};

/*** vars ***/
extern char **environ;

/*** Utility prototypes ***/
int _putchar(char n);
ssize_t _getline(char **line, size_t *len, FILE *stream);
void prompt(void);
char *read_line(void);
char *parse_cmd(char *cmd);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strchr(const char *str, int c);
size_t _strspn(const char *str, const char *sset);
size_t _strcspn(const char *str, const char *sset);
char *_strtok(char *str, const char *delim);
char *_getenv(const char *name);
char *_strdup(char *s);
char *_strstr(const char *haystack, const char *needle);
int _strncmp(const char *s1, const char *s2, size_t n);

/***SHELL***/
void execmd(char *argv);
void p_pid(void);
void exec_exit(char *status);
void exec_env(void);
void exec_cd(char *dir);
void exec_setenv(char *args);
void exec_unsetenv(char *args);
void exec_alias(char *args);
void logical_ops(char *args);
void file_cmd(const char *filename);

#endif
