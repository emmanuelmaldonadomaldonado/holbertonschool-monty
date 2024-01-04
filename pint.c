#include "monty.h"
/**
 * f_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_pint(stack_t **head, unsigned int number)
{

	if (*head == NULL)

	{

		fprintf(stderr, "L%u: cant't pint, stack empty\n", number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);

		}

	printf("%d\n", (*head)->n);
					}
