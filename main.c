#include"monty.h"

/**
 * main - Main entry
 * Description: Monty bytecodes files interpreter
 * @argc: total of arguments
 * @argv: The arguments, monty files
 * Return: Always return 0
 */
int main(int argc, char **argv)
{
	char *token = NULL;
	unsigned int linenum = 0;
	size_t size = 0;
	stack_t *head = NULL;

	if (argc != 2)
		error_arguments();

	FILE *doc = fopen(argv[1], "r");

	if (doc == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&token, &size, doc) != -1)
	{
		linenum++;
		get_op_code(token, linenum, &head);
	}
	/* closing file */
	fclose(doc);

	/* Free separated memory */
	free(token);
	free_stack(head);

	return (0);
}
