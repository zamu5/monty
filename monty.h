#ifndef MONTY
#define MONTY

#define ERROR_USAGE "USAGE: monty file\n"
#define ERROR_ERROR "Error: Can't open file "

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int number;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;

	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void spaces(char *buffer);
int compare(char *buff, int count);
int _isdigit(char *s);
int readline(char *file);
void op_push(stack_t **head, unsigned int line);
void op_pall(stack_t **h, unsigned int line);
void (*get_func(char *, int))(stack_t **stack, unsigned int);
stack_t *add_dnodeint(stack_t **head, int n);
size_t print_dlistint(const stack_t *h);
void op_pint(stack_t **h, unsigned int line);
void op_pop(stack_t **head, unsigned int line);
void op_swap(stack_t **head, unsigned int line);
void op_add(stack_t **head, unsigned int line);
void op_nop(stack_t **head, unsigned int line);
void op_sub(stack_t **head, unsigned int line);
void op_div(stack_t **head, unsigned int line);
void op_mul(stack_t **head, unsigned int line);
void op_mod(stack_t **head, unsigned int line);
void op_pchar(stack_t **head, unsigned int line);
void op_pstr(stack_t **head, unsigned int line);
void op_rotl(stack_t **head, unsigned int line);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void op_rotr(stack_t **head, unsigned int line);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void freeStack_t(stack_t *head);

#endif
