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
    free_head();
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
/**
 * free_head - frees head
 */
void free_head(void)
{
    if (args->head)
        free_stack(args->head);
    args->head = NULL;
}
/**
 * free_stack - frees node in stack
 * @head: first node
 */
void free_stack(stack_t *head)
{
    if (head == NULL)
        return;
    if (head->next != NULL)
    {
        free_stack(head->next);
    }
    free(head);
}
