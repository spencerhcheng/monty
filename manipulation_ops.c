#include "monty.h"

/**
 * rotl - moves first element from stack (top) to queue (end)
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void rotl(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}

/**
 * rotr - reverses the doubly linked stack_t list
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void rotr(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}

/**
 * swap - swaps the top two elemnts of the stack
 * @head: pointer to first node in doubly linked stack_t list
 * @line_number: number of line in source Monty (.m) file
 * Return: void
 */

void swap(stack_t **head, unsigned int line_number)
{
	int temp_n;

	if (count_nodes(head) < 2)
		raise_op_error(line_number, "swap");

	temp_n = (*head)->next->n;
	(*head)->next->n = (*head)->n;
	(*head)->n = temp_n;
}
