void op_add(stack_t **head, unsigned int line)
{
	if(*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%ui: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*(**head).next).n = (*(**head).next).n + (**head).n;
	op_pop(head, line);
}
void op_sub(stack_t **head, unsigned int line)
{
	if(*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%ui: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*(**head).next).n = (*(**head).next).n - (**head).n;
	op_pop(head, line);
}
void op_div(stack_t **head, unsigned int line)
{
	if(*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%ui: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if((**head).n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*(**head).next).n = (*(**head).next).n / (**head).n;
	op_pop(head, line);
}
void op_mul(stack_t **head, unsigned int line)
{
	if(*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%ui: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*(**head).next).n = (*(**head).next).n * (**head).n;
	op_pop(head, line);
}
void op_mod(stack_t **head, unsigned int line)
{
	if(*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%ui: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if((**head).n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*(**head).next).n = (*(**head).next).n % (**head).n;
	op_pop(head, line);
}
