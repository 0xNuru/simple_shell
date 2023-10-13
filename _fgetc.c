#include "shell.h"

/**
 * _fgetc - Reads the next character from a file stream
 * @stream: A pointer to the file stream to be read
 *
 * Return: The character read as an integer
 * otherwise EOF on error or when EOF is reached
 */

int _fgetc(FILE *stream)
{
char c; /* Character read from file stream */
ssize_t bytes_read; /* Stores the number of bytes read */

if (stream == NULL) /* Check if stream in empty */
	return (EOF);

bytes_read = read(fileno(stream), &c, 1);

/* Check if EOF has been reached or an error occured */
if (bytes_read == 1)
	return ((int)c);
else
	return (EOF);
}
