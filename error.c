#include "monty.h"
/**
 * open_error - handles open file errors
 * @file_name: name of the file to open
 * Return: void
 */

void open_error(char *file_name)
{
    dprintf(2, "Error: Can't open file %s\n", file_name);
    free_args();
    exit(EXIT_FAILURE);
}

/**
 * malloc_error - error handling when malloc fails
 * Return: void
 */
void malloc_error()
{
    dprintf(2, "Error: malloc failed\n");
    free_args();
    exit(EXIT_FAILURE);
}

/**
 * invalid_instruction - handles invalid input
 */
void invalid_instruction(void)
{
    dprintf(2, "L%d: unknown instruction %s\n", args->line_number, args->tokens[0]);
    close_files();
    free_tokens();
    free_args();
    exit(EXIT_FAILURE);
}

