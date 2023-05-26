#include "simple_shell.h"

/**
 * _strchr -  finds the first occurrence of a specific character
 * in a given string.
 * @str: string from which to search.
 * @c: character to search
 *
 * Return: the matching character.
*/
char *_strchr(const char *str, const char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}

	return (NULL);
}

/**
 * _strspn - counts consecutive number of characters
 * that can be found in a given charset from the start of a string.
 * @s: string from which to count.
 * @charset: characters to use for counting.
 *
 * Return: number of consecutive characters that were found in charset.
*/
int _strspn(const char *s, const char *charset)
{
	int len = 0;

	while (*s != '\0')
	{
		if (_strchr(charset, *s) != NULL)
		{
			len++;
			s++;
		}
		else
		{
			break;
		}
	}

	return (len);
}
