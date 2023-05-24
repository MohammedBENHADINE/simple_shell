#include "simple_shell.h"

/**
 * str_dup - duplicates a string.
 * @s: string to duplicate.
 *
 * Return: returns a duplicate of input string.
*/
char *str_dup(const char *s)
{
	int len = str_len(s), i;
	char *dup = malloc(len + 1);

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = s[i];

	dup[len] = '\0';

	return (dup);
}
