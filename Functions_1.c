#include "monty.h"

/**
 * push_stack -push (add) node to list.
 * Description: Function that push a new node at the beginning of stack_t stack
 * @head: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void push_stack(stack_t **head, unsigned int line_number)
{
	/* obtain int arg */
	int val;
	char *arg = strtok(NULL, " \n");

	if (arg == NULL)
		not_int_err(line_number);

	/* arg to int */
	if (sscanf(arg, "%d", &val) != 1)
		not_int_err(line_number);

	/* new node */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		malloc_error();

	new_node->n = val;
	new_node->prev = NULL;

	/* add node to stack */
	if (*head != NULL)
		(*head)->prev = new_node;
	new_node->next = *head;
	*head = new_node;
}
/**
 * pall_stack -print.
 * Description: Function that print the elements of a stack
 * @head: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void pall_stack(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * free_stack -free list.
 * Description: Function that frees a dlist_t list
 * @head: top of the stack. (head)
 * Return: void
 **/
void free_stack(stack_t *head)
{
	stack_t *temp = head;

	while (temp != NULL)
	{
		stack_t *next = temp->next;

		free(temp);
		temp = next;
	}
}
/**
 * pint_stack -print.
 * Description: Function that print the valueat top of stack
 * @head: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void pint_stack(stack_t **head, unsigned int line_number)
{

	if (*head == NULL)
		pint_error(line_number);

	printf("%d\n", (*head)->n);
}
/**
 * pop_stack -print.
 * Description: Function that pop (delete) the value at top of stack
 * @head: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void pop_stack(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (*head == NULL)
		pop_error(line_number);

	*head = (*head)->next;

	if (*head != NULL)
		(*head)->prev = NULL;
	free(tmp);
}
