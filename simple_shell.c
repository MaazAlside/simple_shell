#include "main.h"

/**
* execute - Execute a command.
* @command: The command to execute.
* @status: Pointer to the status variable to be updated.
*/
void execute(char **command, int *status)
{

	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(status);
	}
}


/**
* main - simple_shell.
* @ac: arguments count.
* @argv: arguments vector.
*
* Return: Nothing.
*/

int main(int ac, char **argv)
{
	int status, i;

	char **array, *token, *buffer;

	(void) ac;
	(void) argv;

	status = 0;
	i = 0;
	array = malloc(sizeof(char *) * 1024);
	while (1)
	{
		buffer = my_getline();
		if (buffer == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			return (status);
		}
		token = strtok(buffer, " \t\n");
		while (token)
		{
			array[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		array[i] = NULL;
		if (_strcmp(array[0], "exit") == 0)
		{
			free2d(array);
			exit(EXIT_SUCCESS);
		}
		execute(array, &status);
		i = 0;
		free(buffer);
		free(array);
	}
}
