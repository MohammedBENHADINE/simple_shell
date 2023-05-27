#include "simple_shell.h"

/**
 * count_tokens - counts the number of substrings that are
 * seperated by a charset of delimiters.
 * @str: string to evaluate.
 * @dlm: string of delimiters
 *
 * Return: number of tokens.
*/
int count_tokens(const char *str, const char *dlm)
{
	int i = 0, count = 0;
	short istoken = _strchr(dlm, str[i]) == NULL ? 0 : 1;

	while (str[i] != '\0')
	{
		if (_strchr(dlm, str[i]) == NULL)
		{
			if (istoken == 0)
				count++;
			istoken = 1;
		}
		else
		{
			istoken = 0;
		}
		i++;
	}

	return (count);
}
