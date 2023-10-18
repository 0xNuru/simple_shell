#include "shell.h"

/**
* parse_input - a function that parses the input string to cmd and args
* @input: the input string
* @token_status: a pointer used to signify if token is null from beginning
*
* Return: the array containing the command and args
*/

char **parse_input(char *input, int *token_status)
{
	char *token = NULL, **args, *inputcpy;
	int t_count = 0;

	*token_status = 0;
	inputcpy = strdup(input);
	token = strtok(inputcpy, TOKEN_DELIM);
	if (token == NULL)
	{
		*token_status = 1;
	}
	args = malloc(sizeof(char *) * 64);
	if (args == NULL)
	{
		free(inputcpy);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	args[t_count++] = token;

	while ((token = strtok(NULL, TOKEN_DELIM)))
	{
		args[t_count++] = token;
		if (t_count >= 64)
		{
			args = _realloc(args, sizeof(char *) * t_count * 2);
			if (args == NULL)
			{
				free(inputcpy);
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
	}
	free(inputcpy);
	args[t_count] = NULL;
	return (args);
}
