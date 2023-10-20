#include "main.h"

/**
* main - simple_shell.
* @ac: arguments count.
* @argv: arguments vector.
*
* Return: Nothing.
*/

int main(int ac, char **argv)
{
	int status = 0;

	char **cmd = NULL, *line = NULL;

	(void) ac;

	while (1)
	{
		line = my_getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			return (status);
		}
		cmd = my_strtok(line);
		if (!cmd)
			continue;
		if (_strcmp(cmd[0], "exit") == 0)
		{
			if (cmd[1] != NULL)
			{
				status = _atoi(cmd[1]);
				if (status == -1)
				{
					exit(2);
				}
			}
			free2d(cmd);
			return (status);
		}
		status = my_exec(cmd, argv);
	}
}
