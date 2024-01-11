#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "monty.h"

instruction_t *get_instructions(void);
void cleanup_resources(FILE *file, char *line, stack_t **stack);

#endif
