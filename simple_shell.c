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

	for (;;)
	{
		line = my_getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			return (status);
		}
		cmd = my_strtok(line);
		if (cmd == NULL)
			continue;
		status = my_exec(cmd, argv);
	}
}
