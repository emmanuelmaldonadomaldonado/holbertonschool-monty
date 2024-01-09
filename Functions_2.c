#include "monty.h"
/**
 *  * _swap -main entry.
 *   * Description: Function that swaps the top 2 elements of stack
 *    * @head: element at the top of the stack (head)
 *     * @line_number: constant int value in the structure
 *      * Return: void
 *       **/
void _swap(stack_t **head, unsigned int line_number)
{
	int num;

	if (*head == NULL || (*head)->next == NULL)
		swap_error(line_number);

	num = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = num;
}
/**
 *  *_add -main entry.
 *   * Description: Function that adds the top two elements of the stack
 *    * @head: element at the top of the stack (head)
 *     * @line_number: constant int value in the structure
 *      * Return: void
 *       **/
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (*head == NULL || (*head)->next == NULL)
		add_error(line_number);

	(*head)->next->n += (*head)->n;
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(tmp);
}
/**
 *  * _nop -main entry.
 *   * Description: Doesnt do anything
 *    * @head: element at the top of the stack (head)
 *     * @line_number: constant int value in the structure
 *      * Return: void
 *       **/
void _nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
