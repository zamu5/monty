#include "monty.h"
/**
 * main - The Monty language
 * @ac: argument counter
 * @av: arguments vector
 * Return: 0 in fail
 */

int main(int ac, char *av[])
{
	char *buff = NULL;
	FILE *fo;
	ssize_t red;
	size_t len = 0;
	int count = 1;

	if (ac != 2)
	{
		fprintf(stderr, "%s", ERROR_USAGE);
		exit(EXIT_FAILURE);
	}
	fo = fopen(av[1], "r");
	if (fo == NULL)
	{
		fprintf(stderr, "%s%s\n", ERROR_ERROR, av[1]);
		exit(EXIT_FAILURE);
	}
	red = getline(&buff, &len, fo);
	while (red >= 0)
	{
		spaces(buff);
		if (buff[0] == '#')
			continue;
		else if (compare(buff, count) == -1)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", count, buff);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	fclose(fo);
	readline(av[1]);
	return (0);
}
