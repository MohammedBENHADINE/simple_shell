#include "simple_shell.h"

/**
 * str_chr -  finds the first occurrence of a specific character
 * in a given string.
 * @str: string from which to search.
 * @c: character to search
 *
 * Return: the matching character.
*/
int str_chr(const char *str, const char c)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}

	return (0);
}
