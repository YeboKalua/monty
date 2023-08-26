#include "monty.h"
/**
  * pop - removes top element of stack
  * @stack - stack to remove from
  * @line_number - number where code is located
  */
void pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (args->head == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
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
/**
  * swap - swaps two elements of stack
  * @stack: stack to swap from
  * @line_number: where command is located
  * Return: void
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	(void) stack;
	if (args->stack_length < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		total_free();
		exit(EXIT_FAILURE);
	}
	tmp1 = args->head;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	if (tmp1->next)
		tmp1->next->prev = tmp1;
	tmp2->next = tmp1;
	tmp1->prev = tmp2;
	tmp2->prev = NULL;
	args->head = tmp2;
}
/**
  * add - adds the top elements of stack
  * @stack: stack to add from
  * @line_number: line where command is
  */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	(void) stack;
	if (args->stack_length < 2)
	{
		dprintf(2, " L%d: can't add, stack too short\n", line_number);
		total_free();
		exit(EXIT_FAILURE);
	}
	tmp1 = args->head;
	tmp2 = tmp1->next;
	tmp2->n = tmp1->n + tmp2->n;
	delete_node();
	args->stack_length -= 1;
}
/**
  * nop - does nothing
  * @stack: stack to do nothing from
  * line_number: line number to read from
  */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	total_free();
}