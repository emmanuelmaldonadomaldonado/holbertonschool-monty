#include "monty.h"
/**
 * f_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        cleanup(NULL, NULL, *stack);  // Pass appropriate arguments to cleanup
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}
