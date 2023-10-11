#include "shell.h"

/**
 * _strcmp - Compares 2 strings using a loop.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Negative, positive, or zero value if s1 is
 * less than, greater than, or equal to s2.
 */

int _strcmp(char *s1, char *s2)
{
for (; *s1 != '\0' && *s1 == *s2; s1++, s2++)
{
	/*
	 * Continues the loop until the strings are different
	 * or until the end of the strings
	 */
}
return (*s1 - *s2);
}




/**
 * _strlen - Returns the length of a string.
 * @s: Pointer to a string.
 *
 * Return: Length of the string.
 */

int _strlen(char *s)
{
int length = 0;
int a;
for (a = 0; s[a] != '\0'; a++)

	length++;
return (length);
}




/**
 * _strchr - Finds the first occurrence of characters within strings
 * @s: String to be searched 
 * @c: Character to be found
 *
 * Return: Pointer to the first occurrence of c in
 * s, or 0 for unfound characters
 */

char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (s);
        s++;
    }

    if (c == '\0')
        return (s);
    return (0);
}
