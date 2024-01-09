#include "monty.h"
global_var var_global;
/**
 * main - driver function for monty program
 * @ac: int num of arguments
 * @av: opcode file
 * Return: 0
 */
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

    /* Add more logic to read and interpret Monty bytecode file */
    
    fclose(file);
    return 0;
}
