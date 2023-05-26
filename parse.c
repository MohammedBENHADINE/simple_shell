#include "simple_shell.h"
#include <string.h>
#include <stdio.h>

/**
 * parse - extracts sub-strings from a string
 * seperated by specified delimiters.
 * @in_str: the string read from input.
 *
 * Return: an array of strings (tokens);
*/
char **parse(char *in_str)
{
	char *delimiters = " \0";
	char **token_arr = { NULL };
	int n = 0;

	if (in_str == NULL)
		return (NULL);

	n = _strlen(in_str);
	in_str[n - 1] = '\0';
	token_arr = tokenize(in_str, delimiters);

	return (token_arr);
}
