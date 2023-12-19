#include "shell.h"

/**
 * main - function handles user input and interacts
 * with the command line environment and process commend.
 * @argc: integer.
 * @argv: pointer.
 * @envp: pointer.
 * Return: it returns 0.
*/

int main(int argc, char *argv[], char *envp[])
{
	char *buf = NULL;
	size_t len = BUFFER_LEN;
	ssize_t lines;
	int isinteractive, lasterror = 0, counter = 0;

	if (argc > 2)
		len = BUFFER_LEN;

	while (1)
	{
		counter++;
		buf = malloc(BUFFER_LEN);
		isinteractive = isatty(fileno(stdin));

		if (isinteractive)
			write(1, "$ ", 2);

		lines = getline(&buf, &len, stdin);

		if (lines == -1)
		{
			free(buf);
			exit(lasterror);
		}

		if (buf[lines - 1] == '\n')
			buf[lines - 1] = '\0';
		if (is_env(buf, envp))
		{
			free(buf);
			buf = NULL;
			continue;
		}
		lasterror = execute_command(buf, argv, envp, lasterror, counter);
		free(buf);
		buf = NULL;
	}
	return (0);
}

