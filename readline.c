#include "monty.h"
int readline(char *file)
{
	FILE *fo;
	char *buff = NULL, *token;
	ssize_t red;
	size_t len = 0;
	int count = 1;
	void (*test)(stack_t **stack, unsigned int line_number) = NULL;
	stack_t *list = NULL;

	fo = fopen(file, "r");
	while((red = getline(&buff, &len, fo)) >= 0)
	{
		spaces(buff);
		if (buff[0] == '#')
			continue;
		else
		{
			token = strtok(buff, " \n");
			if (strcmp(token, "push") == 0)
				number = atoi(strtok(NULL, " \n"));
			test = get_func(token, count);
			if (test == NULL)
				return(0);
			test(&list, count);
		}
		count++;

	}
	return(0);
}
