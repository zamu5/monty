int compare(char *buff, int count)
{
	char *data[8] = {"push", "pall", "pint", "pop", "swap", "add", "nop", NULL};
	char *token;
	int i = 0, result;

	token = strtok(buff, " /n");
	while(token && data[i])
	{
		if (strcmp(token, data[i]) == 0)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " /n");
				result = _isdigit(token);
				if (result == 0)
				{
					fprintf(stderr, "L%i: usage: push integer\n", count);
					exit(EXIT_FAILURE);
				}
				return(1);
				result++;
			}
			return(1);
		}
		i++;
	}
	return(-1);

}
