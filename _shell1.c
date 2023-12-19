#include "shell.h"

/**
 * _strcat - function that concatenates two strings
 * @sorc: refers to the source string
 * @des: refers to the destination string
 * Return: A pointer to the resulting string 'des'.
 */

char *_strcat(char *des, const char *sorc)
{
	int i = 0;
	int len = 0;

	while (des[i++])
		len++;
	for (i = 0; sorc[i]; i++)
		des[len++] = sorc[i];
	des[len] = '\0';
	return (des);
}

/**
 * _strcpy - it is a function that copies the string pointed to by 'des'
 * @des: pointer to destination string
 * @sorc: ponter to source string
 * Return: @original
 */

char *_strcpy(char *des, const char *sorc)
{
	char *original = des;

	while (*sorc != '\0')
	{
		*des = *sorc;
		sorc++;
		des++;
	}
	*des = '\0';
	return (original);
}

/**
 * to_str - A funcation switch integer number to string
 * @num: the integer number
 * @base: the base of the number
 * Return: pointer
 */

char *to_str(int num, int base)
{

	int i = 30;
	static char buf[40] = { 0 };

	for (; num  && i; --i, num /= base)

		buf[i] = "0123456789abcdef"[num  % base];

	return (&buf[i + 1]);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
