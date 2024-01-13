#include "main.h"
/**
 * exit_status - handles the exit status for handle_exit
 * @status: exit status
 * Return: void
 */
static void exit_status(char *status)
{
	int exit_code = 0;

	if (status != NULL)
		exit_code = atoi(status);
	exit(exit_code);
}

/**
 * exec_exit - handles the built-in exit command
 * @status: exit status
 * Return: void
 */
void exec_exit(char *status)
{
	exit_status(status);
}
