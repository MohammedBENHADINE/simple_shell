#include "simple_shell.h"
#include <stddef.h>

/**
* free_td - frees a two dimensional array.
* @grid: 2d array
*
*/
void free_td(char **grid)
{
	int i = 0, len = 0;

	while (grid[i++] != NULL)
		len++;

	for (i = 0; i < len; i++)
		free(grid[i]);

	free(grid);

	grid = NULL;
}
