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
	cache_t *cache;

	if (argc != 2)
		raise_input_error();
	cache = malloc(sizeof(cache_t));
	head = NULL;
	cache->file = fopen(argv[1], "r");
	if (cache->file == NULL)
	{
		free(cache);
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
