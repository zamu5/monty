#include "monty.h"
/**
 * print_dlistint - print a list
 * @h: head of the list
 * Return: the number of nodes
 */
size_t print_dlistint(const stack_t *h)
{
	int i = 0;

	if (h == NULL)
		return (0);
	while ((*h).prev != NULL)
		h = (*h).prev;
	while (h != NULL)
	{
		printf("%d\n", (*h).n);
		h = (*h).next;
		i++;
	}
	return (i);
}
/**
 * add_dnodeint_end - add a new node at the end
 * @head: head of the list
 * @n: value of the new node
 * Return: the addres of tthe new element
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *copy;

	copy = *head;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	(*new).n = n;
	(*new).next = NULL;
	if (copy == NULL)
		(*new).prev = copy, *head = new;
	else
	{
		while ((*copy).next != NULL)
			copy = (*copy).next;
		(*new).prev = copy;
		(*copy).next = new;
	}
	return (new);
}
/**
 * delete_dnodeint_at_index - delete a node in an specific index
 * @head: head of the list
 * @index: number of node to be deleted
 * Return: 1 with success
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp_del, *tmp_head;

	if (!head || !*head)
		return (-1);
	tmp_head = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(tmp_head);
		return (1);
	}
	for ( ; index > 1 && tmp_head && tmp_head->next; index--)
		tmp_head = tmp_head->next;
	if (!tmp_head->next)
		return (-1);
	tmp_del = tmp_head->next;
	tmp_head->next = tmp_del->next ? tmp_del->next : NULL;
	if (tmp_del->next)
		tmp_del->next->prev = tmp_head;
	free(tmp_del);
	return (1);
}
