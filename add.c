// add.c

#include "monty.h"
#include <stdio.h>

void add(stack_t **stack, unsigned int line_number, int value)
{
    (void)value;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number, value);
}

