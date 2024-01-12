#include "monty.h"

/**
 * get_instruction - Searches for the opcode in the instructions array.
 * @opcode: The opcode to search for.
 * @instructions: The array of supported instructions.
 *
 * Return: A pointer to the corresponding instruction, or NULL if not found.
 */
const instruction_t *get_instruction(char *opcode, const instruction_t *instructions)
{
	while (instructions->opcode)
	{
		if (strcmp(opcode, instructions->opcode) == 0)
			return instructions;

		instructions++;
	}

	return NULL;
}

