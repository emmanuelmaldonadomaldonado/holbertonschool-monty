#include "monty.h"
#include "instructions.h"
/**
 * main - Entry point for Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments passed to the program
 *
 * Return: Always 0 on success
 */
int main(int argc, char *argv[])
{
	instruction_t *my_instructions = get_instructions();
	FILE *file = fopen(argv[1], "r");
	char *line = NULL;
	char *opcode = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	int i;

	if (argc != 2) 
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	my_file(file, argv);
	while ((getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode == NULL || *opcode == '#')
			continue;
		for (i = 0; my_instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, my_instructions[i].opcode) == 0)
			{
				my_instructions[i].f(&stack, line_number);
				break;
			}
		}
		if (my_instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			cleanup_resources(file, line, &stack);
			exit(EXIT_FAILURE);
		}
	}
	cleanup_resources(file, line, &stack);
	return (0);
}
