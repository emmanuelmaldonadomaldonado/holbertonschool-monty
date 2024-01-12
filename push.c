// push.c

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, unsigned int line_number)
{
    // Ensure there is an argument following push
    if (!stack || !line_number)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Use atoi to convert the argument to an integer
    int value;
    if (scanf("%d", &value) != 1)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for a new node
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the new node
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    // Update the previous pointer of the existing top node, if any
    if (*stack)
    {
        (*stack)->prev = new_node;
    }

    // Update the stack pointer
    *stack = new_node;
}

