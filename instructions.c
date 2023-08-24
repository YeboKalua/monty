#include "monty.h"
/**
 * get_command - gets opcode to implement
 */
void get_command(void)
{
    int i = 0;
    instruction_t instructions[] = {
    {"push", &push}, {"pall", &pall}/*,
    {"pint", &pint}, {"pop", &pop},
    {"swap", &swap}, {"add", &add},
    {"nop", &nop}, {"stack", &stack},
    {"queue", &queue}, {NULL, NULL}*/
    };
   if (args->n_tokens == 0)
       return;
    /*args->instruction = malloc(sizeof(instruction_t));
    if (args->instruction == NULL)
        malloc_error();*/
    for (; instructions[i].opcode != NULL; i++)
        {
             printf("Comparing: '%s' and '%s'\n", instructions[i].opcode, args->tokens[0]);
            if (strcmp(instructions[i].opcode, args->tokens[0]) == 0)
            {
                args->instruction->opcode = instructions[i].opcode;
                args->instruction->f = instructions[i].f;
                return;
            }
        }
    invalid_instruction();
}
/**
 * execute - implements instruction 
 */
void execute(void)
{
    stack_t *stack = NULL;

    if (args->n_tokens == 0)
        return;
    args->instruction->f(&stack, args->line_number);
}