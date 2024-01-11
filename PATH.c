#include "main.h"
/**
 * path - prints the path
 * @argv: char
 * @argc: int
 * Return: 0
 */

void path(int argc, char *argv)
{
	char *toks;
	char *path = getenv("PATH");
	char *len_path[MAX_PATH_LEN];
	int count = 0;

	toks = strtok(path, ":");
	while (toks != NULL)
	{

