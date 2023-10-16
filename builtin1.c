#include "shell.h"

/**
* __exit - a function that exits from process
* @input: input string
*
* Return: (1) if exit was entered
*/

int __exit(char *input)
{
	char *inputcpy, **args, *error;
	long int status;
	int token_status;

	inputcpy = strdup(input);
	args = parse_input(inputcpy, &token_status);
	if (token_status == 1)
		return (0);

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] == NULL)
			exit(EXIT_SUCCESS);

		if (args[2] != NULL)
		{
			error = "usage: exit status\n";
			write(2, error, strlen(error));
			return (1);
		}
		status = atoi(args[1]);
		if (status == 0 && _strcmp(args[1], "0") != 0)
		{
			error = "invalid exit status\n";
			write(2, error, strlen(error));
			return (1);
		}
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
	token1 = _strtok(inputcpy, " ");
	token2 = _strtok(NULL, " ");

	if ((_strcmp(token1, "env") == 0) && (token2 == NULL))
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		return (0);
	}
	return (1);
}


/**
* _setenv - change or add an environment variable
* @name: name of the env var
* @value: value of the env var
* @overwrite: the ovewrite option
*
* Description: The setenv() function adds the variable name to the
* environment with the value value, if name does not already exist.
* If name does exist in the environment, then its value is changed to value
* if overwrite is nonzero;
* if overwrite is zero, then the value of name is  not
* changed  (and  setenv()  returns a success status).
* Return: 0 (success)
*/

int _setenv(const char *name, const char *value, int overwrite)
{
	char *env_name_value;
	int putenv_status;

	/* Error handling: name has to be in the correct format */
	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
		return (-1);

	/* if env var already exitst and overwrite is false */
	if (_getenv(name) != NULL && overwrite != 0)
		return (0);


	env_name_value = malloc(strlen(name) + strlen(value) + 2);
	if (env_name_value == NULL)
	{
		perror("malloc");
		return (-1);
	}

	/* write the name and value into env_name_value  */
	sprintf(env_name_value, "%s=%s", name, value);

	/* call putenv and save the return value in putenv_status  */
	putenv_status = _putenv(env_name_value);
	/* Error handling: */
	if (putenv_status != 0)
	{
		free(env_name_value);
		return  (-1);
	}

	return (0);
}


/**
* is_setenv - check if cmd is setenv and call setenv
* @input: the input string
*
* Return: 0 (success) otherwise -1.
*/

int is_setenv(char *input)
{
	char *inputcpy, **args, *error = "usage: setenv VARIABLE VALUE\n";
	int token_status;

	inputcpy = strdup(input);
	args = parse_input(inputcpy, &token_status);
	if (token_status == 1)
		return (0);
	if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
		{
			write(2, error, strlen(error));
			return (98);
		}

		if (_setenv(args[1], args[2], 1) == -1)
		{
			error = "setenv failed\n";
			write(2, error, strlen(error));
			return (98);
		}
		return (99);
	}
	if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] == NULL || args[3] != NULL)
		{
			error = "usage: unsetenv VARIABLE\n";
			write(2, error, strlen(error));
			return (98);
		}
		if (_unsetenv(args[1]) == -1)
		{
			error = "unsetenv failed\n";
			write(2, error, strlen(error));
			return (98);
		}
		return (99);
	}
	return (0);
}


/**
* _putenv - a function that replicates the putenv function
* @name_value: a string in the format NAME="VALUE" to be added to env
*
* Description: a function that prints the alphabet
* Return: 0 (success)
*/

int _putenv(char *name_value)
{
	int env_len = 0, i;
	char **new_environ;

	/* find length of environment array */
	while (environ[env_len])
		env_len++;

	/**
	 * allocate memory for new environ (+2 because of null pointer
	 * and new environ var
	 */
	new_environ = malloc((env_len + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		perror("malloc");
		return (-1);
	}

	/* copy old environ to new_environ */
	for (i = 0; i < env_len; i++)
		new_environ[i] = strdup(environ[i]);

	new_environ[env_len] = strdup(name_value);
	new_environ[env_len + 1] = NULL;

	environ = new_environ;

	return (0);
}
