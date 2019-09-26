#include "monty.h"
/**
 * main - The Monty language
 * @ac: argument counter
 * @av: arguments vector
 * Return: 0 in fail
 */

int main(int ac, char *av[])
{
	FILE *fo;

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
	fclose(fo);
	readline(av[1]);
	return (0);
}
