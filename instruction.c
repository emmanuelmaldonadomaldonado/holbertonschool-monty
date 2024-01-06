// instruction.c

#include "monty.h"
#include <string.h>

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    /* Agrega aquí otras instrucciones según sea necesario */
    {NULL, NULL} // Marcar el final del array
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
    return NULL; // Instrucción no encontrada
}
