#include "simple_shell.h"

/**
 * get_args - creates a string of arguments from
 * an array of arguments.
 * @str: array of strings.
 *
 * Return: a string of arguments.
*/
char *get_args(char **str)
{
	char *str_out = NULL;
	int i = 0;

	str_out = str_dup(str[i++]);

	while (str[i] != NULL)
	{
		str_out = str_concat(str_concat(str_out, " "), str[i]);
		i++;
	}

	return (str_out);
}
