// instruction.c

#include "monty.h"
#include <string.h>

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {NULL, NULL} // Mark the end of the array
};

const instruction_t *get_instruction(char *opcode)
{
    for (int i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(instructions[i].opcode, opcode) == 0)
        {
            return &instructions[i];
        }
    }
    return NULL; // Instruction not found
}
