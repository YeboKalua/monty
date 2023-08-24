#ifndef MONTY_H
#define MONTY_H

/* C standard library */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/* Function prototypes */
void initializer();
void read_file(char *file_name);
void open_error(char *file_name);
void malloc_error();
void free_args();

/**
 * struct args_struct - structure for argument
 * @buffer: where file is copied at
 * @line: parsed line stored
 * @line_number: tracks line numbers in files
 * @tokens: stores words from line
 * @n_tokens: number of tokens
 * @command: available command
 */
typedef struct args_struct
{
    FILE *buffer;
    char *line;
    char **tokens;
    int n_tokens;
    unsigned int line_number;
    instruction_t *command;
}args_t;
extern args_t *args;

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

#endif
