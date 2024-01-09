#include "monty.h"

/*structure*/
instruction_t operation[] = {
	{"push", push_stack},
	{"pall", pall_stack},
	{"pint", pint_stack},
	{"pop", pop_stack},
	{"swap", _swap},
	{"nop", _nop},
	{"add", _add},
	{NULL, NULL}
};

/**
 * get_op_code - contain the function that will perform the operation
 * @token: operation code
 * @line_number: line readed
 * @head: stack structure
 * Return: void
 */
void get_op_code(char *token, unsigned int line_number, stack_t **head)
{
	int i;
	/* Tokenization process */
	char *op_code = strtok(token, " \n");

	if (op_code == NULL || op_code[0] == '#')
		return;

	/* get correct operation */
	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(op_code, operation[i].opcode) == 0)
		{
			operation[i].f(head, line_number);
			break;
		}
	}
	/*chek if instruction is not known */
	if (operation[i].opcode == NULL)
		invalidInstruction_error(op_code, line_number);
}
