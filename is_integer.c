// is_integer.c

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int is_integer(const char *str)
{
    if (!str)
        return 0;

    char *endptr;
    strtol(str, &endptr, 10);

    return (*endptr == '\0');
}
