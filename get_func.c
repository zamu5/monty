#include "monty.h"
/**
 * get_func - receives an op_code and checks if is a know op_code
 *
 * @token: string to check if is a op_code
 * @line_number: line number in the file where the string is present
 *
 * Return: nothing
 */
void (*get_func(char *token, int line))(stack_t **stack,
					unsigned int line_number)
{
	instruction_t opcode[] = {
		{"push", op_push},
		{"push1", op_push1},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{NULL, NULL}
	};


	int i = 0;

	(void)line;
	while (opcode[i].opcode != NULL)
	{
		if (strcmp(opcode[i].opcode, token) == 0)
		{
			return (opcode[i].f);
		}
		i++;
	}
	return (NULL);
}
