#include "monty.h"

/**
 * remove_leading_whitespace - removes leading whitespace
 * @line: character array to remove leading whitespace from
 * Return: new string
 */

char *remove_leading_whitespace(char *line)
{
	if (line == NULL)
		return (NULL);

	while (*line && (*line == ' ' || *line == '\t' || *line == '\v'))
		++line;

	if (*line == '\0' || *line == '\n')
		return (NULL);

return (line);
}

/**
* goto_number - moves pointer to first number after opcode
* @line: line to parse number from
* Return: pointer to index of first number after opcode in line
*/
char *goto_number(char *line)
{
	char *c;
	int res = 0;
	int i = 0;
	int neg = 1;

	if (line == NULL)
		return (NULL);

	while (*line && (*line < '0' || *line > '9'))
	{
		if (*line == '-')
		neg = -1;
		i++;
		++line;
	}
	if (*line == '\0')
		return (NULL);
	c = line;
	while (*c && *c >= '0' && *c <= '9')
		c++;

	if (!(*c == '\0' || *c == '\n' || *c == ' ' || *c == '\t'))
		return (NULL);

	res = _atoi(line) * neg;
	if (res < 0)
	{
		line[i - 1] = '-';
		return (line - 1);
	}
return (line);
}

/**
* count_nodes - counts the number of nodes in a doubly linked stack_t list
* @head: double pointer to the first node in a doubly linked stack_list
* Return: node count
*/

int count_nodes(stack_t **head)
{
	stack_t *temp;
	int count = 0;

	if (*head == NULL)
		return (0);

	temp = *head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
return (count);
}

/**
* free_stack - frees a doubly linked stack_t list
* @head: double pointer to first node in a doubly linked stack_t list
* Return: void
*/

void free_stack(stack_t *head)
{
	stack_t *temp_node;

	while (head != NULL)
	{
		temp_node = head;
		head = head->next;
		free(temp_node);
	}

}

/**
 * clean_exit - closes open file stream and frees doubly linked stack_t list
 * @file: file stream to close
 * @head: stack to free
 * Return: void;
 */

void clean_exit(stack_t *head)
{
	free_stack(head);
	fclose(file);
	exit(EXIT_FAILURE);
}
