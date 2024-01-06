// main.c

/*#include "monty.h"
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

    while ((read_line = getline(&buffer, &size, file)) != -1)
    {
	if (read_line <= 1 || buffer[0] == '#')
	{
	printf("Skipping line: %s", buffer);
        continue;
	}

	printf("Processing line: %s", buffer);
        // Parse y ejecuta la operación correspondiente
        const instruction_t *instruction = get_instruction(buffer);

        if (instruction)
        {
            if (strcmp(instruction->opcode, "push") == 0)
            {
                // Extrae el valor numérico de la instrucción push y pasa ese valor a la función
                int value = atoi(buffer + strlen("push"));
                instruction->f(&stack, value, 0);
            }
            else
            {
                // Ejecuta la función sin preocuparte del valor numérico para las demás instrucciones
                instruction->f(&stack, 0, 0); // 0 es solo un ejemplo, podrías necesitar el número de línea real
            }
        }

        // Limpiar el buffer para la próxima línea
        free(buffer);
        buffer = NULL;
        size = 0;
    }

    fclose(file);
    free(buffer);
    // No necesitas liberar la pila aquí, ya que la función pall lo hará si es necesario

    return 0;
}*/

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
                if (strcmp(instruction->opcode, "push") == 0)
                {
                    // Extrae el valor numérico de la instrucción push y pasa ese valor a la función
                    char *value_str = strtok(NULL, " ");
                    if (value_str != NULL)
                    {
                        int value = atoi(value_str);
                        instruction->f(&stack, 0, value);
                    }
                    else
                    {
                        fprintf(stderr, "L%d: usage: push integer\n", line_number);
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    // Ejecuta la función sin preocuparte del valor numérico para las demás instrucciones
                    instruction->f(&stack, 0, 0); // 0 es solo un ejemplo, podrías necesitar el número de línea real
                }
            }
        }

        // Limpiar el buffer para la próxima línea
        free(buffer);
        buffer = NULL;
        size = 0;
    }

    fclose(file);
    free(buffer);
    // No necesitas liberar la pila aquí, ya que la función pall lo hará si es necesario

    return 0;
}

