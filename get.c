#include "monty.h"
#include <string.h>

/* Define the opcodes array here */
const instruction_t opcodes[] = {
    {"push", push},
    /* Add other instructions here */
    {NULL, NULL} /* This is the end-of-array marker */
};

const instruction_t *get_instruction(char *opcode)
{
    int i;

    if (!opcode)
        return NULL;

    for (i = 0; opcodes[i].opcode; i++)
    {
        if (strcmp(opcodes[i].opcode, opcode) == 0)
            return &opcodes[i];
    }

    return NULL;
}

