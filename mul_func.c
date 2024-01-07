#include "monty.h"

/**
 * mul_func - Function that multiplies the second top
 * element if the stack with the top element of the stack.
 *
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the monty file.
 */

void mul_func(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        cleanup(NULL, NULL, *stack);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}
