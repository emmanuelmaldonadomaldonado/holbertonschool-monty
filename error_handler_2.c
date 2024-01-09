#include"monty.h"
/**
 * pint_error - print error message if the stack is empty
 * @line_number: line
 * Return: void
 */
void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * pop_error - print error message if the stack is empty
 * @line_number: line
 * Return: void
 */
void pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * swap_error - print err msg if stack contains less than two elements
 * @line_number: line
 * Return: void
 */
void swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * add_error - Print error if the stack contains less than two elements
 * @line_number: line
 * Return: void
 */
void add_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
