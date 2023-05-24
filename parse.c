#include "simple_shell.h"
#include <string.h>
#include <stdio.h>

/**
 * parse - extracts sub-strings from a string
 * seperated by specified delimiters.
 * @in: the string read from input.
 *
 * Return: an array of strings (tokens);
*/
char **parse(char *in)
{
	char *delimiters = " \"";
	char **token_arr = { NULL };
	int n = str_len(in);

	if (in[n - 1] == '\n')
		in[n - 1] = '\0';

	token_arr = extract_tokens(in, delimiters);

	return (token_arr);
}
