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
/**
  * rotl - rotates stack
  * @stack: pointer to stack
  * @line_number: line where command is stored
  */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	(void) stack;
	(void) line_number;
	if (args->stack_length < 2)
		return;
	tmp1 = args->head;
	tmp2 = tmp1->next;
	args->head = tmp2;
	while (tmp2)
		{
			if (tmp2->next == NULL)
			{
				tmp2->next = tmp1;
				tmp1->next = NULL;
				tmp1->prev = tmp2;
				break;
			}
			tmp2 = tmp2->next;
		}
}
/**
  * rotr - rotates stack
  * @stack: pointer to stack
  * @line_number: line where command is stored
  */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *last;

	(void) stack;
	(void) line_number;
	if (args->stack_length < 2)
		return;
	tmp = args->head;
	while (tmp)
		{
			if (tmp->next == NULL)
			{
				last = tmp;
				break;
			}
			tmp = tmp->next;
		}
	last->prev->next = NULL;
	last->next = args->head;
	last->prev = NULL;
	args->head = last;
}