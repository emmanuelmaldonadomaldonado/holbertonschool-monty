#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

/* Function prototypes */
int is_integer(const char *str);
stack_t *push_stack(stack_t **stack, int n);

/**
 * push - Pushes an element to the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");

    if (arg == NULL || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    char *endptr;
    errno = 0;
    long value = strtol(arg, &endptr, 10);

    if (*endptr != '\0' || errno != 0 || (value > INT_MAX || value < INT_MIN))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = push_stack(stack, (int)value);

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * is_integer - Checks if a string represents a valid integer.
 * @str: The string to be checked.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_integer(const char *str)
{
    if (!str)
        return 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)str[i]) && (i == 0 && str[i] != '-' && str[i] != '+'))
            return 0;
    }

    return 1;
}

/**
 * push_stack - Pushes a new element to the stack.
 * @stack: A pointer to the top of the stack.
 * @n: The value to be pushed onto the stack.
 *
 * Return: A pointer to the newly created element.
 */
stack_t *push_stack(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
        return NULL;

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;

    return new_node;
}
