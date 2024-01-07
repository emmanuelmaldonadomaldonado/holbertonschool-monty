#include "monty.h"

/**
 * cleanup - Function that frees memory before exit.
 *
 * @file: file to be closed.
 * @line: line to be freed.
 * @stack: stack to be freed with free_stack.
 */

void cleanup(FILE *file, char *line, stack_t *stack)
{
    if (file != NULL)
        fclose(file);
    if (line != NULL)
        free(line);
    free_stack(&stack);
}
