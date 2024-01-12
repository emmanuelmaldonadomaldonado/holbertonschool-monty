// pall.c

#include "monty.h"
#include <stdio.h>

void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;  // Not using line_number in this function

    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

