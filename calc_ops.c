#include "monty.h"

/**
 * add - replaces top two elements with their sum
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void add(stack_t **head, unsigned int line_number)
{
	int sum;

	if (count_nodes(head) < 2)
	{
		/* raise_op_error(head, line_number, "add"); */
		printf("L%d: can't add, stack too short\n", line_number);
		/* fclose(file); */
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	sum = (*head)->n + (*head)->next->n;
	pop(head, line_number);
	(*head)->n = sum;
}

/**
 * sub - substracts the top two elements of the stack
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void sub(stack_t **head, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (count_nodes(head) < 2)
	{
		raise_op_error(head, line_number, "sub");
		/* printf("L%d: can't add, stack too short", line_number); */
		/* free_stack(*head); */
		/* exit(EXIT_FAILURE); */
	}

	temp = *head;
	result = (temp)->next->n - (temp)->n;
	pop(head, line_number);
	(*head)->n = result;
}

/**
 * divide - divides the second element of the stack by the top element
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void divide(stack_t **head, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (count_nodes(head) < 2)
		raise_op_error(head, line_number, "div");

	temp = *head;
	result = (temp)->next->n / (temp)->n;
	pop(head, line_number);
	(*head)->n = result;
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void mul(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}

/**
 * mod - computes the modulo of the stacks second top element with top element
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void mod(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
