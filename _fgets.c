#include "shell.h"

/**
 * _fgets - Reads at most one less than size
 * characters from a file input stream
 *
 * @s: Buffer that stores the line read
 * @n: Maximum number of characters to read.
 * @stream: The input file to be read
 * Return: s on success, and NULL on error or when EOF
 * occurs while no characters have been read.
 */

char *_fgets(char *s, int n, FILE *stream)
{
int char_read; /* Counter for characters read */
char temp; /* Temporary storage buffer for characters */

if (s == NULL || n <= 0 || stream == NULL)
	return (NULL);

char_read = 0; /* Initialize counter to 0 */

while (char_read < n - 1)
{
	if (read(fileno(stream), &temp, 1) != 1)
	{
		if (char_read == 0) /* No characters read */
			return (NULL); /* EOF reached or error encountered */
	}
	s[char_read] = temp; /* Store the character read */
	char_read++;
	/* Once a new line is encountered, end the reading process */
	if (temp == '\n')
		break;
}
s[char_read] = '\0'; /* Include null-terminator */
return (s);
}
