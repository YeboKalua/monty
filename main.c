#include "monty.h"
args_t *args = NULL;
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: command line arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
    size_t n = 0;
    ssize_t command_line;
    
	if (argc != 2)
    {
        dprintf(2, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    initializer();
    read_file(argv[1]);
    while (getline(&args->line, &n, args->buffer) != -1)
        {
            
            args->line_number += 1;
            args->n_tokens = 0;
            tokenizer();
            /*for (int i = 0; i < args->n_tokens; i++)
    {
        printf("Token %d: %s\n", i + 1, args->tokens[i]);
    }
            get_command();
            printf("Ive managed to get the command");
            execute();
            printf("Ive executed");
            free_tokens();*/
        }
    close_files();
    free_args();
    return (0);
}
