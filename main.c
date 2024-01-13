#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack_t *stack = NULL; /* Initialize the stack */

	char *buffer = NULL;
	size_t size = 0;
	ssize_t read_line;
	unsigned int line_number = 0;

	const instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap}, //adding 
		{NULL, NULL} /* Null terminator to mark the end of the array */
	};
	while ((read_line = getline(&buffer, &size, file)) != -1)
	{
		line_number++;

		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';

		char *opcode = strtok(buffer, " ");
		if (opcode != NULL)
		{
			const instruction_t *instruction = get_instruction(opcode, instructions);
			if (instruction)
			{
				instruction->f(&stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				free(buffer);
				fclose(file);
				free_stack(stack); /* Free the stack before exiting */
				exit(EXIT_FAILURE);
			}
		}
		free(buffer);
		buffer = NULL;
		size = 0;
	}
	fclose(file);
	free(buffer);
	free_stack(stack); /* Free the stack before exiting */
	return (0); // Add parentheses around the return value
}
