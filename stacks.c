#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
    if (args->n_tokens <= 1 || !(number_check(args->tokens[1])))
    {
        free_args();
        dprintf(2, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    *stack = malloc(sizeof(stack_t));
    if (*stack == NULL)
        malloc_error();
    (*stack)->next = (*stack)->prev = NULL;
    (*stack)->n = (int) atoi(args->tokens[1]);
    if (args->head == NULL)
		args->head = *stack;
	else
	{
		if (args->stack)
		{
			(*stack)->next = args->head;
        	args->head->prev = *stack;
			args->head = *stack;
		}
		else
		{
			stack_t *tmp = args->head;

			while (tmp->next)
				tmp = tmp->next;
			tmp->next = *stack;
			(*stack)->prev = tmp;
		}
	}
    args->stack_length += 1;
}
/**
 * number_check - checks whether string is number
 * @str: string to check
 * Return: 0 on success
 */
int number_check(char *str)
{
    int i = 0;

    while (str[i])
        {
            if (i == 0 && str[i] == '-' && str[i + 1])
            {
                i++;
                continue;
            }
            if (str[i] < '0' || str[i] > '9')
                return (0);
            i++;
        }
    return (1);
}
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    if (args->head == NULL)
        return;
    (void) line_number;
    (void) stack;
    tmp = args->head;
    while (tmp != NULL)
        {
            printf("%d\n", tmp->n);
            tmp = tmp->next;
        }
}
/**
  * pint - prints top value of stack
  * @stack: pointer to stack
  * @line_number: number where pint called
  */
void pint(stack_t **stack, unsigned int line_number)
{
    (void) stack;
    if (args->head == NULL)
    {
        dprintf(2, "L%d: can't pint, stack empty\n", line_number);
        total_free();
        exit(EXIT_FAILURE);
    }
    printf("%d\n", args->head->n);
}