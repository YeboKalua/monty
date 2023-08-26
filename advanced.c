#include "monty.h"
/**
  * pstr - prints string
  * @stack: pointer to stack
  * @line_number: line where command is stored
  */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;

	(void) stack;
	(void) line_number;

	tmp1 = args->head;
	while (tmp1 != NULL)
		{
			if (tmp1->n <= 0 || tmp1->n > 127)
				break;
			printf("%c", tmp1->n);
			tmp1 = tmp1->next;
		}
	printf("\n");
}