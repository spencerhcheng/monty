#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LINE_LENGTH 32

/**
 * cache - line buffer and file stream
 *
 *
 */
typedef struct cache_s
{
	FILE *file;
	char *line;
} cache_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcoode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* functions.c */
char *remove_leading_whitespace(char *line);
char *goto_number(char *line);
int count_nodes(stack_t **head);
void free_stack(stack_t *head);
void clean_exit(cache_t *cache, stack_t *head);
/* char *remove_whitespace(char *line); */ /* dont think we need */

/* string_functions.c */
int _strlen(char *str);
int _strncmp(char *str1, char *str2, int n);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);

/* push_pop_ops.c */
int push(stack_t **head, char *line, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);

/* errors.c */
void raise_input_error(void);
void raise_file_error(char *file_name);
void raise_push_error(int line_number);
void raise_op_error(stack_t **head, unsigned int line_number, char *operation);

/* execute.c */
int execute(cache_t *cache, stack_t **head, char *line, unsigned int line_num);

/* manipulation_ops.c*/
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);

/* calc_ops.c */
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void divide(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);

/* print_ops */
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);

/* stack_queue */
void stack(stack_t **head, unsigned int line_number);
void queue(stack_t **head, unsigned int line_number);

/* add_node.c */
stack_t *add_node(stack_t **head, const int n);

#endif
