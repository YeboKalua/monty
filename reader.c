#include "monty.h"

/**
 * read_file - reads file into buffer
 * @file_name: name of the file to open
 * Return: void
 */
void read_file(char *file_name)
{
    int fd;
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        open_error(file_name);  
    args->buffer = fdopen(fd, "r");
    if (args->buffer == NULL)
    {
        close(fd);
        open_error(file_name);
    }
}

/**
 * initializer - initializes struct args_t
 * Return: void
 */
void initializer()
{
    args = malloc(sizeof(args_t));
    if (args == NULL)
        malloc_error();

    args->instruction = malloc(sizeof(instruction_t));
    if (args->instruction == NULL)
        malloc_error();
    
    args->buffer = NULL;
    args->line = NULL;
    args->n_tokens = 0;
    args->line_number = 0;
    args->head = NULL;
    args->stack_length = 0;
	args->stack = 1;
}