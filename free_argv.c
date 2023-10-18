#include "shell.h"

/**
* free_argv - Frees a double pointer array
*
* @args: The double pointer array to free.
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
