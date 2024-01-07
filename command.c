#include "monty.h"

/**
 * command - Function that finds and
 * executes the corresponding function.
 *
 * @opcode: Function commands
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the monty file.
 * @opcodes: Struct of instruction_t.
 */

void command(char *opcode, stack_t **stack,
			 unsigned int line_number, instruction_t opcodes[])
{
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
		i++;
	}

	if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
		return;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	cleanup(NULL, NULL, *stack);
	exit(EXIT_FAILURE);
}
