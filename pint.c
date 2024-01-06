// pint.c

#include "monty.h"
#include <stdio.h>

void pint(stack_t **stack, unsigned int line_number, int value)
{
    (void)value;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

