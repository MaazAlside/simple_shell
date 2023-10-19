#include "main.h"

/**
 * free2d - frees 2d array
 * @array : input array to be freed.
 *
 * Return: nothing
 */

void free2d(char **array)
{
	int i;

	if (array == NULL)
		return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
	array = NULL;
}
