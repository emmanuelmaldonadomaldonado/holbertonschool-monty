// monty.h

#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number, int value); // Cambiado el tipo del segundo parámetro
} instruction_t;

void push(stack_t **stack, unsigned int line_number, int value);
void pall(stack_t **stack, unsigned int line_number, int value);
void pint(stack_t **stack, unsigned int line_number, int value);
void pop(stack_t **stack, unsigned int line_number, int value); // Declare the pop function
void swap(stack_t **stack, unsigned int line_number, int value); // Declare the swap function
void add(stack_t **stack, unsigned int line_number, int value); // Declare the add function
const instruction_t *get_instruction(char *opcode);

#endif
