#include "simple_shell.h"
#include <stddef.h>

/**
* *str_concat - concatenates two strings.
* @s1: first contents.
* @s2: second contents.
*
* Return: pointer to a newly allocated space in memory.
*/
char *str_concat(const char *s1, const char *s2)
{
	int size1 = str_len(s1);
	int size2 = str_len(s2);
	char *new_str = malloc(sizeof(char) * (size1 + size2 + 1));

	if (new_str == NULL)
	{
		return (NULL);
	}
	else
	{
		int i, j;

		for (i = 0; i < size1; i++)
			new_str[i] = s1[i];

		for (j = i; j < (size1 + size2); j++)
			new_str[j] = s2[j - i];
	}

	return (new_str);
}
