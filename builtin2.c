#include "shell.h"

/**
* is_builtin - a function to check if the command entered is a builtin
* @input: the line entered
*
* Return: 99 (a builtin was encounterd), otherwise 0
*/

int is_builtin(char *input)
{
	if (__exit(input) != 0)
		return (99);

	if (__env(input) == 0)
		return (99);

	if (is_setenv(input) != 0)
		return (99);

	return (0);
}
