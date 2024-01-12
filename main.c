#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL; /* Initialize the stack */

    char *buffer = NULL;
    size_t size = 0;
    ssize_t read_line;
    unsigned int line_number = 0;

    while ((read_line = getline(&buffer, &size, file)) != -1)
    {
        line_number++;

        /* Remove the newline character at the end, if it exists */
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';

        /* Parse and execute the corresponding operation */
        char *opcode = strtok(buffer, " ");
        if (opcode != NULL)
        {
            const instruction_t *instruction = get_instruction(opcode);
            if (instruction)
            {
                instruction->f(&stack, line_number);
            }
            else
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }

        /* Clear the buffer for the next line */
        free(buffer);
        buffer = NULL;
        size = 0;
    }

    fclose(file);
    free(buffer);
    /* You don't need to free the stack here, as the pall function will do it if necessary */

    return 0;
}
