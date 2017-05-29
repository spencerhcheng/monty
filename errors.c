#include "monty.h"

/**
 * raise_op_error - prints an error for inadequate number of nodes in
 * doubly linked stack_t list
 * @line_number: Monty file line number with invalid operation
 * @operation: name of operation function
 * Return: void
 */

void raise_op_error(unsigned int line_number, char *operation)
{
	char *swap_error = "L%d: can't swap, stack too short\n";
	char *add_error = "L%d: can't add, stack too short";
	char *sub_error = ":%d: can't sub, stack too short";
	char *div_error = ":%d: can't div, stack too short";

	if (_strcmp(operation, "pint") == 0)
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);

	if (_strcmp(operation, "pop") == 0)
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);

	if (_strcmp(operation, "swap") == 0)
		dprintf(STDERR_FILENO, swap_error, line_number);

	if (_strcmp(operation, "add") == 0)
		dprintf(STDERR_FILENO, add_error, line_number);

	if (_strcmp(operation, "sub") == 0)
		dprintf(STDERR_FILENO, sub_error, line_number);

	if (_strcmp(operation, "div") == 0)
		dprintf(STDERR_FILENO, div_error, line_number);

	if (_strcmp(operation, "div_zero") == 0)
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);

	exit(EXIT_FAILURE);
}

/**
 * raise_input_error - prints error if argc is not 2
 * Return: void
 */

void raise_input_error(void)
{
	printf(STDERR_FILENO, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * raise_file_error - prints error if file can't be opened
 * @file_name: name of invalid file
 * Return: void
 */

void raise_file_error(char *file_name)
{
	printf(STDERR_FILENO, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}
/**
 * raise_push_error - prints error if file can't be opened
 * @line_number: Monty file line number with invalid operation
 * Return: void
 */

void raise_push_error(int line_number)
{
	printf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
