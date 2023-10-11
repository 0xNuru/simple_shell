#include "shell.h"

/**
 * _realloc - Reallocates a memory block.
 * @ptr: Pointer to the old memory block.
 * @new_size: New size of the memory block.
 *
 * Return: Pointer to the new memory block, otherwise NULL on failure.
 */

void *_realloc(void *ptr, size_t new_size)
{
size_t prev_size; /* Stores the size of the previous memory */
size_t element_size;
size_t total_elements;
size_t i; 
void *new_ptr; /* pointer to the new memory block */
char *prev_content;/* pointer to the previous memory's content */
char *new_content; /* pointer to the new memory's content */

/* Checks if new_size is 0 and if so, free the old memory block */
if (new_size == 0) 
{
	free(ptr);
	return (NULL);
}

/* Checks if ptr is NULL and if so, simply allocate new memory */
if (ptr == NULL) 
	return (malloc(new_size));

/* Attempt to allocate memory for the new block */
new_ptr = malloc(new_size);

if (new_ptr) 
{
	/* Calculate the size of each element and the total number of elements */
	element_size = sizeof(((char *)ptr)[0]);
	total_elements = new_size / element_size;
	prev_size = total_elements * element_size;
    
	/* Use the smaller of the old and new sizes */
	if (new_size < prev_size) 
	{
		prev_size = new_size;
	}

	prev_content = (char *)ptr;
	new_content = (char *)new_ptr;
    
	/* Copy data from the old block to the new block */
	for (i = 0; i < prev_size; i++) 
	{
		new_content[i] = prev_content[i];
	}
	free(ptr); /* Free the old block */
	return (new_ptr);
}
else
{
	return (NULL); /* Failed allocation */
}
}
