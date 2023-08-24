#ifndef MONTY_H
#define MONTY_H

/* C standard library */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * args_struct - structure for argument
 * @buffer: where file is copied at
 * @line: parsed line stored
 */
typedef struct args_struct
{
    file *buffer;
    char *line;
}args_t;
extern args_t *args;
#endif
