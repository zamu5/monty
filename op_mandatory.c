#include "monty.h"
/**
 * op_push - add a new node at the begining of a list
 * @head: head of the list
 * @n: value of the new node
 * Return: the adrres of the new node
 */
void op_push(stack_t **head, unsigned int line)
{
	stack_t *new = malloc(sizeof(stack_t));

	(void)line;
	if (new == NULL)
		return;
	(*new).n = number;
	(*new).prev = NULL;
	(*new).next = *head;
	if (*head != NULL)
		(**head).prev = new;
	*head = new;
}
/**
 * op_pall - print a list
 * @h: head of the list
 * @line: line of opcode
 * Return: nothing
 */
void op_pall(stack_t **h, unsigned int line)
{
	(void)line;
	print_dlistint(*h);
}
/**
 * print_dlistint - print a list
 * @h: head of the list
 * Return: the number of nodes
 */
void op_pint(stack_t **h, unsigned int line)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%ui: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	while ((**h).prev != NULL)
		*h = (**h).prev;
	if (*h != NULL)
	{
		printf("%d\n", (**h).n);
      	}
}
void op_pchar(stack_t **head, unsigned int line)
{
	if(*head == NULL)
	{
		fprintf(stderr, "L%ui: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if((**head).n >= 0 && (**head).n < 256)
		putchar((**head).n), putchar('\n');
	else
	{
		fprintf(stderr, "L%ui: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
}
void op_pstr(stack_t **head, unsigned int line)
{
	(void)line;
	if(*head == NULL)
	{
		putchar('\n');
		return;
	}
	while(*head)
	{
		if((**head).n <= 0 || (**head).n > 255)
			break;
		putchar((**head).n);
		*head = (**head).next;
	}
	putchar('\n');
}
