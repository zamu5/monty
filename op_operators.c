#include "monty.h"
/**
 * op_add - adds the top two elements of the stack.
 *
 * @head: double pointer to the head
 * @line: line number in the file
 *
 * Return: nothing
 */
void op_add(stack_t **head, unsigned int line)
{
	if (*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*(**head).next).n = (*(**head).next).n + (**head).n;
	op_pop(head, line);
}
/**
 * op_sub - subtracts the top element of the stack from
 * the second top element of the stack.
 *
 * @head: double pointer to the head
 * @line: line number in the file
 *
 * Return: nothing
 */
void op_sub(stack_t **head, unsigned int line)
{
	if (*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*(**head).next).n = (*(**head).next).n - (**head).n;
	op_pop(head, line);
}
/**
 * op_div - divides the second top element of the stack
 * by the top element of the stack.
 *
 * @head: double pointer to the head
 * @line: line number in the file
 *
 * Return: nothing
 */
void op_div(stack_t **head, unsigned int line)
{
	if (*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((**head).n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*(**head).next).n = (*(**head).next).n / (**head).n;
	op_pop(head, line);
}
/**
 * op_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 *
 * @head: double pointer to the head
 * @line: line number in the file
 *
 * Return: nothing
 */
void op_mul(stack_t **head, unsigned int line)
{
	if (*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*(**head).next).n = (*(**head).next).n * (**head).n;
	op_pop(head, line);
}
/**
 * op_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @head: double pointer to the head
 * @line: line number in the file
 *
 * Return: nothing
 */
void op_mod(stack_t **head, unsigned int line)
{
	if (*head == NULL || (**head).next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((**head).n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*(**head).next).n = (*(**head).next).n % (**head).n;
	op_pop(head, line);
}
