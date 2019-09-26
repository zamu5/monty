#include "monty.h"
/**
 * op_swap - swaps the top two elements of the stack
 *
 * @head: double pointer to the head
 * @line: line number in the file
 *
 * Return: nothing
 */
void op_swap(stack_t **head, unsigned int line)
{
	int temp;

	if (*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (**head).n;
	(**head).n = (*(**head).next).n;
	(*(**head).next).n = temp;
}
/**
 * op_rotl - rotates the stack to the top
 *
 * @head: double pointer to the head
 * @line: line number in the file
 *
 * Return: nothing
 */
void op_rotl(stack_t **head, unsigned int line)
{
	int temp;

	if (*head == NULL)
		return;
	temp = (**head).n;
	add_dnodeint_end(head, temp);
	op_pop(head, line);
}
/**
 * op_rotr - rotates the stack to the bottom.
 *
 * @head: double pointer to the head
 * @line: line number in the file
 *
 * Return: nothing
 */
void op_rotr(stack_t **head, unsigned int line)
{
	int i = 1;
	stack_t *copy;

	if (*head == NULL)
		return;
	copy = *head;
	while ((*copy).next != NULL)
	{
		copy = (*copy).next;
		i++;
	}
	number = (*copy).n;
	op_push(head, line);
	delete_dnodeint_at_index(head, i);
}
/**
 * op_nop - doesn’t do anything.
 *
 * @head: double pointer to the head
 * @line: line number in the file
 *
 * Return: nothing
 */
void op_nop(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
}
/**
 * op_pop - removes the top element of the stack.
 *
 * @head: double pointer to the head
 * @line: line number in the file
 *
 * Return: nothing
 */
void op_pop(stack_t **head, unsigned int line)
{
	stack_t *copy;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
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
}
