#include "monty.h"
 
/**
 * tokenizer - creates tokens from line
 * Return: void
 */
void tokenizer(void)
{
    int i = 0;
    char *d = " \n";
    char *token = NULL;
    char *c_line = NULL;
    
    c_line = malloc(sizeof(char) * (strlen(args->line) + 1));
    strcpy(c_line, args->line);
    args->n_tokens = 0;
    token = strtok(c_line, d);
    while (token != NULL)
        {
            args->n_tokens += 1;
            token = strtok(NULL, d);
        }
    
    args->tokens = malloc(sizeof(char *) * (args->n_tokens + 1));
    strcpy(c_line, args->line);
    token = strtok(c_line, d);
    while (token)
        {
            args->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
            if (args->tokens[i] == NULL)
                malloc_error();
            strcpy(args->tokens[i], token);
            token = strtok(NULL, d);
            i++;
        }
    args->tokens[i] = NULL;
    free(c_line);
}