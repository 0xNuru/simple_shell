#include "shell.h"

/**
* main - simple shell program
*
* Description: an implementation of a simple shell CLI
* Return: 0 (success)
*/

int main(void)
{
char *input, **args;
pid_t pid;
int status, token_status, eof_status = 0;

while (1)
{
	printf("($) ");
	input = read_input(&eof_status);
	if (eof_status == 1)
		break;
	args = parse_input(input, &token_status);
	if (token_status == 1)
	{
		free(input);
		continue;
	}
	if (is_builtin(input) == 99)
	{
		free(input);
		continue;
	}
	if (_f_ok(args[0]) != 0)
	{
		free(input);
		continue;
	}
	pid = fork();
	if (pid == 0)
	{
		_execvpe(args[0], args, environ);
		perror("execve");
		free(input);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	free(input);
}
/*free(input);*/
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

	if (args)
	{
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}
}
