#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack_t *stack = NULL, *temp;
    char *buffer = NULL;
    size_t size = 0;
    ssize_t read_line;
    unsigned int line_number = 0;

    const instruction_t instructions[] = {{"push", push}, {"pall", pall}, {"pint", pint}, {NULL, NULL}};

    while ((read_line = getline(&buffer, &size, file)) != -1) {
        line_number++;
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';

        char *opcode = strtok(buffer, " ");
        if (opcode && get_instruction(opcode, instructions))
            get_instruction(opcode, instructions)->f(&stack, line_number);
        else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free(buffer);
            fclose(file);
            while (stack) { temp = stack; stack = stack->next; free(temp); }
            return EXIT_FAILURE;
        }
        free(buffer), buffer = NULL, size = 0;
    }

    fclose(file);
    free(buffer);
    while (stack) { temp = stack; stack = stack->next; free(temp); }
    return EXIT_SUCCESS;
}
