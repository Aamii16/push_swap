#include "push_swap.h"


void	push(t_stack **from, t_stack **to)
{
	t_stack		*tmp_from;

	if (!from || !*from)
		return ;
	tmp_from = *from;
	if (!*to)
	{
		*to = *from;
		printf("dddddddd  %d\n", (tmp_from)->data);
		printf("dddddddd  %d\n", (*to)->data);
		*from = (*from)->next;
		(*to)->next = NULL;
		return ;
	}
	(*from) = (*from)->next;
	tmp_from->next = *to;
	*to = tmp_from;
}

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	if (!stack)
		return;
	tmp = *stack;
	head = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	(*stack) = (*stack)->next;
	head->next = NULL;
}

void reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*tmp;
	t_stack	*head;

	if (!stack || !*stack || !(*stack)->next)
		return;
	head = *stack;
	tmp = *stack;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack;
	*stack = tmp;	
}
