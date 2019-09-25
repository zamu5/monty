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
		if(s[0] == 45)
			i++;
		if (s[i] < 47 || s[i] > 58)
			return (0);
		i++;
	}
	return (1);
}
/**
 * freeStack_t - free a list
 * @head: head of the list
 * Return: nothing
 */
void freeStack_t(stack_t *head)
{
	stack_t *copy;

	while (head)
	{
		copy = head;
		head = (*head).next;
		free(copy);
	}
}
