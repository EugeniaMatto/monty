#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stddef.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct global_s - global
 * @n: integer.
 * @fd: file descriptor
 * @buffer: buffer
 * @mode: mode
 */
typedef struct global_s
{
	int n;
	FILE *fd;
	char *buffer;
	char mode;
} global_t;
extern global_t gl;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

FILE *read_textfile(char *filename);
void next_word(char *word);
int belongs(char *aux);
int isEmpty(char *buffer);
int execute(char *aux, stack_t **stack, unsigned int line);
stack_t *add_dnodeint_end(stack_t **head, int n);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void add_nodo(stack_t **stack, int a);
void erroargv(void);
void errounk(unsigned int line, char *aux);
void get_command(char *buffer, int line, stack_t **a, FILE *fd);
void free_list(stack_t *head);


#endif
