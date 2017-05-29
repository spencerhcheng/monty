#include "monty.h"

/**
 * execute - calls a function based on op code
 * @cache: holds file stream
 * @head: double pointer to first node in a doubly linked stack_t list
 * @line_num: Monty source file
 * @line: line buffer with op_code
 * Return: 0 on success; -1 on fail
 */

int execute(cache_t *cache, stack_t **head, char *line, unsigned int line_num)
{

	instruction_t operations[] = {
		{"pall", pall},   {"pint", pint},
		{"pchar", pchar}, {"pstr", pstr},
		{"pop", pop},     {"nop", nop},
		{"add", add},     {"sub", sub},
		{"div", divide},  {"mul", mul},   {"mod", mod},
		{"rotl", rotl},   {"rotr", rotr}, {"swap", swap},
		{"stack", stack}, {"queue", queue},
		{NULL, NULL}
	};
	int i, push_return;
	char *clean_line;

	/* remove extraneous whitespace from line */
	clean_line = remove_leading_whitespace(line); /* <---helpers.c */
	if (clean_line == NULL)
	{
		free(line);
		return (0);
	}

	/* check to see if line begins with "push" */
	if (_strncmp(clean_line, "push", _strlen("push")) == 0)
	{
		/* attempt to add the line to the stack/queue */
		push_return = push(head, line, line_num); /* <---- push_and_pop.c */
		if (push_return == 0)
			return (0);
		else
			return (-1); /* return fail to main */
	}
	/* check for clean_line in the operations[] array above */
	for (i = 0; operations[i].opcode; ++i)
	{
		if (_strncmp(clean_line, operations[i].opcode,
			_strlen(operations[i].opcode)) == 0)
		{
			free(line);
			(operations[i].f)(head, line_num);
			return (0);
		}
	}
	fclose(cache->file);
	printf("L%d: unknown instruction ", line_num);
	while (*clean_line && (*clean_line != ' ' && *clean_line != '\t'))
	{
		putchar(*clean_line++);
	}

	free(line);
	exit(EXIT_FAILURE);

return (-1);
}
