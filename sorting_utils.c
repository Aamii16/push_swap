#include "push_swap.h"

int	cost(t_stack **stack, int index)
{
	int	size;

	size = stack_size(stack);
	if (index > (size / 2))
		return (size - index);
	else
		return (index);
}

int	get_max(t_stack **to)
{
	t_stack	*curr;
	int		index;
	int		max;
	int		i;

	curr = *to;
	max = curr->data;
	i = 0;
	index = 0;
	while (curr)
	{
		if (curr->data > max)
		{
			max = curr->data;
			index = i;
		}
		i++;
		curr = curr->next;
	}
	return (index);
}

int	get_min(t_stack **to)
{
	t_stack	*curr;
	int		index;
	int		min;
	int		i;

	if (!to || !*to)
		return (-1);
	curr = *to;
	min = curr->data;
	i = 0;
	index = 0;
	while (curr)
	{
		if (curr->data < min)
		{
			min = curr->data;
			index = i;
		}
		i++;
		curr = curr->next;	
	}
	return (index);
}

void	sort_three(t_stack **a)
{
	int first;
	int second;
	int third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;	
	if (first > second && first > third && second > third)
	{
		ra(a);
		swap(*a, (*a)->next);
		write(1, "sa\n", 3);
	}
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first < second && first > third)
		rra(a);
	else if (first > second && first < third)
	{
		swap(*a, (*a)->next);
		write(1, "sa\n", 3);
	}
	else if (first < second && first < third && second > third)
	{
		rra(a);
		swap(*a, (*a)->next);
		write(1, "sa\n", 3);
	}
}
