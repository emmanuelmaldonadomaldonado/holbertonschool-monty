// main.c

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

    stack_t *stack = NULL; // Inicializar la pila

    char *buffer = NULL;
    size_t size = 0;
    ssize_t read_line;
    unsigned int line_number = 0;

    while ((read_line = getline(&buffer, &size, file)) != -1)
    {
        // Eliminar el salto de línea al final, si existe
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';

        //printf("Processing line: %s\n", buffer);

        // Parse y ejecuta la operación correspondiente
        char *opcode = strtok(buffer, " ");
        if (opcode != NULL)
        {
            const instruction_t *instruction = get_instruction(opcode);
            if (instruction)
            {
                instruction->f(&stack, line_number); // Corrected function call
            }
        }

        // Limpiar el buffer para la próxima línea
        free(buffer);
        buffer = NULL;
        size = 0;
        line_number++; // Increment line number for each line processed
    }

    fclose(file);
    free(buffer);
    // No necesitas liberar la pila aquí, ya que la función pall lo hará si es necesario

    return 0;
}
