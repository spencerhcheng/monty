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
	int exec_return = -1; /* TEST: was 0 */
	/* FILE *file; */
	cache_t *cache;

	cache = malloc(sizeof(cache_t));

	/* check only one arg passed (other than ./monty */
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	head = NULL;

	/* open the file provided as argument */
	cache->file = fopen(argv[1], "r");
	/* file = fopen(argv[1], "r"); */
	if (cache->file == NULL)
	{
		raise_file_error(argv[1]);
	}
	line_number = 0;
	/* call execute() on each  line */
	do {
		++line_number;
		line = NULL;
		length = 0;
		chars_read = getline(&line, &length, cache->file);
		if (chars_read > 0)
		{

			exec_return = execute(cache, &head, line, line_number);
			if (exec_return != 0)
				clean_exit(cache, head);
		}
	} while (chars_read >= 0);

	free(line);
	fclose(cache->file);
	free(cache);
	
	free_stack(head);

	return (0);
}
