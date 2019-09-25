#include "monty.h"
/**
 * spaces - remove the spaces at the begining of the buffer
 * @buffer: buffer
 * Return: the same buffer without spaces
 */
void spaces(char *buffer)
{
	int i = 0, j = 0;

	if (buffer[i] == 32 || buffer[i] == 9)
	{
		while (buffer[i] == 32 || buffer[i] == 9)
		{
			i++;
		}
		while (buffer[i] != '\0')
		{
			buffer[j] = buffer[i];
			i++;
			j++;
		}
		while (buffer[j] != '\0')
		{
			buffer[j] = '\0';
		}
	}
}
