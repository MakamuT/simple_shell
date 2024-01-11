#include "main.h"
/**
 * exit_status - handles the exit status for handle_exit
 * @status: exit status
 * Return: void
 */
static void exit_status(int status)
{
	exit(status);
}

/**
 * handle_exit - handles the built-in exit command
 * @status: exit status
 * Return: void
 */
void handle_exit(int status)
{
	exit_status(status);
	exit(status);
}
