#include "monty.h"
/**
  * pop - removes top element of stack
  * @stack - stack to remove from
  * @line_number - number where code is located
  */
void pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	if (args->head == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack", line_number);
		total_free();
		exit(EXIT_FAILURE);
	}
	delete_node();
	args->stack_length -= 1;
}
/**
  * delete_node - deletes node
  */
void delete_node(void)
{
	stack_t *tmp;

	tmp = args->head;
	args->head = tmp->next;
	free(tmp);
}