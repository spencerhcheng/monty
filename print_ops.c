#include "monty.h"

/**
 * pall - prints stack
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;
	if (*head == NULL || head == NULL)
		return;

	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	free(temp);
}

/**
 * pint - prints val at top of stack follow by new line
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void pint(stack_t **head, unsigned int line_number)
{

	if (!head || !*head)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		free_stack(*head);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * pchar - converts to char and prints the element at
 *         the top of the stack followed by new line
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void pchar(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}

/**
 * pstr -converts all elements to char and prints
 *       them on one line followed by a new line
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void pstr(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
