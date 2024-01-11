#include "instructions.h"

/**
 * cleanup_resources - Clean up resources
 * @file: File pointer to close
 * @line: Line buffer to free
 * @stack: Pointer to the stack to free
 */
void cleanup_resources(FILE *file, char *line, stack_t **stack)
{
    if (file != NULL)
        fclose(file);

    if (line != NULL)
        free(line);

    if (stack != NULL)
        free_stack(stack);
}

