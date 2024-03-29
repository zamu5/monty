#include "monty.h"
/**
 * compare - reads a line in the file and checks if its valid to run op_code
 *
 * @buff: buffer to save line per line in the file
 * @count: line number in the file that is being checked
 *
 * Return: 1 if is a valid line, 0 otherwise.
 */
int compare(char *buff, int count)
{
	char *data[18] = {"push", "pall", "pint", "pop", "swap", "add", "nop",
			 "sub", "div", "mul", "mod", "pchar", "pstr", "rotl",
			  "rotr", "stack", "queue", NULL};
	char *token;
	int i = 0, result;

	token = strtok(buff, " \n");
	while (token && data[i])
	{
		if (strcmp(token, data[i]) == 0)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " \n");
				if (!token)
				{
					fprintf(stderr, "L%i: usage: push integer\n", count);
					exit(EXIT_FAILURE);
				}
				result = _isdigit(token);
				if (result == 0)
				{
					fprintf(stderr, "L%i: usage: push integer\n", count);
					exit(EXIT_FAILURE);
				}
				return (1);
				result++;
			}
			return (1);
		}
		i++;
	}
	return (-1);

}
