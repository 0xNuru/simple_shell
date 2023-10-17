#include "shell.h"

/**
* read_input - a function that reads the user input
* @eof_status: the address of a var that holds the status of eof
*
* Return: (input) -> a string containing the input
*/

char *read_input(int *eof_status)
{
	char *input;
	size_t bytes_read, input_len;

	input = NULL;
	input_len = 0;
	*eof_status = 0;
	bytes_read = getline(&input, &input_len, stdin);

	if (bytes_read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			*eof_status = 1;
		}
		else
		{
			perror("getline");
			free(input);
			exit(EXIT_FAILURE);
		}
	}

	if (input[bytes_read - 1] == '\n')
		input[bytes_read - 1] = '\0';

	return (input);
}
