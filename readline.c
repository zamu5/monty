#include "monty.h"
/**
 * readline - read each line and execute the opcode
 * @file: file with the opcodes
 * Return: 0 in fail
 */
int readline(char *file)
{
	FILE *fo;
	char *buff = NULL, *token, *buff1 = NULL;
	ssize_t red;
	size_t len = 0;
	int count = 1, flag = 0;
	void (*test)(stack_t **stack, unsigned int line_number) = NULL;
	stack_t *list = NULL;

	fo = fopen(file, "r");
	while ((red = getline(&buff, &len, fo)) >= 0)
	{
		buff1 = malloc((strlen(buff) + 1) * sizeof(char));
		spaces(buff), strcpy(buff1, buff);
		if (buff[0] == '#' || buff[0] == '\n')
			;
		else if (compare(buff, count) == -1)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", count, buff);
			free(buff1), fclose(fo), free(buff), freeStack_t(list);
			exit(EXIT_FAILURE); }
		else
		{
			token = strtok(buff1, " \n");
			flag = mode(token, flag);
			if (strcmp(token, "push") == 0)
				number = atoi(strtok(NULL, " \n"));
			if (flag && strcmp(token, "push") == 0)
				strcat(token, "1");
			test = get_func(token, count);
			if (test == NULL)
				;
			else
				test(&list, count); }
		count++, free(buff1);
	}
	fclose(fo), free(buff), freeStack_t(list);
	return (0);
}
/**
 * mode - switch the operation mode
 * @token: mode
 * @flag: mode
 * Return: nothing
 */
int mode(char *token, int flag)
{
	if (strcmp(token, "queue") == 0)
		flag = 1;
	if (strcmp(token, "stack") == 0)
		flag = 0;
	return (flag);
}
