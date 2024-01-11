#include <stdlib.h>
#include "instructions.h"

/**
 * get_instructions - Get the array of instructions
 *
 * Return: Pointer to the array of instructions
 */
instruction_t *get_instructions(void)
{
    instruction_t *my_instructions = malloc(sizeof(instruction_t) * 8);

    if (my_instructions == NULL)
    {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }

    // Initialize the array
    my_instructions[0] = (instruction_t){"push", push};
    my_instructions[1] = (instruction_t){"pall", pall};
    my_instructions[2] = (instruction_t){"pint", pint};
    my_instructions[3] = (instruction_t){"pop", pop};
    my_instructions[4] = (instruction_t){"nop", nop};
    my_instructions[5] = (instruction_t){"swap", swap};
    my_instructions[6] = (instruction_t){"add", add};
    my_instructions[7] = (instruction_t){NULL, NULL};

    return my_instructions;
}

/**
 * free_instructions - Free the allocated memory for instructions
 * @instructions: Pointer to the array of instructions
 */
void free_instructions(instruction_t *instructions)
{
    free(instructions);
}

