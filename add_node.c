#include "monty.h"

/**
 * add_node - adds a node to the top of a doubly linked stack_t list
 * @head: double pointer to the first node in a doubly linked stack_t list
 * @n: int elemt to add to stack
 * Return: pointer to newly created node
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;

	*head = new;
return (new);
}
