#include "monty.h"
/**
 * f_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pop(stack_t **head, unsigned int number)
{
    stack_t *h;

    (void)number;

    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    h = *head;
    *head = h->next;
    free(h);
}
