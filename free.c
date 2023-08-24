#include "monty.h"
/**
 * free_args - frees arguments
 * Return: void
 */
void free_args()
{
    if (args != NULL)
    {
        free(args->line);
        free(args->buffer);
    }
}