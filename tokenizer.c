#include "monty.h"
/**
 * token_count - gets number of tokens
 * @line: line to count words from
 * Return: number of words read
 */
int token_count(char *line)
{
    bool inWord = false;
    int count;
    while (*line != '\n')
        {
            if (isspace(*line))
            {
                inWord = false;
            }
            else
            {
                if (!inWord)
                {
                    count++;
                    inWord = true;
                }
            }
            line++;
        }
    return (count);
}
 
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
    
    c_line = strdup(args->line);
    args->n_tokens = token_count(c_line);
    
    args->tokens = malloc(sizeof(char *) * (args->n_tokens + 1));
    token = strtok(c_line, d);
    while (token)
        {
            args->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
            if (args->tokens[i] == NULL)
                malloc_error();
            strcpy(args->tokens[i], token);
            printf("Token %d: %s\n", i + 1, args->tokens[i]);
            token = strtok(NULL, d);
            i++;
        }
    args->tokens[i] = NULL;
    printf("Number of tokens stored: %d\n", i);
    free(c_line);
}