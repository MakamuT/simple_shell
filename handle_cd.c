#include "main.h"
#define SIZE_C 1024
/**
 * handle_cd - Changes the current directory of the process
 * @dir: directory
 * Return: void
 */
void handle_cd(const char *dir)
{
	char *home_dir = getenv("HOME");
	char *pwd = getenv("PWD");
	char cwd[SIZE_C], *dir_cp = NULL;

	if (dir == NULL || _strcmp(dir, "~") == 0)
	{
		if (home_dir != NULL)
			dir_cp = strdup(home_dir);
		else
			return;
	}
	else if (_strcmp(dir, "-") == 0)
	{
		if (pwd != NULL)
			dir_cp = strdup(pwd);
		else
			return;
	} else
		dir_cp = strdup(dir);
	if (dir_cp == NULL)
	{
		perror("strdup() error");
		return;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		free(dir_cp);
		return;
	}
	if (chdir(dir) != 0)
	{
		perror("chdir() error");
		free(dir_cp);
		return;
	}
	free(dir_cp);
}
