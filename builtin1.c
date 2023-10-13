#include "shell.h"

/**
* __exit - a function that exits from process
* @input: input string
*
* Return: (1) if exit was entered
*/

int __exit(char *input)
{
	char *inputcpy, **args;
	long int status;
	int token_status;

	inputcpy = strdup(input);
	args = parse_input(inputcpy, &token_status);
	if (token_status == 1)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{	
		if (args[1] == NULL)
			exit(EXIT_SUCCESS);

		if (args[2] != NULL)
		{
			printf("Usage: exit status\n");
			return (0);
		}
		status = atoi(args[1]);
		exit(status);
	}
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
	char **env = environ;

	inputcpy = strdup(input);
	token1 = strtok(inputcpy, " ");
	token2 = strtok(NULL, " ");

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
