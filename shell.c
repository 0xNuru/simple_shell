#include "shell.h"

/**
* main - simple shell program
*
* Description: an implementation of a simple shell CLI
* Return: 0 (success)
*/

int main(void)
{

	if (isatty(STDIN_FILENO))
		interactive_sh();
	else
		non_interactive_sh();

	return (0);
}





/**
 * free_args - Frees memory  for an array
 * @args: String array being freed
 *
 */

void free_args(char **args)
{
	int i;

	if (args != NULL && *args != NULL)
	{

		if (args)
		{
			for (i = 0; args[i] != NULL; i++)
			{
				free(args[i]);
			}
			free(args);
		}
	}
}
