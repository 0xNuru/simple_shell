#include "shell.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: String being converted.
 *
 * Return: The converted number i.e. result.
 */

int _atoi(char *s)
{
int i, sign, result;
long num;

i = 0;
sign = 1;
num = 0;
result = (int)(sign *num);

while (s[i])
{
	if (s[i] == '-')
		sign *= -1;
	else if (s[i] == '+')
		sign *= 1;

	if (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		if (num < INT_MIN || num > INT_MAX)
			return (0);
	}
	i++;
}
return (result);
}
