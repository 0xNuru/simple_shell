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

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(1, "($) ", strlen("($) "));
			input = read_input(&eof_status);
			if (eof_status == 1)
				break;
			args = parse_input(input, &token_status);

			if (token_status == 1 || is_builtin(input) == 99 || _f_ok(args[0]) != 0)
				continue;

			pid = fork();
			if (pid == 0)
			{
				_execvpe(args[0], args, environ);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
				waitpid(pid, &status, 0);
		}
	}
	else
	{
		input = read_input(&eof_status);
		if (eof_status != 1)
		{
			args = parse_input(input, &token_status);
			if (token_status == 0 && is_builtin(input) != 99 && _f_ok(args[0]) == 0)
			{
				pid = fork();
				if (pid == 0)
				{
					_execvpe(args[0], args, environ);
					perror("execve");
					exit(EXIT_FAILURE);
				}
				else
					waitpid(pid, &status, 0);
			}

		}
	}
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
