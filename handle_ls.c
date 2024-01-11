#include "main.h"
#include <dirent.h>
/**
 * handle_ls - prints a list of directories
 * @dir: directory
 * Return: 0 on success, -1 on failure
 */
int handle_ls(const char *dir)
{
	DIR *pdir;
	struct dirent *start;

	pdir = opendir(dir);
	if (pdir == NULL)
		return (-1);
	while ((start = readdir(pdir)) != NULL)
		printf("%s ", start->d_name);
	printf("\n");
	closedir(pdir);
	return (0);
}
