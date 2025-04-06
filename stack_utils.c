
#include "push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*stack;
	
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	return (stack);
}

void	add_node(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;	
	while (tmp)
	{
		if (!tmp->next)
		{
			tmp->next = node;
			break ;
		}
		tmp = tmp->next;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack *pre;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		pre = curr;
		curr = curr->next;
		free (pre);	
	}
	*stack = NULL;
}

int	stack_size(t_stack	**stack)
{
	t_stack	*tmp;
	int		size;

	if (!stack || !*stack)
		return (0);
	size = 0;
	tmp = *stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;	
	}
	return (size);
}