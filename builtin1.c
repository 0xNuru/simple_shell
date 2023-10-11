#include "shell.h"

/**
* __exit - a function that exits from process
* @input: input string
*
* Return: (1) if exit was entered
*/

int __exit(char *input)
{
	char *token1, *token2, *inputcpy;

	inputcpy = strdup(input);
	token1 = _strtok(inputcpy, " ");
	token2 = _strtok(NULL, " ");

	if ((strcmp(token1, "exit") == 0) && (token2 == NULL))
		return (1);
	
	return (0);
}


/**
* __env - a function that prints
* @input: input string
*
* Return: 0 (success)
*/
int __env(char *input)
{
	char *token1, *token2, *inputcpy;
	extern char **environ;
	char **env = environ;
	
	inputcpy = strdup(input);
	token1 = _strtok(inputcpy, " ");
	token2 = _strtok(NULL, " ");

	if ((strcmp(token1, "env") == 0) && (token2 == NULL))
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	return (0);
}
