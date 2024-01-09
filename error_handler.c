#include"monty.h"
/**
 * error_arguments -Main entry
 * Description: If user doesnt give file or more than valid arguments
 * Return: void
 **/
void error_arguments(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * invalidInstruction_error -Main entry
 * Description: print message if le to open the filehas an invalid instruction
 * @op_code: instruction
 * @line_number: line
 * Return: void
 **/
void invalidInstruction_error(char *op_code, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_code);
	exit(EXIT_FAILURE);
}

/**
 * not_int_err -Main entry
 * Description: print message if parameter received is not integer
 * @line_number: line
 * Return: void
 **/
void not_int_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error -Main entry
 * Description: print message if cant malloc anymore
 * Return: void
 **/
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
