#include "monty.h"

/**
 * add - Function that adds the top two elements of the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the monty file.
 */

void add(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: cant't add, stack too short\n", line_number);
        cleanup(NULL, NULL, *stack);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}
