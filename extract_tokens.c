#include "simple_shell.h"
#include <stdio.h>

/**
 * extract_tokens - extracts tokens from a string and stores
 * them inside an array.
 * @str: string from which to extract tokens.
 * @dlm: delimiter charset.
 *
 * Return: array of tokens
*/
char **extract_tokens(const char *str, const char *dlm)
{
	char **token_arr;
	int i = 0, j = 0;

	if (str == NULL || dlm == NULL)
		return (NULL);
	token_arr = malloc(sizeof(char *) * (count_tokens(str, dlm) + 1));
	if (token_arr == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		if (str_chr(dlm, str[i]) == 0)
		{
			int p = i, q = i, r = 0, token_size = 0;

			while (str[p] != '\0' && str_chr(dlm, str[p]) == 0)
				p++;
			token_size = p - i;
			if (token_size > 0)
			{
				token_arr[j] = malloc(token_size + 1);
				if (token_arr[j] == NULL)
				{
					free_td(token_arr);
					return (NULL);
				}
				while (r < token_size)
					token_arr[j][r++] = str[q++];
				token_arr[j][r] = '\0';
				j++;
			}
			i = p;
		}
		else
		{
			i++;
		}
	}
	token_arr[j] = NULL;
	return (token_arr);
}
