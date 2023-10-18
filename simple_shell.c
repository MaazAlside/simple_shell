#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - ex: fork+wait+execve
 *
 * Return: Always 0.
 */

int main(void)
{
    pid_t pid;
    int status, i, n_char;
    size_t buffer_size;
    char **array = NULL;
    char *token;
    char *buffer = NULL;

    i = 0;
    buffer_size = 0;

    array = malloc(sizeof(char *) * 1024);
    while (1)
    {
        write(1, "#cisfun$ ", 9);
        n_char = getline(&buffer, &buffer_size, stdin);
	if ( n_char == EOF)
	{
		perror("getline error");
	}
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
