#include "shell.h"

/**
* _atoi - Change string to an integer.
* @s: Pointer to a character string.
*
* Return: num in int.
*/

int _atoi(char *s)
{
	int si;
	unsigned int num;
	char *tem;

	tem = s;
	num = 0;
	si = 1;
	while (*tem != '\0' && (*tem < '0' || *tem > '9'))
	{
		if (*tem == '-')
			si *= -1;
		tem++;
	}
	if (*tem != '\0')
	{
		do {
			num = num * 10 + (*tem - '0');
			tem++;
		} while (*tem >= '0' && *tem <= '9');
	}
	return (num * si);
}
