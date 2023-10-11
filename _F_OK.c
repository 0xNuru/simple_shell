#include "main.h"

/**
* _f_ok - a function that checks if a file exitst
* @cmd: command to be checked
* @environ: environment in which path exists
*
* Return: 0 (file exitst) otherwise, -1
*/


int _f_ok(char *cmd, char **environ)
{
	size_t token_len, e_len, cmd_len;
	char *path, *token, *executable;

	if (access(cmd, F_OK) == 0)
		return (0);

	path = strdup(getenv("PATH"));
	if (path == NULL)
	{
		perror("getenv");
		return (1);
	}
	cmd_len = strlen(cmd);
	token = _strtok(path, ":");

	while (token != NULL)
	{
		token_len = strlen(token);
		e_len = (token_len + cmd_len + 2) * sizeof(char);
		executable = malloc((e_len) * sizeof(char));
		if (executable == NULL)
		{
			perror("malloc");
			return (1);
		}

		snprintf(executable, e_len, "%s/%s", token, cmd);

		if (access(executable, F_OK) == 0)
		{
			free(executable);
			return (0);
		}
		free(executable);
		token = _strtok(NULL, ":");

	}
	perror("access");
	return (1);
}