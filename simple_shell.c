#include "main.h"

/**
 * main - simple_shell.
 *
 * Return: Nothing.
 */

int main(void)
{
	pid_t pid;
	int status, i;
	char **array = NULL;
	char *token;
	char *buffer;

	i = 0;
	array = malloc(sizeof(char *) * 1024);
	while (1)
	{
		buffer = my_getline();
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
			if (execve(array[0], array, NULL) == -1)
			{
				perror("execve error");
			}
		}
		else
		{
			wait(&status);
		}
		i = 0;
		free(array);
	}
}
