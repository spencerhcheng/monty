#include "monty.h"

/**
 * push - adds a node element to the stack/queue
 * @head: pointer to first node in a doubly linked stack_t list
 * @line: monty (.m) source file line with push instruction
 * @line_number: line number of operation
 * Return: 0 on success; -1 on fail
 */

int push(stack_t **head, char *line, unsigned int line_number)
{
	char *n;
	stack_t *new_node;

    /* find the first number in line if one exists */
	n = goto_number(line); /* <---- functions.c */
	if (n == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		free(line);
		return (-1);
	};

	new_node = add_node(head, atoi(n));
	free(line);
	if (new_node == NULL)
	{
		puts("Error: malloc failed");
		return (-1);
	}

	return (0);
}

/**
 * pop - removes top element from stack
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
		raise_op_error(line_number, "pop");

	temp = *head;
	if (temp->next == NULL)
		*head = NULL;
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(temp);
	}
}

/**
 * nop - does nothing
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
