#include "monty.h"
/**
 * free_args - frees arguments
 * Return: void
 */
void free_args()
{
    if (args == NULL)
        return;
    if (args->instruction)
    {
        free(args->instruction);
        args->instruction = NULL;
    }
    if (args->line)
    {
        free(args->line);
        args->line = NULL;
    }
    free(args);
}
/**
 * free_tokens - frees tokens
 * Return: void
 */
void free_tokens(void)
{
    int i = 0;

    if (args->tokens == NULL)
        return;
    while (args->tokens[i])
        {
            free(args->tokens[i]);
            i++;
        }
    free(args->tokens);
    args->tokens = NULL;
}
/**
 * close_files - closes files
 */
void close_files(void)
{
    if (args->buffer == NULL)
        return;
    fclose(args->buffer);
    args->buffer = NULL;
}