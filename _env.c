#include "shell.h"

/**
 * is_env - function checks if the command is env
 * @cmd: command
 * @envp: envp
 * Return: 1 if matches and 0 if not
 */

int is_env(char *cmd, char **envp)
{
	int len = 0;
	char **myenv;

	while (cmd[len] != '\0')
		len++;
	if (len != 3)
	return (0);
	else
	{
		if (cmd[0] == 'e' && cmd[1] == 'n' && cmd[2] == 'v')
		{
			for (myenv = envp; *myenv != NULL; myenv++)
			{
				len = 0;
				while ((*myenv)[len] != '\0')
					len++;
				write(1, *myenv, len);
				write(1, "\n", 1);
			}
			return (1);
		}
	}
	return (0);
}
