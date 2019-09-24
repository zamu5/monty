#include "monty.h"
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
	if ((fo = fopen(av[1], "r")) == NULL)
	{
		fprintf(stderr, "%s%s\n", ERROR_ERROR, av[1]);
		exit (EXIT_FAILURE);
	}
	while((red = getline(&buff, &len, fo)) >= 0)
	{
		spaces(buff);
		if (compare(buff, count) == -1)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", count, buff);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	return (0);
}
