#include "simple_shell.h"
#include <stddef.h>

/**
* str_len - returns the length of a string.
* @s: a string argument.
*
* Return: length of string argument.
*/
int str_len(const char *s)
{
	int length = 0;

	if (s != NULL)
	{
		while (*s++)
			length++;
	}

	return (length);
}
