// swap.c

#include "monty.h"
#include <stdio.h>

void swap(stack_t **stack, unsigned int line_number, int value)
{
    (void)value;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *first = *stack;
    stack_t *second = first->next;

    first->next = second->next;
    first->prev = second;
    second->next = first;
    second->prev = NULL;

    if (first->next != NULL)
        first->next->prev = first;

    *stack = second;
}

