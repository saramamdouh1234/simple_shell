#include "shell.h"

/**
 * print_not_found - A funcation to print a error
 * massage if ac commend not found.
 * @shell: pointer
 * @counter: integer to count.
 * @cmd: As a pointer
 * Return: no return
 */

void print_not_found(char *shell, int counter, char *cmd)
{
	write(2, shell, _strlen(shell));
	write(2, ": ", 2);
	write(2, to_str(counter, 10), _strlen(to_str(counter, 10)));
	write(2, ": ", 2);
	write(2, cmd, _strlen(cmd));
	write(2, ": ", 2);
	write(2, "not found\n", 10);
}

/**
 * duplicate_str - A funcation to duplicate a string
 * @src: pionter to the string
 * Return: pionter str
*/

char *duplicate_str(char *src)
{
	char *str;
	int i, n;

	i = 0;
	n = 0;

	while (src[n] != '\0')
		n++;
	str = (char *)calloc(n + 1, sizeof(char));
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

/**
 * _getpath - function to get environment variable's value.
 * @env: an array of environment variables.
 * Return: The full path if found and NULL otherwise.
 */

char *_getpath(char *env[])
{
	int i;
	char *thepath = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
		 && env[i][3] == 'H' && env[i][4] == '=')
		{
			thepath = env[i] + 5;
			break;
		}
	}
	return (thepath);
}

/**
* is_in_path - function checks if a given command is
* in the PATH environment varible
* @command: The command to search for.
* @env: An array of environment variables.
* Return: returns full command if found and null otherwise.
*/

char *is_in_path(char *command, char **env)
{
	char *path = _getpath(env);
	char *tok, *full_command, *pathclone;

	if (path == NULL)
		return (NULL);
	pathclone = duplicate_str(path);
	tok = strtok(pathclone, ":");

	while (tok)
	{
		full_command = malloc(BUFFER_LEN);
		_strcpy(full_command, tok);
		_strcat(full_command, "/");
		_strcat(full_command, command);

		if (access(full_command, X_OK) == 0)
		{
			free(pathclone);
			return (full_command);
		}
		free(full_command);
		tok = strtok(NULL, ":");
	}
	free(pathclone);
	return (NULL);
}

/**
 * is_adigit - check if num is positivr digit
 * @s: string to be checked
 * Return: 0 or 1
 */

int is_adigit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] > '9' || s[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

