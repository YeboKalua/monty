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
