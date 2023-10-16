#include "shell.h"

/**
 * _getline - Read an entire line from the file input stream
 * @lineptr: Pointer to the buffer that stores the line being read
 * @alloc_size: Pointer to the allocated buffer size.
 * @input: File input stream
 *
 * Return: The number of characters read, including the 
 * delimiter character, but excluding ('\0'), otherwise -1 on failure.
 */

ssize_t _getline(char **lineptr, size_t *alloc_size, FILE *input) 
{
char delim; /* Delimiter */
size_t tracker; /* Tracks current position within the buffer where characters are being stored. */
int bytes_read; /* Stores the result of the number of bytes read or EOF */
char *new_buffer; /* Pointer storing the address of new memory allocated */

delim = '\n';
tracker = 0; 

/* Check for invalid input arguments */
if (lineptr == NULL || alloc_size == NULL || input == NULL)
    return (-1);
/* Allocate memory for line buffer if it's not allocated or too small */
if (*lineptr == NULL || *alloc_size == 0) 
{
    *alloc_size = BUFFSIZE; /* Set initial buffer size to BUFFSIZE */
    if ((*lineptr = (char *)malloc(*alloc_size)) == NULL) 
        return (-1); /* Failed allocation */
}
while (1) 
{
bytes_read = fgetc(input);

    if (bytes_read == EOF) 
    {
        if (tracker == 0)
        {
            free(*lineptr); /* Free memory */
            return (-1); /* No characters read (EOF) */
        }
        else 
        {
            (*lineptr)[tracker] = '\0';
            return (tracker); /* Line read successfully, excluding null terminator */
        }
    }
    if (tracker + 1 >= *alloc_size) 
    {
	/* Double buffer size and check for reallocation failure */
	new_buffer = (char *)_realloc(*lineptr, *alloc_size *= 2);
	if (new_buffer == NULL)
        {
            free(*lineptr); /* Free memory */
            return (-1); /* Failed memory reallocation */
        }
    }
    
    /*  Store the character read in the buffer and increment the tracker */
    (*lineptr)[tracker++] = (char)bytes_read;

    /* Check for consecutive black new lines */
    if (tracker > 1 && (*lineptr)[tracker - 1] == '\n' && (*lineptr)[tracker - 2] == '\n')
	return (0);

    if (bytes_read == delim) 
    {
        (*lineptr)[tracker] = '\0'; /* Exclude the newline character */
        return (tracker); /* Line read successfully, excluding null terminator */
    }
}
}
