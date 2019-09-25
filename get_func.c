#include "monty.h"
void (*get_func(char *token, int line))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode[] = {
		{"push", op_push},
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
		if(strcmp(opcode[i].opcode, token) == 0)
		{
			return (opcode[i].f);
		}
		i++;
	}
	return (NULL);
}
