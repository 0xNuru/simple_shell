#include "shell.h"

int main(int argc, char *argv[])
{
size_t bytes_read, input_len;
char *input;
pid_t pid;
extern char **environ;
int status;
char **args;
char *token;
int t_count;

while(1)
{
	t_count = 0;
	token = NULL;
	input_len = 0;
	printf("($) ");
	bytes_read = getline(&input, &input_len, stdin);
	if (bytes_read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			break;
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

	if ((__exit(input)) == 1)
		break;
	
	__env(input);
	
	token = _strtok(input, " ");
	
	if (token == NULL)
		continue;
	
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
			args = realloc(args, sizeof(char *) * t_count * 2);
			if (args == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
	
	}
	args[t_count] = NULL;
	
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
		/*if (WIFEXITED(status))
			printf("Success exit status: %d", WEXITSTATUS(status));
		else
			printf("exited abnormally");*/
	}
	free(args);
}
free(input);
return(0);
}
