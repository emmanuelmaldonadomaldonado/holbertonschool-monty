#ifndef _MONTY_H_
#define _MONTY_H_

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* error_handler 1 */
void error_arguments(void);
void invalidInstruction_error(char *op_code, unsigned int line_number);
void not_int_err(unsigned int line_number);
void malloc_error(void);

/* error handler 2 */
void pint_error(unsigned int line_number);
void pop_error(unsigned int line_number);
void swap_error(unsigned int line_number);
void add_error(unsigned int line_number);

/*opcodes */
void get_op_code(char *token, unsigned int line_number, stack_t **head);

/* Stack */
void push_stack(stack_t **head, unsigned int line_number);
void pall_stack(stack_t **head, unsigned int line_number);
void free_stack(stack_t *head);
void pint_stack(stack_t **head, unsigned int line_number);
void pop_stack(stack_t **head, unsigned int line_number);

/* stack operations */
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
#endif
