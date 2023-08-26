#include "monty.h"
/**
 * total_free - frees all data
 */
void total_free(void)
{
    close_files();
    free_tokens();
    free_args();
}