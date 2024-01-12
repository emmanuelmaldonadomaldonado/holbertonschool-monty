#include "monty.h"

int stack_mode = STACK_MODE;

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 */

void stack(stack_t **stack, unsigned int line_number)
{
	if (stack_mode == QUEUE_MODE)
		stack_mode = STACK_MODE;

	(void)stack;
	(void)line_number;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	if (stack_mode == STACK_MODE)
		stack_mode = QUEUE_MODE;

	(void)stack;
	(void)line_number;
}
#include "monty.h"

void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
}
