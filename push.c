// push.c

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void push(stack_t **stack, unsigned int line_number)
{
    char *value_str = strtok(NULL, " \t\n");

    if (!value_str)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (!is_integer(value_str))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(value_str);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

int is_integer(const char *str)
{
    if (!str)
        return 0;

    char *endptr;
    strtol(str, &endptr, 10);

    return (*endptr == '\0');
}
