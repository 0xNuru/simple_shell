char *token = NULL;
int t_count = 0

//tokenze input an pass the first token to "token" e.g ls
token = strtok(input, " ");


if (token == null)
	continue;

//dynamically assigned array that holds args
char **args = malloc(sizeof(char *) * 64);
if (args == NULL)
	perror("malloc");
	exit(FAILURE);

//pass in the command into args as args[0]
args[t_count] = token;

// input = cd home
// token = strtok(input, " ") -> token = "cd"


