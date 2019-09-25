#include "monty.h"
/**
 * _isdigit - check if a character is a digit in a string
 *
 * @s: string to check
 *
 * Return: 0 if not digit, 1 if all the string has digits
 */
int _isdigit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < 47 || s[i] > 58)
			return (0);
		i++;
	}
	return (1);
}