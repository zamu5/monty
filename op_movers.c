void op_swap(stack_t **head, unsigned int line)
{
	int temp;

	if(*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%ui: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (**head).n;
	(**head).n = (*(**head).next).n;
	(*(**head).next).n = temp;
}
void op_rotl(stack_t **head, unsigned int line)
{
	int temp;

	temp = (**head).n;
	add_dnodeint_end(head, temp);
	op_pop(head, line);
}

void op_rotr(stack_t **head, unsigned int line)
{
	int i = 1;
	stack_t *copy;

	copy = *head;
	while((*copy).next != NULL)
	{
		copy = (*copy).next;
		i++;
	}
	number = (*copy).n;
	op_push(head, line);
	delete_dnodeint_at_index(head, i);
}
void op_nop(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
}
void op_pop(stack_t **head, unsigned int line)
{
	stack_t *copy;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%ui: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	copy = *head;
	if ((*copy).next == NULL)
		*head = NULL;
	else
	{
		*head = (*copy).next;
		(**head).prev = NULL;
	}
	free(copy);
	return;
}
