#include "main.h"

/**
 * main - simple_shell.
 *
 * Return: Nothing.
 */

int main(int ac, char **argv)
{
	pid_t pid;
	int status, i;
	char **array;
	char *token;
	char *buffer;
	(void) ac;
	(void) argv;

	status = 0;
	i = 0;
	array = malloc(sizeof(char *) * 1024);
	while (1)
	{
		buffer = my_getline();
		if (buffer == NULL)
			return (status);
		token = strtok(buffer, " \t\n");
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		array[i] = NULL;
		pid = fork();
		if (pid == 0)
		{
			if (execve(array[0], array, environ) == -1)
			{
				perror("execve error");
			}
		}
		else
		{
			wait(&status);
		}
		i = 0;
		free(buffer);
		free(array);
	}
}
