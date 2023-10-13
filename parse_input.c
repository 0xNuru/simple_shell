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
	char *token;
	char **args;
	int t_count;
	char *inputcpy;

	t_count = 0;
	token = NULL;
	*token_status = 0;
	inputcpy = strdup(input);

	token = _strtok(inputcpy, " ");
	if (token == NULL)
		*token_status = 1;

	args = malloc(sizeof(char *) * 64);
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	args[t_count++] = token;

	while ((token = _strtok(NULL, " ")))
	{
		args[t_count++] = token;

		if (t_count >= 64)
		{
			args = _realloc(args, sizeof(char *) * t_count * 2);
			if (args == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
	}
	 args[t_count] = NULL;

	return (args);

}
