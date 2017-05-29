#include "monty.h"

/**
 * main - entry point for Monty file interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: always return 0
 */
int main(int argc, char **argv)
{
	stack_t *head;
	unsigned int line_number;
	ssize_t chars_read;
	char *line;
	size_t length;
	FILE *file;

	/* check only one arg passed (other than ./monty */
	if (argc != 2)
	{
		printf("Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	head = NULL;

	/* open the file provided as argument */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 0;

	/* call execute() on each  line */
	do {
		++line_number;
		line = NULL;
		length = 0;
		chars_read = getline(&line, &length, file);
	if (chars_read > 0)
		execute(&head, line, line_number);  /* execute.c */
	else
		free(line);
	} while (chars_read >= 0);

	fclose(file);
	free_stack(head);
	return (0);
}
