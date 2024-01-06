// pall.c

#include "monty.h"
#include <stdio.h>

void pall(stack_t **stack, unsigned int line_number, int value)
{
    stack_t *current = *stack;

    (void)value;  // Evitar el warning de variable no utilizada
    (void)line_number;
    (void)stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
