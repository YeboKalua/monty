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
    command_line = getline(&args->line, &n, args->buffer);
    if (command_line == -1)
    {
        dprintf(2, "End of File\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("%s", args->line);
    }
    return (0);
}
