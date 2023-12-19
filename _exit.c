#include "shell.h"

/**
* is_exit - check exit.
* @t: Pointer to a character string.
* @exitcode: input2
* @lasterror: input2
* @freeme1: input2
* @s: input2
* @c: input2
* Return: void.
*/
int is_exit(char *t, char *exitcode, int lasterror,
char *freeme1, char *s, int c)
{
	int len = 0;

	while (t[len] != '\0')
		len++;
	if (len == 4)
	{
		if (t[0] == 'e' && t[1] == 'x' && t[2] == 'i'	&& t[3] == 't')
		{
			if (exitcode == NULL)
			{
				free(t);
				free(freeme1);
				if (lasterror != 0)
					exit(2);
				else
					exit(0);
			}
			else
			{
				if (is_adigit(exitcode))
				{
					len = _atoi(exitcode);
					free(t);
					free(freeme1);
					exit(len);
				}
				else
				{
					print_illigal(s, exitcode, c);
					return (1);
				}
			}
		}
	}
	return (0);
}
/**
* print_illigal - prints error.
* @s: Pointer to a character string.
* @exitcode: input2
* @c: input3
* Return: void.
*/
void print_illigal(char *s, char *exitcode, int c)
{
	write(2, s, _strlen(s));
	write(2, ": ", 2);
	write(2, to_str(c, 10), _strlen(to_str(c, 10)));
	write(2, ": ", 2);
	write(2, "exit", 4);
	write(2, ": ", 2);
	write(2, "Illegal number: ", 16);
	write(2, exitcode, _strlen(exitcode) + 1);
	write(2, "\n", 2);
}
