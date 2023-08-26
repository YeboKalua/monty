#include "monty.h"
/**
  * sub - subtracts first two elements
  * @stack: stack to subtract from
  * @line_number: number of command
  */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;
	(void) stack;
	
	if (args->stack_length < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		total_free();
		exit(EXIT_FAILURE);
	}
	tmp1 = args->head;
	tmp2 = tmp1->next;
	tmp2->n = tmp2->n - tmp1->n;
	delete_node();
	args->stack_length -= 1;
}