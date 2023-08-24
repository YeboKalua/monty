#ifndef MONTY_H
#define MONTY_H

/* C standard library */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/* Function prototypes */
void initializer();
void read_file(char *file_name);
void open_error(char *file_name);
void malloc_error();

/**
 * args_struct - structure for argument
 * @buffer: where file is copied at
 * @line: parsed line stored
 */
typedef struct args_struct
{
    FILE *buffer;
    char *line;
}args_t;
extern args_t *args;
#endif
