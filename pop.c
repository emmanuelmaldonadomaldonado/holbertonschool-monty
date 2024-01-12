// pop.c

#include "monty.h"
#include <stdio.h>

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */

void pop(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    *stack = temp->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}
