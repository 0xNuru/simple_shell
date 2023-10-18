#include "shell.h"

/**
* main - entry point
* @n: number..
*
* Description: a function that prints the alphabet
* Return: 0 (success)
*/

void free_argv(char **args)
{
	int i;

	if (args != NULL)
	{
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);

		free(args);
	}
}
