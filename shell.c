#include "shell.h"

/**
* main - simple shell program
* @argc: the number of arguments
* @argv: the arguments vector
*
* Description: an implementation of a simple shell CLI
* Return: 0 (success)
*/

int main(int argc, char *argv[])
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
		continue;

	if (is_builtin(input) == 99)
		continue;

	if (_f_ok(args[0], environ) != 0)
		continue;

	pid = fork();
	if (pid == 0)
	{
		_execvpe(args[0], args, environ);
		perror("execve");
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	free(args);
}
free(input);
return (0);
}
